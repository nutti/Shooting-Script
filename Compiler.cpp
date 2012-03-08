#include <iostream>
#include <iomanip>
#include <memory>
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

	// Global variables.
	m_Variables.push_back( ValueTable() );
	m_Variables[ 0 ].SetGlobal();

	// HALT operation is first operation.
	OpHalt();

	m_File = f;
	ScanBegin();						// Initialize scanner.
	yy::Parser parser( *this );			// Build parser.
	int result = parser.parser();		// Analyze grammer.
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
	func.SetInex( index )		// Set system call number.
	if( func.Add( pName, func ) == 0 ){
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

	const FunctionTag* pTag = m_Functions.find( *pName );
	if( pTag ){
		if( !pTag->ChkArgList( pArgs ) ){
			error( location, "Function " + *pName + " has different type of argument." );
			return;
		}
	}
	else{
		FunctionTag func( type );
		func.SetArgs( pArgs );			// Set arguments.
		func.SetDeclaration();			// Set declared flag.
		func.SetInex( MakeLabel() );	// Set label.
		if( m_Functions.Add( *pName, func ) == 0 ){
			error( location, "Internal Error : Failed to register to function table." );
		}
	}
}

struct AddValue
{
	Compiler*		m_pCompiler;
	ValueTable&		m_ValueTable;
	mutable int		m_Addr;
	AddValue( Compiler* pCompiler, ValueTable& values ) :	m_pCompiler( pCompiler ),
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






