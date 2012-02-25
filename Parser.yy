%skelton "lalr.cc"
#define "parser_class_name" "Parser"
#defines
%{
	#include <string>
	#include "Node.h"
	class Compiler;
%}
%parse-param{ Compiler& compiler }
%lex-param{ Compiler& compiler }
%locations
%except 1	/* Ignore the if-colision once. */
%initial-action
{
	/* Initialize locations */
	@$.begin.filename = @$.end.filename = &compiler.get_filename();
}
/* Debug */
%error-verbose
/* Symbol */
%union
{
	int		m_IntVal;
	std::string*	m_pStrVal;
	int		m_Type;
	ValueList*	m_pValueList;
	ArgList*	m_pArgList;
	DeclList*	m_pDeclList;
	StateList*	m_pStateList;
	Statement*	m_pStatement;
	ArgDef*		m_pArgDef;
	Args*		m_pArgs;
	ValueNode*	m_pVal;
	Node*		m_pExpr;
	Assign*		m_pAssign;
	StateBlock*	m_pBlock;
}
%{
#include "Compiler.h"
%}

/* Terminal symbols */

/* EOF */
%token			TOKEN_EOF		0	"end of file"
/* Integer value */
%token <m_IntVal>	TOKEN_IVAL			"ival"
/* Identifier */
%token <m_pStrVal>	TOKEN_IDENTIFIER		"identifier"
/* String value */
%token <m_pStrVal>	TOKEN_SVAL			"sval"
/* Operations */
%token			TOKEN_LOGOR			"||"
%token			TOKEN_LOGAND			"&&"
%token			TOKEN_EQ			"=="
%token			TOKEN_NE			"!="
%token			TOKEN_GE			">="
%token			TOKEN_LE			"<="
%token			TOKEN_LSHIFT			"<<"
%token			TOKEN_RSHIFT			">>"
%token			TOKEN_ADDASSIGN			"+="
%token			TOKEN_SUBASSIGN			"-="
%token			TOKEN_MULASSIGN			"*="
%token			TOKEN_DIVASSIGN			"/="
%token			TOKEN_MODASSIGN			"%="
/* Statements */
%token			TOKEN_IF			"if"
%token			TOKEN_ELSE			"else"
%token			TOKEN_WHILE			"while"
%token			TOKEN_FOR			"for"
%token			TOKEN_SWITCH			"switch"
%token			TOKEN_CASE			"case"
%token			TOKEN_DEFAULT			"default"
%token			TOKEN_BREAK			"break"
%token			TOKEN_RETURN			"return"
%token			TOKEN_INTEGER			"int"
%token			TOKEN_STRING			"string"
%token			TOKEN_VOID			"void"

/* Nonterminal symbols */

%type <m_pExpr>		expr
%type <m_pVal>		value
%type <m_pAssign>	assign
%type <m_pValueList>	vallist
%type <m_pArgList>	arglist
%type <m_pArgDef>	argdef
%type <m_pDeclList>	decllist
%type <m_pStateList>	statelist
%type <m_pBlock>	block
%type <m_pArgs>		args
%type <m_pStatement>	statement
%type <m_Type>		type

/* Destructor */

%destructor { delete $$; } "identifier"
%destructor { delete $$; } "sval"
%destructor { delete $$; } vallist
%destructor { delete $$; } arglist
%destructor { delete $$; } argdef
%destructor { delete $$; } decllist
%destructor { delete $$; } statelist
%destructor { delete $$; } args
%destructor { delete $$; } block
%destructor { delete $$; } assign
%destructor { delete $$; } statement
%destructor { delete $$; } value
%destructor { delete $$; } expr

/* Priority */

%left "||";
%left "&&";
%nonassoc "==" "!=" '>' '<' ">=" "<=";
%left '&' '|';
%left '+' '-';
%left '*' '/' '%';
%left NEG;

/* Grammer */

%%

%start unit;

unit:	sentence
	| unit sentence
	;

sentence:	error ';'
		| function
		| declaration
		;

declaration:	type vallist ';'				{ connector.DefineVal( @2, $1, $2 ); }
		| type "identifier" '(' ')' ';'			{ connector.DefineFunc( @2, $1, $2, NULL ); }
		| type "identifier" '(' arglist ')' ';'		{ connector.DefineFunc( @2, $1, $2, $4 ); }
		| "void" "identifier" '(' ')' ';'		{ connector.DefineFunc( @2, TYPE_VOID, $2, NULL ); }
		| "void" "identifier" '(' arglist ')' ';'	{ connector.DefineFunc( @2, TYPE_VOID, $2. NULL ); }
		;
