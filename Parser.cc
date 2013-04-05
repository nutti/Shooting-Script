
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison LALR(1) parsers in C++
   
      Copyright (C) 2002, 2003, 2004, 2005, 2006, 2007, 2008 Free Software
   Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* First part of user declarations.  */

/* Line 311 of lalr1.cc  */
#line 4 "Parser.yy"

	#include <string>
	#include "Node.h"
	#include "../Math.hpp"
	class Compiler;


/* Line 311 of lalr1.cc  */
#line 49 "Parser.cc"


#include "Parser.hh"

/* User implementation prologue.  */

/* Line 317 of lalr1.cc  */
#line 41 "Parser.yy"

#include "Compiler.h"


/* Line 317 of lalr1.cc  */
#line 63 "Parser.cc"

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* FIXME: INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#define YYUSE(e) ((void) (e))

/* Enable debugging if requested.  */
#if YYDEBUG

/* A pseudo ostream that takes yydebug_ into account.  */
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)	\
do {							\
  if (yydebug_)						\
    {							\
      *yycdebug_ << Title << ' ';			\
      yy_symbol_print_ ((Type), (Value), (Location));	\
      *yycdebug_ << std::endl;				\
    }							\
} while (false)

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug_)				\
    yy_reduce_print_ (Rule);		\
} while (false)

# define YY_STACK_PRINT()		\
do {					\
  if (yydebug_)				\
    yystack_print_ ();			\
} while (false)

#else /* !YYDEBUG */

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_REDUCE_PRINT(Rule)
# define YY_STACK_PRINT()

#endif /* !YYDEBUG */

#define yyerrok		(yyerrstatus_ = 0)
#define yyclearin	(yychar = yyempty_)

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


/* Line 380 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

namespace yy {

/* Line 380 of lalr1.cc  */
#line 132 "Parser.cc"
#if YYERROR_VERBOSE

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  Parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr = "";
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              /* Fall through.  */
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }

#endif

  /// Build a parser object.
  Parser::Parser (Compiler& compiler_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      compiler (compiler_yyarg)
  {
  }

  Parser::~Parser ()
  {
  }

#if YYDEBUG
  /*--------------------------------.
  | Print this symbol on YYOUTPUT.  |
  `--------------------------------*/

  inline void
  Parser::yy_symbol_value_print_ (int yytype,
			   const semantic_type* yyvaluep, const location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yyvaluep);
    switch (yytype)
      {
         default:
	  break;
      }
  }


  void
  Parser::yy_symbol_print_ (int yytype,
			   const semantic_type* yyvaluep, const location_type* yylocationp)
  {
    *yycdebug_ << (yytype < yyntokens_ ? "token" : "nterm")
	       << ' ' << yytname_[yytype] << " ("
	       << *yylocationp << ": ";
    yy_symbol_value_print_ (yytype, yyvaluep, yylocationp);
    *yycdebug_ << ')';
  }
#endif

  void
  Parser::yydestruct_ (const char* yymsg,
			   int yytype, semantic_type* yyvaluep, location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yymsg);
    YYUSE (yyvaluep);

    YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

    switch (yytype)
      {
        case 4: /* "\"identifier\"" */

/* Line 480 of lalr1.cc  */
#line 106 "Parser.yy"
	{ delete (yyvaluep->m_pStrVal); };

/* Line 480 of lalr1.cc  */
#line 239 "Parser.cc"
	break;
      case 5: /* "\"sval\"" */

/* Line 480 of lalr1.cc  */
#line 107 "Parser.yy"
	{ delete (yyvaluep->m_pStrVal); };

/* Line 480 of lalr1.cc  */
#line 248 "Parser.cc"
	break;
      case 59: /* "vallist" */

/* Line 480 of lalr1.cc  */
#line 108 "Parser.yy"
	{ delete (yyvaluep->m_pValueList); };

/* Line 480 of lalr1.cc  */
#line 257 "Parser.cc"
	break;
      case 60: /* "arglist" */

/* Line 480 of lalr1.cc  */
#line 109 "Parser.yy"
	{ delete (yyvaluep->m_pArgList); };

/* Line 480 of lalr1.cc  */
#line 266 "Parser.cc"
	break;
      case 61: /* "argdef" */

/* Line 480 of lalr1.cc  */
#line 110 "Parser.yy"
	{ delete (yyvaluep->m_pArgDef); };

/* Line 480 of lalr1.cc  */
#line 275 "Parser.cc"
	break;
      case 64: /* "block" */

/* Line 480 of lalr1.cc  */
#line 114 "Parser.yy"
	{ delete (yyvaluep->m_pBlock); };

/* Line 480 of lalr1.cc  */
#line 284 "Parser.cc"
	break;
      case 65: /* "decllist" */

/* Line 480 of lalr1.cc  */
#line 111 "Parser.yy"
	{ delete (yyvaluep->m_pDeclList); };

/* Line 480 of lalr1.cc  */
#line 293 "Parser.cc"
	break;
      case 66: /* "statelist" */

/* Line 480 of lalr1.cc  */
#line 112 "Parser.yy"
	{ delete (yyvaluep->m_pStateList); };

/* Line 480 of lalr1.cc  */
#line 302 "Parser.cc"
	break;
      case 67: /* "decls" */

/* Line 480 of lalr1.cc  */
#line 111 "Parser.yy"
	{ delete (yyvaluep->m_pDeclList); };

/* Line 480 of lalr1.cc  */
#line 311 "Parser.cc"
	break;
      case 68: /* "states" */

/* Line 480 of lalr1.cc  */
#line 112 "Parser.yy"
	{ delete (yyvaluep->m_pStateList); };

/* Line 480 of lalr1.cc  */
#line 320 "Parser.cc"
	break;
      case 69: /* "statement" */

/* Line 480 of lalr1.cc  */
#line 116 "Parser.yy"
	{ delete (yyvaluep->m_pStatement); };

/* Line 480 of lalr1.cc  */
#line 329 "Parser.cc"
	break;
      case 70: /* "assign" */

/* Line 480 of lalr1.cc  */
#line 115 "Parser.yy"
	{ delete (yyvaluep->m_pAssign); };

/* Line 480 of lalr1.cc  */
#line 338 "Parser.cc"
	break;
      case 71: /* "expr" */

/* Line 480 of lalr1.cc  */
#line 118 "Parser.yy"
	{ delete (yyvaluep->m_pExpr); };

/* Line 480 of lalr1.cc  */
#line 347 "Parser.cc"
	break;
      case 72: /* "value" */

/* Line 480 of lalr1.cc  */
#line 117 "Parser.yy"
	{ delete (yyvaluep->m_pVal); };

/* Line 480 of lalr1.cc  */
#line 356 "Parser.cc"
	break;
      case 73: /* "args" */

/* Line 480 of lalr1.cc  */
#line 113 "Parser.yy"
	{ delete (yyvaluep->m_pArgs); };

/* Line 480 of lalr1.cc  */
#line 365 "Parser.cc"
	break;

	default:
	  break;
      }
  }

  void
  Parser::yypop_ (unsigned int n)
  {
    yystate_stack_.pop (n);
    yysemantic_stack_.pop (n);
    yylocation_stack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  Parser::debug_level_type
  Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif

  int
  Parser::parse ()
  {
    /// Lookahead and lookahead in internal form.
    int yychar = yyempty_;
    int yytoken = 0;

    /* State.  */
    int yyn;
    int yylen = 0;
    int yystate = 0;

    /* Error handling.  */
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// Semantic value of the lookahead.
    semantic_type yylval;
    /// Location of the lookahead.
    location_type yylloc;
    /// The locations where the error started and ended.
    location_type yyerror_range[2];

    /// $$.
    semantic_type yyval;
    /// @$.
    location_type yyloc;

    int yyresult;

    YYCDEBUG << "Starting parse" << std::endl;


    /* User initialization code.  */
    
/* Line 553 of lalr1.cc  */
#line 15 "Parser.yy"
{
	/* Initialize locations */
	yylloc.begin.filename = yylloc.end.filename = &compiler.GetFileName();
}

/* Line 553 of lalr1.cc  */
#line 451 "Parser.cc"

    /* Initialize the stacks.  The initial state will be pushed in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystate_stack_ = state_stack_type (0);
    yysemantic_stack_ = semantic_stack_type (0);
    yylocation_stack_ = location_stack_type (0);
    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yylloc);

    /* New state.  */
  yynewstate:
    yystate_stack_.push (yystate);
    YYCDEBUG << "Entering state " << yystate << std::endl;

    /* Accept?  */
    if (yystate == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    /* Backup.  */
  yybackup:

    /* Try to take a decision without lookahead.  */
    yyn = yypact_[yystate];
    if (yyn == yypact_ninf_)
      goto yydefault;

    /* Read a lookahead token.  */
    if (yychar == yyempty_)
      {
	YYCDEBUG << "Reading a token: ";
	yychar = yylex (&yylval, &yylloc, compiler);
      }


    /* Convert token to internal form.  */
    if (yychar <= yyeof_)
      {
	yychar = yytoken = yyeof_;
	YYCDEBUG << "Now at end of input." << std::endl;
      }
    else
      {
	yytoken = yytranslate_ (yychar);
	YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
      }

    /* If the proper action on seeing token YYTOKEN is to reduce or to
       detect an error, take that action.  */
    yyn += yytoken;
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yytoken)
      goto yydefault;

    /* Reduce or error.  */
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
	if (yyn == 0 || yyn == yytable_ninf_)
	goto yyerrlab;
	yyn = -yyn;
	goto yyreduce;
      }

    /* Shift the lookahead token.  */
    YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

    /* Discard the token being shifted.  */
    yychar = yyempty_;

    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yylloc);

    /* Count tokens shifted since error; after three, turn off error
       status.  */
    if (yyerrstatus_)
      --yyerrstatus_;

    yystate = yyn;
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystate];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    /* If YYLEN is nonzero, implement the default value of the action:
       `$$ = $1'.  Otherwise, use the top of the stack.

       Otherwise, the following line sets YYVAL to garbage.
       This behavior is undocumented and Bison
       users should not rely upon it.  */
    if (yylen)
      yyval = yysemantic_stack_[yylen - 1];
    else
      yyval = yysemantic_stack_[0];

    {
      slice<location_type, location_stack_type> slice (yylocation_stack_, yylen);
      YYLLOC_DEFAULT (yyloc, slice, yylen);
    }
    YY_REDUCE_PRINT (yyn);
    switch (yyn)
      {
	  case 7:

/* Line 678 of lalr1.cc  */
#line 146 "Parser.yy"
    { compiler.DefineValue( (yylocation_stack_[(3) - (2)]), (yysemantic_stack_[(3) - (1)].m_Type), (yysemantic_stack_[(3) - (2)].m_pValueList) ); }
    break;

  case 8:

/* Line 678 of lalr1.cc  */
#line 147 "Parser.yy"
    { compiler.DefineFunction( (yylocation_stack_[(5) - (2)]), (yysemantic_stack_[(5) - (1)].m_Type), (yysemantic_stack_[(5) - (2)].m_pStrVal), NULL ); }
    break;

  case 9:

/* Line 678 of lalr1.cc  */
#line 148 "Parser.yy"
    { compiler.DefineFunction( (yylocation_stack_[(6) - (2)]), (yysemantic_stack_[(6) - (1)].m_Type), (yysemantic_stack_[(6) - (2)].m_pStrVal), (yysemantic_stack_[(6) - (4)].m_pArgList) ); }
    break;

  case 10:

/* Line 678 of lalr1.cc  */
#line 149 "Parser.yy"
    { compiler.DefineFunction( (yylocation_stack_[(5) - (2)]), TYPE_VOID, (yysemantic_stack_[(5) - (2)].m_pStrVal), NULL ); }
    break;

  case 11:

/* Line 678 of lalr1.cc  */
#line 150 "Parser.yy"
    { compiler.DefineFunction( (yylocation_stack_[(6) - (2)]), TYPE_VOID, (yysemantic_stack_[(6) - (2)].m_pStrVal), (yysemantic_stack_[(6) - (4)].m_pArgList) ); }
    break;

  case 12:

/* Line 678 of lalr1.cc  */
#line 153 "Parser.yy"
    { (yyval.m_pValueList) = new ValueList( (yysemantic_stack_[(1) - (1)].m_pVal) ); }
    break;

  case 13:

/* Line 678 of lalr1.cc  */
#line 154 "Parser.yy"
    { (yyval.m_pValueList) = (yysemantic_stack_[(3) - (1)].m_pValueList)->Add( (yysemantic_stack_[(3) - (3)].m_pVal) ); }
    break;

  case 14:

/* Line 678 of lalr1.cc  */
#line 157 "Parser.yy"
    { (yyval.m_pArgList) = new ArgList( (yysemantic_stack_[(1) - (1)].m_pArgDef) ); }
    break;

  case 15:

/* Line 678 of lalr1.cc  */
#line 158 "Parser.yy"
    { (yyval.m_pArgList) = (yysemantic_stack_[(3) - (1)].m_pArgList)->Add( (yysemantic_stack_[(3) - (3)].m_pArgDef) ); }
    break;

  case 16:

/* Line 678 of lalr1.cc  */
#line 161 "Parser.yy"
    { (yyval.m_pArgDef) = new ArgDef( (yylocation_stack_[(1) - (1)]), (yysemantic_stack_[(1) - (1)].m_Type), NULL ); }
    break;

  case 17:

/* Line 678 of lalr1.cc  */
#line 162 "Parser.yy"
    { (yyval.m_pArgDef) = new ArgDef( (yylocation_stack_[(2) - (1)]), TypeToRef( (yysemantic_stack_[(2) - (1)].m_Type) ), NULL ); }
    break;

  case 18:

/* Line 678 of lalr1.cc  */
#line 163 "Parser.yy"
    { (yyval.m_pArgDef) = new ArgDef( (yylocation_stack_[(2) - (1)]), (yysemantic_stack_[(2) - (1)].m_Type), (yysemantic_stack_[(2) - (2)].m_pStrVal) ); }
    break;

  case 19:

/* Line 678 of lalr1.cc  */
#line 164 "Parser.yy"
    { (yyval.m_pArgDef) = new ArgDef( (yylocation_stack_[(3) - (1)]), TypeToRef( (yysemantic_stack_[(3) - (1)].m_Type) ), (yysemantic_stack_[(3) - (3)].m_pStrVal) ); }
    break;

  case 20:

/* Line 678 of lalr1.cc  */
#line 165 "Parser.yy"
    { (yyval.m_pArgDef) = new ArgDef( (yylocation_stack_[(4) - (1)]), TypeToRef( (yysemantic_stack_[(4) - (1)].m_Type) ), (yysemantic_stack_[(4) - (2)].m_pStrVal) ); }
    break;

  case 21:

/* Line 678 of lalr1.cc  */
#line 166 "Parser.yy"
    { (yyval.m_pArgDef) = new ArgDef( (yylocation_stack_[(5) - (1)]), TypeToRef( (yysemantic_stack_[(5) - (1)].m_Type) ), (yysemantic_stack_[(5) - (3)].m_pStrVal) ); }
    break;

  case 22:

/* Line 678 of lalr1.cc  */
#line 169 "Parser.yy"
    { compiler.AddFunction( (yylocation_stack_[(5) - (1)]), (yysemantic_stack_[(5) - (1)].m_Type), (yysemantic_stack_[(5) - (2)].m_pStrVal), NULL, (yysemantic_stack_[(5) - (5)].m_pBlock) ); }
    break;

  case 23:

/* Line 678 of lalr1.cc  */
#line 170 "Parser.yy"
    { compiler.AddFunction( (yylocation_stack_[(6) - (1)]), (yysemantic_stack_[(6) - (1)].m_Type), (yysemantic_stack_[(6) - (2)].m_pStrVal), (yysemantic_stack_[(6) - (4)].m_pArgList), (yysemantic_stack_[(6) - (6)].m_pBlock) ); }
    break;

  case 24:

/* Line 678 of lalr1.cc  */
#line 171 "Parser.yy"
    { compiler.AddFunction( (yylocation_stack_[(5) - (1)]), TYPE_VOID, (yysemantic_stack_[(5) - (2)].m_pStrVal), NULL, (yysemantic_stack_[(5) - (5)].m_pBlock) ); }
    break;

  case 25:

/* Line 678 of lalr1.cc  */
#line 172 "Parser.yy"
    { compiler.AddFunction( (yylocation_stack_[(6) - (1)]), TYPE_VOID, (yysemantic_stack_[(6) - (2)].m_pStrVal), (yysemantic_stack_[(6) - (4)].m_pArgList), (yysemantic_stack_[(6) - (6)].m_pBlock) ); }
    break;

  case 26:

/* Line 678 of lalr1.cc  */
#line 175 "Parser.yy"
    { (yyval.m_Type) = TYPE_INTEGER; }
    break;

  case 27:

/* Line 678 of lalr1.cc  */
#line 176 "Parser.yy"
    { (yyval.m_Type) = TYPE_STRING; }
    break;

  case 28:

/* Line 678 of lalr1.cc  */
#line 177 "Parser.yy"
    { (yyval.m_Type) = TYPE_FLOAT; }
    break;

  case 29:

/* Line 678 of lalr1.cc  */
#line 178 "Parser.yy"
    { (yyval.m_Type) = TYPE_GU; }
    break;

  case 30:

/* Line 678 of lalr1.cc  */
#line 181 "Parser.yy"
    { (yyval.m_pBlock) = new StateBlock( (yysemantic_stack_[(4) - (2)].m_pDeclList), (yysemantic_stack_[(4) - (3)].m_pStateList) ); }
    break;

  case 31:

/* Line 678 of lalr1.cc  */
#line 184 "Parser.yy"
    { (yyval.m_pDeclList) = NULL; }
    break;

  case 32:

/* Line 678 of lalr1.cc  */
#line 185 "Parser.yy"
    { (yyval.m_pDeclList) = (yysemantic_stack_[(1) - (1)].m_pDeclList); }
    break;

  case 33:

/* Line 678 of lalr1.cc  */
#line 188 "Parser.yy"
    { (yyval.m_pStateList) = NULL; }
    break;

  case 34:

/* Line 678 of lalr1.cc  */
#line 189 "Parser.yy"
    { (yyval.m_pStateList) = (yysemantic_stack_[(1) - (1)].m_pStateList); }
    break;

  case 35:

/* Line 678 of lalr1.cc  */
#line 192 "Parser.yy"
    { (yyval.m_pDeclList) = new DeclList( new Decl( (yysemantic_stack_[(3) - (1)].m_Type), (yysemantic_stack_[(3) - (2)].m_pValueList) ) ); }
    break;

  case 36:

/* Line 678 of lalr1.cc  */
#line 193 "Parser.yy"
    { (yyval.m_pDeclList) = (yysemantic_stack_[(4) - (1)].m_pDeclList)->Add( new Decl( (yysemantic_stack_[(4) - (2)].m_Type), (yysemantic_stack_[(4) - (3)].m_pValueList) ) ); }
    break;

  case 37:

/* Line 678 of lalr1.cc  */
#line 196 "Parser.yy"
    { (yyval.m_pStateList) = new StateList( (yysemantic_stack_[(1) - (1)].m_pStatement) ); }
    break;

  case 38:

/* Line 678 of lalr1.cc  */
#line 197 "Parser.yy"
    { (yyval.m_pStateList) = (yysemantic_stack_[(2) - (1)].m_pStateList)->Add( (yysemantic_stack_[(2) - (2)].m_pStatement) ); }
    break;

  case 39:

/* Line 678 of lalr1.cc  */
#line 200 "Parser.yy"
    { (yyval.m_pStatement) = new NopStatement( (yylocation_stack_[(1) - (1)]) ); }
    break;

  case 40:

/* Line 678 of lalr1.cc  */
#line 201 "Parser.yy"
    { (yyval.m_pStatement) = new AssignStatement( (yylocation_stack_[(2) - (1)]), (yysemantic_stack_[(2) - (1)].m_pAssign) ); }
    break;

  case 41:

/* Line 678 of lalr1.cc  */
#line 202 "Parser.yy"
    { (yyval.m_pStatement) = new FunctionStatement( (yylocation_stack_[(5) - (1)]), (yysemantic_stack_[(5) - (1)].m_pStrVal), (yysemantic_stack_[(5) - (3)].m_pArgs) ); }
    break;

  case 42:

/* Line 678 of lalr1.cc  */
#line 203 "Parser.yy"
    { (yyval.m_pStatement) = new FunctionStatement( (yylocation_stack_[(4) - (1)]), (yysemantic_stack_[(4) - (1)].m_pStrVal), NULL ); }
    break;

  case 43:

/* Line 678 of lalr1.cc  */
#line 204 "Parser.yy"
    { (yyval.m_pStatement) = new CaseStatement( (yylocation_stack_[(3) - (1)]), (yysemantic_stack_[(3) - (2)].m_pExpr) ); }
    break;

  case 44:

/* Line 678 of lalr1.cc  */
#line 205 "Parser.yy"
    { (yyval.m_pStatement) = new DefaultStatement( (yylocation_stack_[(2) - (1)]) ); }
    break;

  case 45:

/* Line 678 of lalr1.cc  */
#line 206 "Parser.yy"
    { (yyval.m_pStatement) = new BreakStatement( (yylocation_stack_[(2) - (1)]) ); }
    break;

  case 46:

/* Line 678 of lalr1.cc  */
#line 207 "Parser.yy"
    { (yyval.m_pStatement) = new ReturnStatement( (yylocation_stack_[(2) - (1)]), NULL ); }
    break;

  case 47:

/* Line 678 of lalr1.cc  */
#line 208 "Parser.yy"
    { (yyval.m_pStatement) = new ReturnStatement( (yylocation_stack_[(3) - (1)]), (yysemantic_stack_[(3) - (2)].m_pExpr) ); }
    break;

  case 48:

/* Line 678 of lalr1.cc  */
#line 209 "Parser.yy"
    { (yyval.m_pStatement) = new IfStatement( (yylocation_stack_[(5) - (1)]), (yysemantic_stack_[(5) - (3)].m_pExpr), (yysemantic_stack_[(5) - (5)].m_pStatement) ); }
    break;

  case 49:

/* Line 678 of lalr1.cc  */
#line 210 "Parser.yy"
    { (yyval.m_pStatement) = new IfStatement( (yylocation_stack_[(7) - (1)]), (yysemantic_stack_[(7) - (3)].m_pExpr), (yysemantic_stack_[(7) - (5)].m_pStatement), (yysemantic_stack_[(7) - (7)].m_pStatement) ); }
    break;

  case 50:

/* Line 678 of lalr1.cc  */
#line 211 "Parser.yy"
    { (yyval.m_pStatement) = new ForStatement( (yylocation_stack_[(9) - (1)]), (yysemantic_stack_[(9) - (3)].m_pAssign), (yysemantic_stack_[(9) - (5)].m_pExpr), (yysemantic_stack_[(9) - (7)].m_pAssign), (yysemantic_stack_[(9) - (9)].m_pStatement) ); }
    break;

  case 51:

/* Line 678 of lalr1.cc  */
#line 212 "Parser.yy"
    { (yyval.m_pStatement) = new WhileStatement( (yylocation_stack_[(5) - (1)]), (yysemantic_stack_[(5) - (3)].m_pExpr), (yysemantic_stack_[(5) - (5)].m_pStatement) ); }
    break;

  case 52:

/* Line 678 of lalr1.cc  */
#line 213 "Parser.yy"
    { (yyval.m_pStatement) = new SwitchStatement( (yylocation_stack_[(7) - (1)]), (yysemantic_stack_[(7) - (3)].m_pExpr), (yysemantic_stack_[(7) - (6)].m_pStateList) ); }
    break;

  case 53:

/* Line 678 of lalr1.cc  */
#line 214 "Parser.yy"
    { (yyval.m_pStatement) = new BlockStatement( (yylocation_stack_[(1) - (1)]), (yysemantic_stack_[(1) - (1)].m_pBlock) ); }
    break;

  case 54:

/* Line 678 of lalr1.cc  */
#line 217 "Parser.yy"
    { (yyval.m_pAssign) = new Assign( (yylocation_stack_[(3) - (1)]), '=', (yysemantic_stack_[(3) - (1)].m_pVal), (yysemantic_stack_[(3) - (3)].m_pExpr) ); }
    break;

  case 55:

/* Line 678 of lalr1.cc  */
#line 218 "Parser.yy"
    { (yyval.m_pAssign) = new Assign( (yylocation_stack_[(3) - (1)]), '+', (yysemantic_stack_[(3) - (1)].m_pVal), (yysemantic_stack_[(3) - (3)].m_pExpr) ); }
    break;

  case 56:

/* Line 678 of lalr1.cc  */
#line 219 "Parser.yy"
    { (yyval.m_pAssign) = new Assign( (yylocation_stack_[(3) - (1)]), '-', (yysemantic_stack_[(3) - (1)].m_pVal), (yysemantic_stack_[(3) - (3)].m_pExpr) ); }
    break;

  case 57:

/* Line 678 of lalr1.cc  */
#line 220 "Parser.yy"
    { (yyval.m_pAssign) = new Assign( (yylocation_stack_[(3) - (1)]), '*', (yysemantic_stack_[(3) - (1)].m_pVal), (yysemantic_stack_[(3) - (3)].m_pExpr) ); }
    break;

  case 58:

/* Line 678 of lalr1.cc  */
#line 221 "Parser.yy"
    { (yyval.m_pAssign) = new Assign( (yylocation_stack_[(3) - (1)]), '/', (yysemantic_stack_[(3) - (1)].m_pVal), (yysemantic_stack_[(3) - (3)].m_pExpr) ); }
    break;

  case 59:

/* Line 678 of lalr1.cc  */
#line 222 "Parser.yy"
    { (yyval.m_pAssign) = new Assign( (yylocation_stack_[(3) - (1)]), '%', (yysemantic_stack_[(3) - (1)].m_pVal), (yysemantic_stack_[(3) - (3)].m_pExpr) ); }
    break;

  case 60:

/* Line 678 of lalr1.cc  */
#line 225 "Parser.yy"
    { (yyval.m_pExpr) = Node::MakeNode( compiler, (yylocation_stack_[(3) - (2)]), OP_LOGAND, (yysemantic_stack_[(3) - (1)].m_pExpr), (yysemantic_stack_[(3) - (3)].m_pExpr) ); }
    break;

  case 61:

/* Line 678 of lalr1.cc  */
#line 226 "Parser.yy"
    { (yyval.m_pExpr) = Node::MakeNode( compiler, (yylocation_stack_[(3) - (2)]), OP_LOGOR, (yysemantic_stack_[(3) - (1)].m_pExpr), (yysemantic_stack_[(3) - (3)].m_pExpr) ); }
    break;

  case 62:

/* Line 678 of lalr1.cc  */
#line 227 "Parser.yy"
    { (yyval.m_pExpr) = Node::MakeNode( compiler, (yylocation_stack_[(3) - (2)]), OP_EQ, (yysemantic_stack_[(3) - (1)].m_pExpr), (yysemantic_stack_[(3) - (3)].m_pExpr) ); }
    break;

  case 63:

/* Line 678 of lalr1.cc  */
#line 228 "Parser.yy"
    { (yyval.m_pExpr) = Node::MakeNode( compiler, (yylocation_stack_[(3) - (2)]), OP_NE, (yysemantic_stack_[(3) - (1)].m_pExpr), (yysemantic_stack_[(3) - (3)].m_pExpr) ); }
    break;

  case 64:

/* Line 678 of lalr1.cc  */
#line 229 "Parser.yy"
    { (yyval.m_pExpr) = Node::MakeNode( compiler, (yylocation_stack_[(3) - (2)]), OP_GT, (yysemantic_stack_[(3) - (1)].m_pExpr), (yysemantic_stack_[(3) - (3)].m_pExpr) ); }
    break;

  case 65:

/* Line 678 of lalr1.cc  */
#line 230 "Parser.yy"
    { (yyval.m_pExpr) = Node::MakeNode( compiler, (yylocation_stack_[(3) - (2)]), OP_GE, (yysemantic_stack_[(3) - (1)].m_pExpr), (yysemantic_stack_[(3) - (3)].m_pExpr) ); }
    break;

  case 66:

/* Line 678 of lalr1.cc  */
#line 231 "Parser.yy"
    { (yyval.m_pExpr) = Node::MakeNode( compiler, (yylocation_stack_[(3) - (2)]), OP_LT, (yysemantic_stack_[(3) - (1)].m_pExpr), (yysemantic_stack_[(3) - (3)].m_pExpr) ); }
    break;

  case 67:

/* Line 678 of lalr1.cc  */
#line 232 "Parser.yy"
    { (yyval.m_pExpr) = Node::MakeNode( compiler, (yylocation_stack_[(3) - (2)]), OP_LE, (yysemantic_stack_[(3) - (1)].m_pExpr), (yysemantic_stack_[(3) - (3)].m_pExpr) ); }
    break;

  case 68:

/* Line 678 of lalr1.cc  */
#line 233 "Parser.yy"
    { (yyval.m_pExpr) = Node::MakeNode( compiler, (yylocation_stack_[(3) - (2)]), OP_AND, (yysemantic_stack_[(3) - (1)].m_pExpr), (yysemantic_stack_[(3) - (3)].m_pExpr) ); }
    break;

  case 69:

/* Line 678 of lalr1.cc  */
#line 234 "Parser.yy"
    { (yyval.m_pExpr) = Node::MakeNode( compiler, (yylocation_stack_[(3) - (2)]), OP_OR, (yysemantic_stack_[(3) - (1)].m_pExpr), (yysemantic_stack_[(3) - (3)].m_pExpr) ); }
    break;

  case 70:

/* Line 678 of lalr1.cc  */
#line 235 "Parser.yy"
    { (yyval.m_pExpr) = Node::MakeNode( compiler, (yylocation_stack_[(3) - (2)]), OP_LSHIFT, (yysemantic_stack_[(3) - (1)].m_pExpr), (yysemantic_stack_[(3) - (3)].m_pExpr) ); }
    break;

  case 71:

/* Line 678 of lalr1.cc  */
#line 236 "Parser.yy"
    { (yyval.m_pExpr) = Node::MakeNode( compiler, (yylocation_stack_[(3) - (2)]), OP_RSHIFT, (yysemantic_stack_[(3) - (1)].m_pExpr), (yysemantic_stack_[(3) - (3)].m_pExpr) ); }
    break;

  case 72:

/* Line 678 of lalr1.cc  */
#line 237 "Parser.yy"
    { (yyval.m_pExpr) = Node::MakeNode( compiler, (yylocation_stack_[(3) - (2)]), OP_MINUS, (yysemantic_stack_[(3) - (1)].m_pExpr), (yysemantic_stack_[(3) - (3)].m_pExpr) ); }
    break;

  case 73:

/* Line 678 of lalr1.cc  */
#line 238 "Parser.yy"
    { (yyval.m_pExpr) = Node::MakeNode( compiler, (yylocation_stack_[(3) - (2)]), OP_PLUS, (yysemantic_stack_[(3) - (1)].m_pExpr), (yysemantic_stack_[(3) - (3)].m_pExpr) ); }
    break;

  case 74:

/* Line 678 of lalr1.cc  */
#line 239 "Parser.yy"
    { (yyval.m_pExpr) = Node::MakeNode( compiler, (yylocation_stack_[(3) - (2)]), OP_TIMES, (yysemantic_stack_[(3) - (1)].m_pExpr), (yysemantic_stack_[(3) - (3)].m_pExpr) ); }
    break;

  case 75:

/* Line 678 of lalr1.cc  */
#line 240 "Parser.yy"
    { (yyval.m_pExpr) = Node::MakeNode( compiler, (yylocation_stack_[(3) - (2)]), OP_DIVIDE, (yysemantic_stack_[(3) - (1)].m_pExpr), (yysemantic_stack_[(3) - (3)].m_pExpr) ); }
    break;

  case 76:

/* Line 678 of lalr1.cc  */
#line 241 "Parser.yy"
    { (yyval.m_pExpr) = Node::MakeNode( compiler, (yylocation_stack_[(3) - (2)]), OP_MOD, (yysemantic_stack_[(3) - (1)].m_pExpr), (yysemantic_stack_[(3) - (3)].m_pExpr) ); }
    break;

  case 77:

/* Line 678 of lalr1.cc  */
#line 242 "Parser.yy"
    { (yyval.m_pExpr) = Node::MakeNode( compiler, (yylocation_stack_[(2) - (2)]), OP_NEG, (yysemantic_stack_[(2) - (2)].m_pExpr) ); }
    break;

  case 78:

/* Line 678 of lalr1.cc  */
#line 243 "Parser.yy"
    { (yyval.m_pExpr) = (yysemantic_stack_[(3) - (2)].m_pExpr); }
    break;

  case 79:

/* Line 678 of lalr1.cc  */
#line 244 "Parser.yy"
    { (yyval.m_pExpr) = (yysemantic_stack_[(1) - (1)].m_pVal); }
    break;

  case 80:

/* Line 678 of lalr1.cc  */
#line 245 "Parser.yy"
    { (yyval.m_pExpr) = new Node( (yylocation_stack_[(1) - (1)]), OP_INT_CONST, (yysemantic_stack_[(1) - (1)].m_IntVal) ); }
    break;

  case 81:

/* Line 678 of lalr1.cc  */
#line 246 "Parser.yy"
    { (yyval.m_pExpr) = new Node( (yylocation_stack_[(1) - (1)]), OP_STRING, (yysemantic_stack_[(1) - (1)].m_pStrVal) ); }
    break;

  case 82:

/* Line 678 of lalr1.cc  */
#line 247 "Parser.yy"
    { (yyval.m_pExpr) = new Node( (yylocation_stack_[(1) - (1)]), OP_FLOAT_CONST, (yysemantic_stack_[(1) - (1)].m_FloatVal) ); }
    break;

  case 83:

/* Line 678 of lalr1.cc  */
#line 248 "Parser.yy"
    { (yyval.m_pExpr) = new Node( (yylocation_stack_[(1) - (1)]), OP_GU_CONST, (yysemantic_stack_[(1) - (1)].m_GUVal ) ); }
    break;

  case 84:

/* Line 678 of lalr1.cc  */
#line 249 "Parser.yy"
    { (yyval.m_pExpr) = new FunctionNode( (yylocation_stack_[(4) - (1)]), (yysemantic_stack_[(4) - (1)].m_pStrVal), (yysemantic_stack_[(4) - (3)].m_pArgs) ); }
    break;

  case 85:

/* Line 678 of lalr1.cc  */
#line 250 "Parser.yy"
    { (yyval.m_pExpr) = new FunctionNode( (yylocation_stack_[(3) - (1)]), (yysemantic_stack_[(3) - (1)].m_pStrVal), NULL ); }
    break;

  case 86:

/* Line 678 of lalr1.cc  */
#line 253 "Parser.yy"
    { (yyval.m_pVal) = new ValueNode( (yylocation_stack_[(1) - (1)]), (yysemantic_stack_[(1) - (1)].m_pStrVal) ); }
    break;

  case 87:

/* Line 678 of lalr1.cc  */
#line 254 "Parser.yy"
    { (yyval.m_pVal) = new ValueNode( (yylocation_stack_[(4) - (1)]), (yysemantic_stack_[(4) - (1)].m_pStrVal), (yysemantic_stack_[(4) - (3)].m_pExpr) ); }
    break;

  case 88:

/* Line 678 of lalr1.cc  */
#line 257 "Parser.yy"
    { (yyval.m_pArgs) = new Args( (yysemantic_stack_[(1) - (1)].m_pExpr) ); }
    break;

  case 89:

/* Line 678 of lalr1.cc  */
#line 258 "Parser.yy"
    { (yyval.m_pArgs) = (yysemantic_stack_[(3) - (1)].m_pArgs)->Add( (yysemantic_stack_[(3) - (3)].m_pExpr) ); }
    break;



/* Line 678 of lalr1.cc  */
#line 1151 "Parser.cc"
	default:
          break;
      }
    YY_SYMBOL_PRINT ("-> $$ =", yyr1_[yyn], &yyval, &yyloc);

    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();

    yysemantic_stack_.push (yyval);
    yylocation_stack_.push (yyloc);

    /* Shift the result of the reduction.  */
    yyn = yyr1_[yyn];
    yystate = yypgoto_[yyn - yyntokens_] + yystate_stack_[0];
    if (0 <= yystate && yystate <= yylast_
	&& yycheck_[yystate] == yystate_stack_[0])
      yystate = yytable_[yystate];
    else
      yystate = yydefgoto_[yyn - yyntokens_];
    goto yynewstate;

  /*------------------------------------.
  | yyerrlab -- here on detecting error |
  `------------------------------------*/
  yyerrlab:
    /* If not already recovering from an error, report this error.  */
    if (!yyerrstatus_)
      {
	++yynerrs_;
	error (yylloc, yysyntax_error_ (yystate, yytoken));
      }

    yyerror_range[0] = yylloc;
    if (yyerrstatus_ == 3)
      {
	/* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

	if (yychar <= yyeof_)
	  {
	  /* Return failure if at end of input.  */
	  if (yychar == yyeof_)
	    YYABORT;
	  }
	else
	  {
	    yydestruct_ ("Error: discarding", yytoken, &yylval, &yylloc);
	    yychar = yyempty_;
	  }
      }

    /* Else will try to reuse lookahead token after shifting the error
       token.  */
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;

    yyerror_range[0] = yylocation_stack_[yylen - 1];
    /* Do not reclaim the symbols of the rule which action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    yystate = yystate_stack_[0];
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;	/* Each real token shifted decrements this.  */

    for (;;)
      {
	yyn = yypact_[yystate];
	if (yyn != yypact_ninf_)
	{
	  yyn += yyterror_;
	  if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
	    {
	      yyn = yytable_[yyn];
	      if (0 < yyn)
		break;
	    }
	}

	/* Pop the current state because it cannot handle the error token.  */
	if (yystate_stack_.height () == 1)
	YYABORT;

	yyerror_range[0] = yylocation_stack_[0];
	yydestruct_ ("Error: popping",
		     yystos_[yystate],
		     &yysemantic_stack_[0], &yylocation_stack_[0]);
	yypop_ ();
	yystate = yystate_stack_[0];
	YY_STACK_PRINT ();
      }

    yyerror_range[1] = yylloc;
    // Using YYLLOC is tempting, but would change the location of
    // the lookahead.  YYLOC is available though.
    YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yyloc);

    /* Shift the error token.  */
    YY_SYMBOL_PRINT ("Shifting", yystos_[yyn],
		     &yysemantic_stack_[0], &yylocation_stack_[0]);

    yystate = yyn;
    goto yynewstate;

    /* Accept.  */
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    /* Abort.  */
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (yychar != yyempty_)
      yydestruct_ ("Cleanup: discarding lookahead", yytoken, &yylval, &yylloc);

    /* Do not reclaim the symbols of the rule which action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (yystate_stack_.height () != 1)
      {
	yydestruct_ ("Cleanup: popping",
		   yystos_[yystate_stack_[0]],
		   &yysemantic_stack_[0],
		   &yylocation_stack_[0]);
	yypop_ ();
      }

    return yyresult;
  }

  // Generate an error message.
  std::string
  Parser::yysyntax_error_ (int yystate, int tok)
  {
    std::string res;
    YYUSE (yystate);
#if YYERROR_VERBOSE
    int yyn = yypact_[yystate];
    if (yypact_ninf_ < yyn && yyn <= yylast_)
      {
	/* Start YYX at -YYN if negative to avoid negative indexes in
	   YYCHECK.  */
	int yyxbegin = yyn < 0 ? -yyn : 0;

	/* Stay within bounds of both yycheck and yytname.  */
	int yychecklim = yylast_ - yyn + 1;
	int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
	int count = 0;
	for (int x = yyxbegin; x < yyxend; ++x)
	  if (yycheck_[x + yyn] == x && x != yyterror_)
	    ++count;

	// FIXME: This method of building the message is not compatible
	// with internationalization.  It should work like yacc.c does it.
	// That is, first build a string that looks like this:
	// "syntax error, unexpected %s or %s or %s"
	// Then, invoke YY_ on this string.
	// Finally, use the string as a format to output
	// yytname_[tok], etc.
	// Until this gets fixed, this message appears in English only.
	res = "syntax error, unexpected ";
	res += yytnamerr_ (yytname_[tok]);
	if (count < 5)
	  {
	    count = 0;
	    for (int x = yyxbegin; x < yyxend; ++x)
	      if (yycheck_[x + yyn] == x && x != yyterror_)
		{
		  res += (!count++) ? ", expecting " : " or ";
		  res += yytnamerr_ (yytname_[x]);
		}
	  }
      }
    else
#endif
      res = YY_("syntax error");
    return res;
  }


  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
  const signed char Parser::yypact_ninf_ = -119;
  const short int
  Parser::yypact_[] =
  {
       224,   -41,  -119,  -119,  -119,    52,  -119,   127,  -119,  -119,
    -119,    56,  -119,    44,  -119,  -119,   -40,    58,  -119,    99,
     277,   110,  -119,    82,   -43,   -29,  -119,    22,   -38,    54,
    -119,    39,  -119,  -119,  -119,   110,   110,   181,  -119,    19,
    -119,  -119,   196,  -119,   -31,   196,    42,   131,  -119,  -119,
     -18,    18,  -119,   198,   110,   110,   110,   110,   110,   110,
     110,   110,   110,   110,   110,   110,   110,   110,   110,   110,
     110,  -119,    82,    49,   196,  -119,  -119,  -119,    86,    91,
    -119,  -119,  -119,   353,    64,  -119,   388,   397,   406,   406,
     406,   406,    40,    40,   406,   406,   228,   228,   124,   124,
    -119,  -119,  -119,    89,   102,   107,   122,   133,   134,   110,
     128,   137,   138,  -119,  -119,   135,    49,  -119,   140,    12,
      82,  -119,   136,  -119,   110,  -119,    92,   110,   110,    82,
     110,   162,  -119,  -119,  -119,   304,  -119,  -119,  -119,   110,
     110,   110,   110,   110,   110,   104,  -119,   353,   143,    78,
     238,   251,   169,   291,  -119,  -119,   353,   353,   353,   353,
     353,   353,  -119,  -119,   184,    49,    49,   110,   193,  -119,
     210,  -119,   342,    49,    49,    82,   220,  -119,   235,  -119,
      49,  -119
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned char
  Parser::yydefact_[] =
  {
         0,     0,    26,    27,    28,     0,    29,     0,     2,     6,
       5,     0,     4,     0,     1,     3,    86,     0,    12,     0,
       0,     0,     7,     0,     0,     0,    14,    16,     0,     0,
      80,    86,    81,    82,    83,     0,     0,     0,    79,    86,
      13,    10,    31,    24,     0,     0,    18,    17,     8,    22,
       0,     0,    77,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    87,     0,    33,    32,    11,    25,    15,     0,    19,
       9,    23,    85,    88,     0,    78,    61,    60,    62,    63,
      65,    67,    70,    71,    64,    66,    68,    69,    73,    72,
      74,    75,    76,     0,    86,     0,     0,     0,     0,     0,
       0,     0,     0,    39,    53,     0,    34,    37,     0,     0,
       0,    20,     0,    84,     0,    35,     0,     0,     0,     0,
       0,     0,    44,    45,    46,     0,    30,    38,    40,     0,
       0,     0,     0,     0,     0,     0,    21,    89,     0,     0,
       0,     0,     0,     0,    43,    47,    55,    56,    57,    58,
      59,    54,    36,    42,     0,     0,     0,     0,     0,    41,
      48,    51,     0,    33,     0,     0,     0,    49,     0,    52,
       0,    50
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  Parser::yypgoto_[] =
  {
      -119,  -119,   276,  -119,   -69,   264,   250,  -119,    10,    43,
    -119,   123,  -119,  -119,  -111,  -118,   -20,   -11,   171
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const signed char
  Parser::yydefgoto_[] =
  {
        -1,     7,     8,     9,    17,    25,    26,    10,    27,   114,
      73,   115,    74,   116,   117,   118,    83,    38,    84
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char Parser::yytable_ninf_ = -1;
  const short int
  Parser::yytable_[] =
  {
        18,    37,    41,   103,    12,   137,    20,    48,    42,    21,
      11,   152,    40,    42,    75,    52,    53,    11,    44,    45,
      42,    30,    31,    32,    33,    34,    46,    80,   139,   140,
     141,   142,   143,    42,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   145,    72,   104,   170,   171,    13,   178,    35,    47,
      16,    18,   119,   177,    36,    82,   144,    43,    21,   181,
     105,    49,   106,   107,   108,   109,   110,   111,   112,    66,
      67,    68,    69,    70,   120,    51,    39,    76,    21,   131,
      19,    78,   135,    81,   113,    30,    31,    32,    33,    34,
      42,    50,    45,    22,   147,   119,    23,   150,   151,    18,
     153,   123,   124,    30,    31,    32,    33,    34,   119,   156,
     157,   158,   159,   160,   161,   164,   124,    14,     1,     2,
       3,     4,    35,     6,   125,    79,   121,    23,    36,   148,
     122,    30,    31,    32,    33,    34,    24,   172,   126,   162,
      35,    21,    23,   127,   119,   119,    36,     2,     3,     4,
       5,     6,   119,   119,   119,    68,    69,    70,   128,   119,
      54,    55,    56,    57,    58,    59,    60,    61,    35,   129,
     130,   132,   133,   134,    36,   138,   146,   136,   163,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    54,    55,    56,    57,
      58,    59,    60,    61,   167,   154,    62,    63,    64,    65,
      66,    67,    68,    69,    70,     1,     2,     3,     4,   169,
       6,    71,   174,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    60,    61,   173,    85,    54,    55,    56,    57,
      58,    59,    60,    61,     2,     3,     4,     5,     6,    54,
      55,    56,    57,    58,    59,    60,    61,    66,    67,    68,
      69,    70,   179,    62,    63,    64,    65,    66,    67,    68,
      69,    70,   180,    15,    29,   165,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    77,   176,   149,   166,    54,
      55,    56,    57,    58,    59,    60,    61,     2,     3,     4,
       0,     6,    54,    55,    56,    57,    58,    59,    60,    61,
       0,     0,     0,     0,    28,     0,    62,    63,    64,    65,
      66,    67,    68,    69,    70,     0,     0,     0,   168,    62,
      63,    64,    65,    66,    67,    68,    69,    70,     0,   155,
      54,    55,    56,    57,    58,    59,    60,    61,     0,     0,
       0,    54,    55,    56,    57,    58,    59,    60,    61,     0,
       0,     0,     0,     0,     0,     0,     0,    62,    63,    64,
      65,    66,    67,    68,    69,    70,     0,   175,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    55,    56,    57,
      58,    59,    60,    61,     0,     0,     0,    56,    57,    58,
      59,    60,    61,     0,     0,     0,    -1,    -1,    -1,    -1,
      60,    61,     0,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    -1,    -1,    64,    65,    66,    67,    68,    69,    70
  };

  /* YYCHECK.  */
  const short int
  Parser::yycheck_[] =
  {
        11,    21,    45,    72,    45,   116,    46,    45,    51,    49,
       0,   129,    23,    51,    45,    35,    36,     7,    47,    48,
      51,     3,     4,     5,     6,     7,     4,    45,    16,    17,
      18,    19,    20,    51,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,   120,    42,     4,   165,   166,     4,   175,    40,    37,
       4,    72,    73,   174,    46,    47,    54,    24,    49,   180,
      21,    28,    23,    24,    25,    26,    27,    28,    29,    39,
      40,    41,    42,    43,    74,    46,     4,    44,    49,   109,
      46,    49,   112,    50,    45,     3,     4,     5,     6,     7,
      51,    47,    48,    45,   124,   116,    48,   127,   128,   120,
     130,    47,    48,     3,     4,     5,     6,     7,   129,   139,
     140,   141,   142,   143,   144,    47,    48,     0,     1,    30,
      31,    32,    40,    34,    45,     4,    50,    48,    46,    47,
      49,     3,     4,     5,     6,     7,    47,   167,    46,    45,
      40,    49,    48,    46,   165,   166,    46,    30,    31,    32,
      33,    34,   173,   174,   175,    41,    42,    43,    46,   180,
       8,     9,    10,    11,    12,    13,    14,    15,    40,    46,
      46,    53,    45,    45,    46,    45,    50,    52,    45,     8,
       9,    10,    11,    12,    13,    14,    15,    35,    36,    37,
      38,    39,    40,    41,    42,    43,     8,     9,    10,    11,
      12,    13,    14,    15,    45,    53,    35,    36,    37,    38,
      39,    40,    41,    42,    43,     1,    30,    31,    32,    45,
      34,    50,    22,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    14,    15,    51,    47,     8,     9,    10,    11,
      12,    13,    14,    15,    30,    31,    32,    33,    34,     8,
       9,    10,    11,    12,    13,    14,    15,    39,    40,    41,
      42,    43,    52,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    47,     7,    20,    47,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    45,   173,   126,    47,     8,
       9,    10,    11,    12,    13,    14,    15,    30,    31,    32,
      -1,    34,     8,     9,    10,    11,    12,    13,    14,    15,
      -1,    -1,    -1,    -1,    47,    -1,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    -1,    -1,    -1,    47,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    -1,    45,
       8,     9,    10,    11,    12,    13,    14,    15,    -1,    -1,
      -1,     8,     9,    10,    11,    12,    13,    14,    15,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    -1,    45,    35,    36,
      37,    38,    39,    40,    41,    42,    43,     9,    10,    11,
      12,    13,    14,    15,    -1,    -1,    -1,    10,    11,    12,
      13,    14,    15,    -1,    -1,    -1,    10,    11,    12,    13,
      14,    15,    -1,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    35,    36,    37,    38,    39,    40,    41,    42,    43
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  Parser::yystos_[] =
  {
         0,     1,    30,    31,    32,    33,    34,    56,    57,    58,
      62,    63,    45,     4,     0,    57,     4,    59,    72,    46,
      46,    49,    45,    48,    47,    60,    61,    63,    47,    60,
       3,     4,     5,     6,     7,    40,    46,    71,    72,     4,
      72,    45,    51,    64,    47,    48,     4,    37,    45,    64,
      47,    46,    71,    71,     8,     9,    10,    11,    12,    13,
      14,    15,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    50,    63,    65,    67,    45,    64,    61,    49,     4,
      45,    64,    47,    71,    73,    47,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    59,     4,    21,    23,    24,    25,    26,
      27,    28,    29,    45,    64,    66,    68,    69,    70,    72,
      63,    50,    49,    47,    48,    45,    46,    46,    46,    46,
      46,    71,    53,    45,    45,    71,    52,    69,    45,    16,
      17,    18,    19,    20,    54,    59,    50,    71,    47,    73,
      71,    71,    70,    71,    53,    45,    71,    71,    71,    71,
      71,    71,    45,    45,    47,    47,    47,    45,    47,    45,
      69,    69,    71,    51,    22,    45,    66,    69,    70,    52,
      47,    69
  };

#if YYDEBUG
  /* TOKEN_NUMBER_[YYLEX-NUM] -- Internal symbol number corresponding
     to YYLEX-NUM.  */
  const unsigned short int
  Parser::yytoken_number_[] =
  {
         0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,    62,    60,    38,   124,    43,
      45,    42,    47,    37,   290,    59,    40,    41,    44,    91,
      93,   123,   125,    58,    61
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned char
  Parser::yyr1_[] =
  {
         0,    55,    56,    56,    57,    57,    57,    58,    58,    58,
      58,    58,    59,    59,    60,    60,    61,    61,    61,    61,
      61,    61,    62,    62,    62,    62,    63,    63,    63,    63,
      64,    65,    65,    66,    66,    67,    67,    68,    68,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    70,    70,    70,    70,    70,    70,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    72,    72,    73,    73
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  Parser::yyr2_[] =
  {
         0,     2,     1,     2,     2,     1,     1,     3,     5,     6,
       5,     6,     1,     3,     1,     3,     1,     2,     2,     3,
       4,     5,     5,     6,     5,     6,     1,     1,     1,     1,
       4,     0,     1,     0,     1,     3,     4,     1,     2,     1,
       2,     5,     4,     3,     2,     2,     2,     3,     5,     7,
       9,     5,     7,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     3,     1,
       1,     1,     1,     1,     4,     3,     1,     4,     1,     3
  };

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
  /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
     First, the terminals, then, starting at \a yyntokens_, nonterminals.  */
  const char*
  const Parser::yytname_[] =
  {
    "\"end of file\"", "error", "$undefined", "\"ival\"", "\"identifier\"",
  "\"sval\"", "\"fval\"", "\"gval\"", "\"||\"", "\"&&\"", "\"==\"",
  "\"!=\"", "\">=\"", "\"<=\"", "\"<<\"", "\">>\"", "\"+=\"", "\"-=\"",
  "\"*=\"", "\"/=\"", "\"%=\"", "\"if\"", "\"else\"", "\"while\"",
  "\"for\"", "\"switch\"", "\"case\"", "\"default\"", "\"break\"",
  "\"return\"", "\"int\"", "\"string\"", "\"float\"", "\"void\"", "\"gu\"",
  "'>'", "'<'", "'&'", "'|'", "'+'", "'-'", "'*'", "'/'", "'%'", "NEG",
  "';'", "'('", "')'", "','", "'['", "']'", "'{'", "'}'", "':'", "'='",
  "$accept", "unit", "sentence", "declaration", "vallist", "arglist",
  "argdef", "function", "type", "block", "decllist", "statelist", "decls",
  "states", "statement", "assign", "expr", "value", "args", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const Parser::rhs_number_type
  Parser::yyrhs_[] =
  {
        56,     0,    -1,    57,    -1,    56,    57,    -1,     1,    45,
      -1,    62,    -1,    58,    -1,    63,    59,    45,    -1,    63,
       4,    46,    47,    45,    -1,    63,     4,    46,    60,    47,
      45,    -1,    33,     4,    46,    47,    45,    -1,    33,     4,
      46,    60,    47,    45,    -1,    72,    -1,    59,    48,    72,
      -1,    61,    -1,    60,    48,    61,    -1,    63,    -1,    63,
      37,    -1,    63,     4,    -1,    63,    37,     4,    -1,    63,
       4,    49,    50,    -1,    63,    37,     4,    49,    50,    -1,
      63,     4,    46,    47,    64,    -1,    63,     4,    46,    60,
      47,    64,    -1,    33,     4,    46,    47,    64,    -1,    33,
       4,    46,    60,    47,    64,    -1,    30,    -1,    31,    -1,
      32,    -1,    34,    -1,    51,    65,    66,    52,    -1,    -1,
      67,    -1,    -1,    68,    -1,    63,    59,    45,    -1,    67,
      63,    59,    45,    -1,    69,    -1,    68,    69,    -1,    45,
      -1,    70,    45,    -1,     4,    46,    73,    47,    45,    -1,
       4,    46,    47,    45,    -1,    26,    71,    53,    -1,    27,
      53,    -1,    28,    45,    -1,    29,    45,    -1,    29,    71,
      45,    -1,    21,    46,    71,    47,    69,    -1,    21,    46,
      71,    47,    69,    22,    69,    -1,    24,    46,    70,    45,
      71,    45,    70,    47,    69,    -1,    23,    46,    71,    47,
      69,    -1,    25,    46,    71,    47,    51,    66,    52,    -1,
      64,    -1,    72,    54,    71,    -1,    72,    16,    71,    -1,
      72,    17,    71,    -1,    72,    18,    71,    -1,    72,    19,
      71,    -1,    72,    20,    71,    -1,    71,     9,    71,    -1,
      71,     8,    71,    -1,    71,    10,    71,    -1,    71,    11,
      71,    -1,    71,    35,    71,    -1,    71,    12,    71,    -1,
      71,    36,    71,    -1,    71,    13,    71,    -1,    71,    37,
      71,    -1,    71,    38,    71,    -1,    71,    14,    71,    -1,
      71,    15,    71,    -1,    71,    40,    71,    -1,    71,    39,
      71,    -1,    71,    41,    71,    -1,    71,    42,    71,    -1,
      71,    43,    71,    -1,    40,    71,    -1,    46,    71,    47,
      -1,    72,    -1,     3,    -1,     5,    -1,     6,    -1,     7,
      -1,     4,    46,    73,    47,    -1,     4,    46,    47,    -1,
       4,    -1,     4,    49,    71,    50,    -1,    71,    -1,    73,
      48,    71,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  Parser::yyprhs_[] =
  {
         0,     0,     3,     5,     8,    11,    13,    15,    19,    25,
      32,    38,    45,    47,    51,    53,    57,    59,    62,    65,
      69,    74,    80,    86,    93,    99,   106,   108,   110,   112,
     114,   119,   120,   122,   123,   125,   129,   134,   136,   139,
     141,   144,   150,   155,   159,   162,   165,   168,   172,   178,
     186,   196,   202,   210,   212,   216,   220,   224,   228,   232,
     236,   240,   244,   248,   252,   256,   260,   264,   268,   272,
     276,   280,   284,   288,   292,   296,   300,   304,   307,   311,
     313,   315,   317,   319,   321,   326,   330,   332,   337,   339
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  Parser::yyrline_[] =
  {
         0,   137,   137,   138,   141,   142,   143,   146,   147,   148,
     149,   150,   153,   154,   157,   158,   161,   162,   163,   164,
     165,   166,   169,   170,   171,   172,   175,   176,   177,   178,
     181,   184,   185,   188,   189,   192,   193,   196,   197,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   217,   218,   219,   220,   221,   222,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   253,   254,   257,   258
  };

  // Print the state stack on the debug stream.
  void
  Parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (state_stack_type::const_iterator i = yystate_stack_.begin ();
	 i != yystate_stack_.end (); ++i)
      *yycdebug_ << ' ' << *i;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  Parser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    /* Print the symbols being reduced, and their result.  */
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
	       << " (line " << yylno << "):" << std::endl;
    /* The symbols being reduced.  */
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
		       yyrhs_[yyprhs_[yyrule] + yyi],
		       &(yysemantic_stack_[(yynrhs) - (yyi + 1)]),
		       &(yylocation_stack_[(yynrhs) - (yyi + 1)]));
  }
#endif // YYDEBUG

  /* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
  Parser::token_number_type
  Parser::yytranslate_ (int t)
  {
    static
    const token_number_type
    translate_table[] =
    {
           0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    43,    37,     2,
      46,    47,    41,    39,    48,    40,     2,    42,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    53,    45,
      36,    54,    35,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    49,     2,    50,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    51,    38,    52,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      44
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int Parser::yyeof_ = 0;
  const int Parser::yylast_ = 449;
  const int Parser::yynnts_ = 19;
  const int Parser::yyempty_ = -2;
  const int Parser::yyfinal_ = 14;
  const int Parser::yyterror_ = 1;
  const int Parser::yyerrcode_ = 256;
  const int Parser::yyntokens_ = 55;

  const unsigned int Parser::yyuser_token_number_max_ = 290;
  const Parser::token_number_type Parser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // yy

/* Line 1054 of lalr1.cc  */
#line 1786 "Parser.cc"


/* Line 1056 of lalr1.cc  */
#line 260 "Parser.yy"


void yy::Parser::error( const yy::Parser::location_type& l, const std::string& m )
{
	compiler.error( l, m );
}

