#include <iostream>
#include "Compiler.h"
#include "VM.h"
#define _DEBUG

int main( int argc, char* argv[] )
{
	for( ++argv; argv[ 0 ]; ++argv ){
		VM::Data data;
		bool compileResult;
		{
			Compiler compiler;
			compileResult = compiler.Compile( *argv, data );
#ifdef _DEBUG
			if( compileResult ){
				compiler.DebugDump();
			}
#endif
		}
		if( compileResult ){
			VM::VCPU machine( data );
			int result = machine.Run();
			std::cout << "result = " << result << std::endl;
		}
	}
	return 0;
}
