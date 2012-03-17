#include <exception>
#include "VM.h"

int VM::VCPU::Run()
{
	m_pCommand = m_Data.m_Command;
	m_pTextBuffer = m_Data.m_TextBuffer;
	m_CommandSize = m_Data.m_CommandSize;
	m_TextSize = m_Data.m_TextSize;

	m_GlobalValue.resize( m_Data.m_ValueSize );
	m_pCommandPtr = m_pCommand + m_Data.m_EntryPoint;

	// Call main
	Push( 0 );		// Arguments count of main
	Push( 0 );		// Initial stack base
	Push( 0 );		// Exit point
	m_StackBase = m_Stack.Size();

	try{
		int op;
		while( ( op = *m_pCommandPtr++ ) != VM_HALT ){
			switch( op ){
				#define VM_SWITCHTABLE
				#include "VMCode.h"
				#undef VM_SWITCHTABLE
			}
		}
	}
	catch( const std::exception& e )
	{
		std::cerr << "VM Error : " << e.what() << std::endl;
		return -1;
	}
	return Top().m_Integer;		// Return value of main function.
}
