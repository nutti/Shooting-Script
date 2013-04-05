%{
	#include <cstdlib>
	#include <cerrno>
	#include <climits>
	#include <string>
	#include "Compiler.h"
	#include "Parser.hh"
	#include "../Math.hpp"
	#undef yywrap
	#define yywrap() 1
	#define yyterminate() return token::TOKEN_EOF
%}

%option noyywrap nounput batch
%option never-interactive
%option noyy_scan_buffer
%option noyy_scan_bytes
%option noyy_scan_string
%option 8bit
%option nounistd

identifier	[a-zA-Z_][a-zA-Z_0-9]*
integer		[1-9][0-9]*
floating	[0-9]*[.][0-9]+f
gameunit	[0-9]*[_][0-9]+g
blank		[ \t]


%x COMMENT_C
%x COMMENT_CPP
%x STRING

%{
	#define YY_USER_ACTION yylloc->columns( yyleng );
%}
%%
%{
	typedef yy::Parser::token token;
	yylloc->step();
	std::string string_buffer;
%}
<INITIAL>{
	\n				{ yylloc->lines(); }
	"^#"				{ yylloc->step(); BEGIN( COMMENT_CPP ); }
	"//"				{ yylloc->step(); BEGIN( COMMENT_CPP ); }
	"/*"				{ yylloc->step(); BEGIN( COMMENT_C ); }

	"if"				return token::TOKEN_IF;
	"else"				return token::TOKEN_ELSE;
	"for"				return token::TOKEN_FOR;
	"while"				return token::TOKEN_WHILE;
	"switch"			return token::TOKEN_SWITCH;
	"case"				return token::TOKEN_CASE;
	"default"			return token::TOKEN_DEFAULT;
	"break"				return token::TOKEN_BREAK;
	"return"			return token::TOKEN_RETURN;

	"float"				return token::TOKEN_FLOAT;
	"string"			return token::TOKEN_STRING;
	"int"				return token::TOKEN_INTEGER;
	"void"				return token::TOKEN_VOID;
	"gu"				return token::TOKEN_GU;

	\\\n				yylloc->lines();

	[-+*/=%&|(){}<>\[\],:;&]	return yy::Parser::token_type( yytext[ 0 ] );

	"&&"				return token::TOKEN_LOGAND;
	"||"				return token::TOKEN_LOGOR;
	"=="				return token::TOKEN_EQ;
	"!="				return token::TOKEN_NE;
	">="				return token::TOKEN_GE;
	"<="				return token::TOKEN_LE;
	"<<"				return token::TOKEN_LSHIFT;
	">>"				return token::TOKEN_RSHIFT;
	"+="				return token::TOKEN_ADDASSIGN;
	"-="				return token::TOKEN_SUBASSIGN;
	"*="				return token::TOKEN_MULASSIGN;
	"/="				return token::TOKEN_DIVASSIGN;
	"%="				return token::TOKEN_MODASSIGN;

	{blank}+			yylloc->step();

	\"				{
						yylloc->step();
						string_buffer.clear();
						BEGIN( STRING );
					}

	{integer}			{
						errno = 0;
						long n = strtol( yytext, NULL, 10 );
						if( n < LONG_MIN || n > LONG_MAX || errno == ERANGE ){
							compiler.error( *yylloc, "Integer is out of range." );
						}
						yylval->m_IntVal = n;
						return token::TOKEN_IVAL;
					}
	

	{floating}		{
						errno = 0;
						float n = (float)strtod( yytext, NULL );
						yylval->m_FloatVal = n;
						return token::TOKEN_FVAL;
					}
	{gameunit}		{
						errno = 0;
						char* end = yytext;
						int integer;
						int decimal;
						char str[ 25 ];
						int len = 0;
						
						
						while( *end != '_' ){
							str[ len++ ] = *end++;
						}
						++end;
						str[ len ] = '\0';
						integer = strtol( str, NULL, 10 );
						len = 0;
						
						while( *end != 'g' ){
							str[ len++ ] = *end++;
						}
						str[ len ] = '\0';
						decimal = strtol( str, NULL, 10 );
						yylval->m_pGUVal = new GameEngine::GameUnit( integer, decimal );
						
						return token::TOKEN_GVAL;
					}
						

	"0"				{
						yylval->m_IntVal = 0;
						return token::TOKEN_IVAL;
					}

	{identifier}			{
						yylval->m_pStrVal = new std::string( yytext );
						return token::TOKEN_IDENTIFIER;
					}
	
	.				compiler.error( *yylloc, "Can not use the character as identifier" );
}
<STRING>{
	\n				{
						yylloc->lines();
						compiler.error( *yylloc, "String is not closed." );
						string_buffer.clear();
						BEGIN( INITIAL );
					}

	<<EOF>>				{
						compiler.error( *yylloc, "File is finished without closing the text file." );
						string_buffer.clear();
						BEGIN( INITIAL );
					}

	[^\\\n"]+			{ string_buffer += yytext; }

	\\\n				yylloc->lines();

	\\[^\n]				{
						switch( yytext[ yyleng - 1 ] ){
							case 'n':
								string_buffer += '\n';
								break;
							default:
								string_buffer += yytext[ yyleng - 1 ];
								break;
						}
					}


	\"				{
						BEGIN( INITIAL );
						yylval->m_pStrVal = new std::string( string_buffer );
						return token::TOKEN_SVAL;
					}
}
<COMMENT_CPP>{
	[^\n]*

	\n				{
						yylloc->lines();
						yylloc->step();
						BEGIN( INITIAL );
					}
}
<COMMENT_C>{
	[^*\n]*

	[^*\n]*\n			{ yylloc->lines(); }

	"*"+[^*/\n]*

	"*"+[^*/\n]*\n			{ yylloc->lines(); }

	<<EOF>>				compiler.error( *yylloc, "File is finished in comment processing" );

	"*"+"/"				BEGIN( INITIAL );
}
%%

void Compiler::ScanBegin()
{
	if( ( yyin = fopen( m_File.c_str(), "r" ) ) == 0 ){
		error( m_File + "can not be opened." );
	}
}

void Compiler::ScanEnd()
{
	fclose( yyin );
	yylex_destroy();
}

