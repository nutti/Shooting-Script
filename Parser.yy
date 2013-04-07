%skeleton "lalr1.cc"
%define "parser_class_name" "Parser"
%defines
%{
	#include <string>
	#include "Node.h"
	#include "../Math.hpp"
	class Compiler;
%}
%parse-param{ Compiler& compiler }
%lex-param{ Compiler& compiler }
%locations
%expect 1	/* Ignore the if-colision once. */
%initial-action
{
	/* Initialize locations */
	@$.begin.filename = @$.end.filename = &compiler.GetFileName();
}
/* Debug */
%error-verbose
/* Symbol */
%union
{
	int		m_IntVal;
	std::string*	m_pStrVal;
	float	m_FloatVal;
	int		m_Type;
	GameEngine::ScriptGU  m_GUVal;
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
/* Float value */
%token <m_FloatVal> TOKEN_FVAL			"fval"
/* Game Unit value */
%token <m_GUVal> TOKEN_GVAL		"gval"
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
%token			TOKEN_FLOAT				"float"
%token			TOKEN_VOID			"void"
%token			TOKEN_GU			"gu"

/* Nonterminal symbols */

%type <m_pExpr>		expr
%type <m_pVal>		value
%type <m_pAssign>	assign
%type <m_pValueList>	vallist
%type <m_pArgList>	arglist
%type <m_pArgDef>	argdef
%type <m_pDeclList>	decls decllist
%type <m_pStateList>	states statelist
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
%destructor { delete $$; } decls decllist
%destructor { delete $$; } states statelist
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
%left "<<" ">>";
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

declaration:	type vallist ';'				{ compiler.DefineValue( @2, $1, $2 ); }
		| type "identifier" '(' ')' ';'			{ compiler.DefineFunction( @2, $1, $2, NULL ); }
		| type "identifier" '(' arglist ')' ';'		{ compiler.DefineFunction( @2, $1, $2, $4 ); }
		| "void" "identifier" '(' ')' ';'		{ compiler.DefineFunction( @2, TYPE_VOID, $2, NULL ); }
		| "void" "identifier" '(' arglist ')' ';'	{ compiler.DefineFunction( @2, TYPE_VOID, $2, $4 ); }
		;

vallist:	value						{ $$ = new ValueList( $1 ); }
		| vallist ',' value				{ $$ = $1->Add( $3 ); }
		;

arglist:	argdef						{ $$ = new ArgList( $1 ); }
		| arglist ',' argdef				{ $$ = $1->Add( $3 ); }
		;

argdef:		type						{ $$ = new ArgDef( @1, $1, NULL ); }
		| type '&'					{ $$ = new ArgDef( @1, TypeToRef( $1 ), NULL ); }
		| type "identifier"				{ $$ = new ArgDef( @1, $1, $2 ); }
		| type '&' "identifier"				{ $$ = new ArgDef( @1, TypeToRef( $1 ), $3 ); }
		| type "identifier" '[' ']'			{ $$ = new ArgDef( @1, TypeToRef( $1 ), $2 ); }
		| type '&' "identifier" '[' ']'			{ $$ = new ArgDef( @1, TypeToRef( $1 ), $3 ); }
		;

function:	type "identifier" '(' ')' block			{ compiler.AddFunction( @1, $1, $2, NULL, $5 ); }
		| type "identifier" '(' arglist ')' block	{ compiler.AddFunction( @1, $1, $2, $4, $6 ); }
		| "void" "identifier" '(' ')' block		{ compiler.AddFunction( @1, TYPE_VOID, $2, NULL, $5 ); }
		| "void" "identifier" '(' arglist ')' block	{ compiler.AddFunction( @1, TYPE_VOID, $2, $4, $6 ); }
		;

type:		"int"						{ $$ = TYPE_INTEGER; }
		| "string"					{ $$ = TYPE_STRING; }
		| "float"					{ $$ = TYPE_FLOAT; }
		| "gu"						{ $$ = TYPE_GU; }
		;

block:		'{' decllist statelist '}'			{ $$ = new StateBlock( $2, $3 ); }
		;

decllist:							{ $$ = NULL; }
		| decls						{ $$ = $1; }
		;

statelist:							{ $$ = NULL; }
		| states					{ $$ = $1; }
		;

decls:		type vallist ';'				{ $$ = new DeclList( new Decl( $1, $2 ) ); }
		| decls type vallist ';'			{ $$ = $1->Add( new Decl( $2, $3 ) ); }
		;

states:		statement					{ $$ = new StateList( $1 ); }
		| states statement				{ $$ = $1->Add( $2 ); }
		;

statement:	';'							{ $$ = new NopStatement( @1 ); }
		| assign ';'						{ $$ = new AssignStatement( @1, $1 ); }
		| "identifier" '(' args ')' ';'				{ $$ = new FunctionStatement( @1, $1, $3 ); }
		| "identifier" '(' ')' ';'				{ $$ = new FunctionStatement( @1, $1, NULL ); }
		| "case" expr ':'					{ $$ = new CaseStatement( @1, $2 ); }
		| "default" ':'						{ $$ = new DefaultStatement( @1 ); }
		| "break" ';'						{ $$ = new BreakStatement( @1 ); }
		| "return" ';'						{ $$ = new ReturnStatement( @1, NULL ); }
		| "return" expr ';'					{ $$ = new ReturnStatement( @1, $2 ); }
		| "if" '(' expr ')' statement				{ $$ = new IfStatement( @1, $3, $5 ); }
		| "if" '(' expr ')' statement "else" statement		{ $$ = new IfStatement( @1, $3, $5, $7 ); }
		| "for" '(' assign ';' expr ';' assign ')' statement	{ $$ = new ForStatement( @1, $3, $5, $7, $9 ); }
		| "while" '(' expr ')' statement			{ $$ = new WhileStatement( @1, $3, $5 ); }
		| "switch" '(' expr ')' '{' statelist '}'		{ $$ = new SwitchStatement( @1, $3, $6 ); }
		| block							{ $$ = new BlockStatement( @1, $1 ); }
		;

assign:		value '=' expr				{ $$ = new Assign( @1, '=', $1, $3 ); }
		| value "+=" expr			{ $$ = new Assign( @1, '+', $1, $3 ); }
		| value "-=" expr			{ $$ = new Assign( @1, '-', $1, $3 ); }
		| value "*=" expr			{ $$ = new Assign( @1, '*', $1, $3 ); }
		| value "/=" expr			{ $$ = new Assign( @1, '/', $1, $3 ); }
		| value "%=" expr			{ $$ = new Assign( @1, '%', $1, $3 ); }
		;

expr:		expr "&&" expr				{ $$ = Node::MakeNode( compiler, @2, OP_LOGAND, $1, $3 ); }
		| expr "||" expr			{ $$ = Node::MakeNode( compiler, @2, OP_LOGOR, $1, $3 ); }
		| expr "==" expr			{ $$ = Node::MakeNode( compiler, @2, OP_EQ, $1, $3 ); }
		| expr "!=" expr			{ $$ = Node::MakeNode( compiler, @2, OP_NE, $1, $3 ); }
		| expr '>' expr				{ $$ = Node::MakeNode( compiler, @2, OP_GT, $1, $3 ); }
		| expr ">=" expr			{ $$ = Node::MakeNode( compiler, @2, OP_GE, $1, $3 ); }
		| expr '<' expr				{ $$ = Node::MakeNode( compiler, @2, OP_LT, $1, $3 ); }
		| expr "<=" expr			{ $$ = Node::MakeNode( compiler, @2, OP_LE, $1, $3 ); }
		| expr '&' expr				{ $$ = Node::MakeNode( compiler, @2, OP_AND, $1, $3 ); }
		| expr '|' expr				{ $$ = Node::MakeNode( compiler, @2, OP_OR, $1, $3 ); }
		| expr "<<" expr			{ $$ = Node::MakeNode( compiler, @2, OP_LSHIFT, $1, $3 ); }
		| expr ">>" expr			{ $$ = Node::MakeNode( compiler, @2, OP_RSHIFT, $1, $3 ); }
		| expr '-' expr				{ $$ = Node::MakeNode( compiler, @2, OP_MINUS, $1, $3 ); }
		| expr '+' expr				{ $$ = Node::MakeNode( compiler, @2, OP_PLUS, $1, $3 ); }
		| expr '*' expr				{ $$ = Node::MakeNode( compiler, @2, OP_TIMES, $1, $3 ); }
		| expr '/' expr				{ $$ = Node::MakeNode( compiler, @2, OP_DIVIDE, $1, $3 ); }
		| expr '%' expr				{ $$ = Node::MakeNode( compiler, @2, OP_MOD, $1, $3 ); }
		| '-' expr %prec NEG			{ $$ = Node::MakeNode( compiler, @2, OP_NEG, $2 ); }
		| '(' expr ')'				{ $$ = $2; }
		| value					{ $$ = $1; }
		| "ival"				{ $$ = new Node( @1, OP_INT_CONST, $1 ); }
		| "sval"				{ $$ = new Node( @1, OP_STRING, $1 ); }
		| "fval"				{ $$ = new Node( @1, OP_FLOAT_CONST, $1 ); }
		| "gval"				{ $$ = new Node( @1, OP_GU_CONST, $1 ); }
		| "identifier" '(' args ')'		{ $$ = new FunctionNode( @1, $1, $3 ); }
		| "identifier" '(' ')'			{ $$ = new FunctionNode( @1, $1, NULL ); }
		;

value:		"identifier"				{ $$ = new ValueNode( @1, $1 ); }
		| "identifier" '[' expr ']'		{ $$ = new ValueNode( @1, $1, $3 ); }
		;

args:		expr					{ $$ = new Args( $1 ); }
		| args ',' expr				{ $$ = $1->Add( $3 ); }

%%

void yy::Parser::error( const yy::Parser::location_type& l, const std::string& m )
{
	compiler.error( l, m );
}
