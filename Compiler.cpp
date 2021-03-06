
#include <iostream>
#include <iomanip>
#include <memory>
#include <memory.h>
#include "Compiler.h"
#include "Parser.hh"

Compiler::Compiler() : m_BreakIndex( -1 ), m_ErrorCount( 0 )
{
}

Compiler::~Compiler()
{
}

bool Compiler::Compile( const std::string& f, VM::Data& data )
{
	// System call
	AddFunction( VM::SYS_PRINT, TYPE_VOID, "print", "s" );
	AddFunction( VM::SYS_TOSTR, TYPE_STRING, "str", "i" );
	AddFunction( VM::SYS_DUMP, TYPE_VOID, "dump", "" );

	// Global variables.
	m_Variables.push_back( ValueTable() );
	m_Variables[ 0 ].SetGlobal();

	// HALT operation is first operation.
	OpHalt();

	m_File = f;
	ScanBegin();						// Initialize scanner.
	yy::Parser parser( *this );			// Build parser.
	int result = parser.parse();		// Analyze grammer.
	ScanEnd();							// End scanner.

	if( result != 0 ){
		return false;
	}

	int codeSize = LabelSetting();		// Set address to label.
	CreateData( data, codeSize );		// Create binary.

	return m_ErrorCount == 0;
}

void Compiler::error( const yy::location& location, const std::string& m )
{
	std::cerr << location << ": " << m << std::endl;
	++m_ErrorCount;
}

void Compiler::error( const std::string& m )
{
	std::cerr << m << std::endl;
	++m_ErrorCount;
}

bool Compiler::AddFunction( int index, int type, const char* pName, const char* pArgs )
{
	FunctionTag func( type );
	// Set argument
	if( !func.SetArgs( pArgs ) ){
		return false;
	}
	func.SetDeclaration();		// Set declared flag.
	func.SetSystem();			// System call flag.
	func.SetIndex( index );		// Set system call number.
	if( m_Functions.Add( pName, func ) == 0 ){
		return false;
	}
	return true;
}

struct DefValue
{
	Compiler*		m_pCompiler;
	int				m_Type;
	DefValue( Compiler* pCompiler, int type ) :	m_pCompiler( pCompiler ),
												m_Type( type )
	{
	}
	void operator()( ValueNode* pNode ) const
	{
		m_pCompiler->AddValue( pNode->GetLocation(), m_Type, pNode->GetString(), pNode->GetLeft() );
	}
};

void Compiler::DefineValue( const yy::location& location, int type, ValueList* pValueList )
{
	std::auto_ptr < ValueList > valueList( pValueList );
	pValueList->ForEach( DefValue( this, type ) );
}

void Compiler::DefineFunction( const yy::location& location, int type, const std::string* pName, ArgList* pArgs )
{
	std::auto_ptr < const std::string > name( pName );
	std::auto_ptr < ArgList > args( pArgs );

	const FunctionTag* pTag = m_Functions.Find( *pName );
	if( pTag ){
		if( !pTag->CheckArgList( pArgs ) ){
			error( location, "Function " + *pName + " has different type of argument." );
			return;
		}
	}
	else{
		FunctionTag func( type );
		func.SetArgs( pArgs );			// Set arguments.
		func.SetDeclaration();			// Set declared flag.
		func.SetIndex( MakeLabel() );	// Set label.
		if( m_Functions.Add( *pName, func ) == 0 ){
			error( location, "Internal Error : Failed to register to function table." );
		}
	}
}

struct AddVal
{
	Compiler*		m_pCompiler;
	ValueTable&		m_ValueTable;
	mutable int		m_Addr;
	AddVal( Compiler* pCompiler, ValueTable& values ) :	m_pCompiler( pCompiler ),
															m_ValueTable( values ),
															m_Addr( -4 )
	{
	}
	void operator()( ArgDef* pArg ) const
	{
		if( !m_ValueTable.AddArg( pArg->GetType(), pArg->GetName(), m_Addr ) ){
			m_pCompiler->error( pArg->GetLocation(), "Argument " + pArg->GetName() + " is already registered." );
		}
		--m_Addr;
	}
};

void Compiler::AddFunction( const yy::location& location, int type, const std::string* pName, ArgList* pArgs, StateBlock* pBlock )
{
	std::auto_ptr < const std::string > name( pName );
	std::auto_ptr < ArgList > args( pArgs );
	std::auto_ptr < StateBlock > block( pBlock );

	FunctionTag* pTag = m_Functions.Find( *pName );
	if( pTag ){
		if( pTag->IsDefinition() ){
			error( location, "Function : " + *pName + " is already registered." );
			return;
		}
		if( pTag->IsDeclaration() && !pTag->CheckArgList( pArgs ) ){
			error( location, "Function : " + *pName + " has different argument type." );
			return;
		}
		pTag->SetDefinition();
	}
	else{
		FunctionTag func( type );
		func.SetArgs( pArgs );
		func.SetDefinition();
		func.SetIndex( MakeLabel() );
		pTag = m_Functions.Add( *pName, func );
		if( pTag == 0 ){
			error( location, "Internal error : The function can not be registered." );
		}
	}
	m_CurFunctionName = *pName;
	m_CurFunctionType = type;

	SetLabel( pTag->GetIndex() );	// Entry point of the function.
	
	BlockIn();		// Increase the stack for variables.

	// Register arguments.
	if( pArgs ){
		pArgs->ForEachReverse( AddVal( this, m_Variables.back() ) );
	}

	// Analyze block.
	if( pBlock ){
		pBlock->Analyze( this );
	}

	const VMCode& code = m_Statement.back();
	if( type == TYPE_VOID ){
		if( code.m_OP != VM_RETURN ){
			OpReturn();
		}
	}
	else{
		if( code.m_OP != VM_RETURNV ){
			error( location, "Function : " + *pName + " has no return." );
		}
	}

	BlockOut();

	m_CurFunctionName.clear();
}

void Compiler::AddValue( const yy::location& location, int type, const std::string& name, const Node* pNode )
{
	int size = 1;
	if( pNode ){
		if( pNode->GetOP() != OP_CONST ){
			error( location, "Array size must be constant." );
		}
		else if( pNode->GetValue() <= 0 ){
			error( location, "Array size must be positive." );
		}
		size = pNode->GetValue();
	}

	ValueTable& values = m_Variables.back();
	if( !values.Add( type, name, size ) ){
		error( location, "Variable : " + name + "is already registered." );
	}
}

int Compiler::MakeLabel()
{
	int index = (int)m_Labels.size();
	m_Labels.push_back( Label( index ) );
	return index;
}

void Compiler::SetLabel( int label )
{
	m_Statement.push_back( VMCode( VM_MAXCOMMAND, label ) );
}

void Compiler::PushString( const std::string& str )
{
	PushString( (int)m_TextTable.size() );
	m_TextTable.insert( m_TextTable.end(), str.begin(), str.end() );
	m_TextTable.push_back( '\0' );
}

bool Compiler::JmpBreakLabel()
{
	if( m_BreakIndex < 0 ){
		return false;
	}
	OpJmp( m_BreakIndex );
	return true;
}

void Compiler::BlockIn()
{
	int startAddr = 0;
	if( m_Variables.size() > 1 ){
		startAddr = m_Variables.back().GetSize();
	}
	m_Variables.push_back( ValueTable( startAddr ) );
}

void Compiler::BlockOut()
{
	m_Variables.pop_back();
}

void Compiler::AllocStack()
{
	OpAllocStack( m_Variables.back().GetSize() );
}

// Calculate address to the label.
struct CalcAddr
{
	std::vector < Label >&		m_Labels;
	int&						m_Pos;
	CalcAddr( std::vector < Label >& labels, int& pos ) : m_Labels( labels ), m_Pos( pos )
	{
	}
	void operator()( const VMCode& code )
	{
		if( code.m_OP == VM_MAXCOMMAND ){
			m_Labels[ code.m_Arg1 ].m_Pos = m_Pos;
		}
		else{
			m_Pos += code.m_Size;
		}
	}
};

// Set address to the label.
struct SetAddr
{
	std::vector < Label >&	m_Labels;
	SetAddr( std::vector < Label >& labels ) : m_Labels( labels )
	{
	}
	void operator()( VMCode& code )
	{
		switch( code.m_OP ){
			case VM_JMP:
			case VM_JMPC:
			case VM_JMPNC:
			case VM_TEST:
			case VM_CALL:
				code.m_Arg1 = m_Labels[ code.m_Arg1 ].m_Pos;
				break;
		}
	}
};

int Compiler::LabelSetting()
{
	int pos = 0;
	std::for_each( m_Statement.begin(), m_Statement.end(), CalcAddr( m_Labels, pos ) );
	std::for_each( m_Statement.begin(), m_Statement.end(), SetAddr( m_Labels ) );

	return pos;
}

struct CopyCode
{
	unsigned char* p;
	CopyCode( unsigned char* pCode ) : p( pCode )
	{
	}
	void operator()( const VMCode& code )
	{
		p = code.Get( p );
	}
};

bool Compiler::CreateData( VM::Data& data, int codeSize )
{
	// Entry point for the program is main function.
	const FunctionTag* pTag = GetFunctionTag( "main" );
	if( pTag == 0 ){
		error( "Function : main is not found." );
		return false;
	}

	data.m_Command = new unsigned char[ codeSize ];		// Binary data.
	data.m_TextBuffer = new char[ m_TextTable.size() ];	// Source code.
	data.m_CommandSize = codeSize;						// Binary size.
	data.m_TextSize = (int)m_TextTable.size();			// Source code size.
	data.m_ValueSize = (int)m_Variables[ 0 ].GetSize();
	data.m_EntryPoint = m_Labels[ pTag->m_Index ].m_Pos;	// Entry point.(main function)

	if( data.m_TextSize != 0 ){
		memcpy( data.m_TextBuffer, &m_TextTable[ 0 ], data.m_TextSize );
	}

	std::for_each( m_Statement.begin(), m_Statement.end(), CopyCode( data.m_Command ) );
	
	return true;
}


#ifdef _DEBUG
void Compiler::DebugDump()
{
	std::cout << "---variables---" << std::endl;
	size_t vsize = m_Variables.size();
	std::cout << "value stack = " << vsize << std::endl;
	for( size_t i = 0; i < vsize; ++i ){
		m_Variables[ i ].Dump();
	}
	std::cout << "---code---" << std::endl;

	static const char* opName[] = {
#define VM_NAMETABLE
#include "VMCode.h"
#undef VM_NAMETABLE
		"LABEL",
	};

	int pos = 0;
	size_t size = m_Statement.size();
	for( size_t i = 0; i < size; ++i ){
		std::cout << std::setw( 6 ) << pos << ": " << opName[ m_Statement[ i ].m_OP ];//opName[ m_Statement[ i ].m_OP ];
		if( m_Statement[ i ].m_Size > 1 ){
			std::cout << ", " << m_Statement[ i ].m_Arg1;
		}
		std::cout << std::endl;
		if( m_Statement[ i ].m_OP != VM_MAXCOMMAND ){
			pos += m_Statement[ i ].m_Size;
		}
	}
}

#endif

