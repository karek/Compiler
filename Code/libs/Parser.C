/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 2 "LatteCPP.y" /* yacc.c:339  */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include "Absyn.H"
typedef struct yy_buffer_state *YY_BUFFER_STATE;
int yyparse(void);
int yylex(void);
YY_BUFFER_STATE yy_scan_string(const char *str);
void yy_delete_buffer(YY_BUFFER_STATE buf);
int yy_mylinenumber;
int initialize_lexer(FILE * inp);
int yywrap(void)
{
  return 1;
}
void yyerror(const char *str)
{
  extern char *yytext;
  fprintf(stderr,"error: line %d: %s at %s\n", 
    yy_mylinenumber, str, yytext);
}



static Program* YY_RESULT_Program_ = 0;
Program* pProgram(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Program_;
  }
}
Program* pProgram(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Program_;
  }
}

static TopDef* YY_RESULT_TopDef_ = 0;
TopDef* pTopDef(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_TopDef_;
  }
}
TopDef* pTopDef(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_TopDef_;
  }
}

static ListTopDef* YY_RESULT_ListTopDef_ = 0;
ListTopDef* pListTopDef(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListTopDef_;
  }
}
ListTopDef* pListTopDef(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListTopDef_;
  }
}

static Arg* YY_RESULT_Arg_ = 0;
Arg* pArg(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Arg_;
  }
}
Arg* pArg(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Arg_;
  }
}

static ListArg* YY_RESULT_ListArg_ = 0;
ListArg* pListArg(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListArg_;
  }
}
ListArg* pListArg(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListArg_;
  }
}

static ClsElems* YY_RESULT_ClsElems_ = 0;
ClsElems* pClsElems(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ClsElems_;
  }
}
ClsElems* pClsElems(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ClsElems_;
  }
}

static ListClsElems* YY_RESULT_ListClsElems_ = 0;
ListClsElems* pListClsElems(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListClsElems_;
  }
}
ListClsElems* pListClsElems(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListClsElems_;
  }
}

static Block* YY_RESULT_Block_ = 0;
Block* pBlock(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Block_;
  }
}
Block* pBlock(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Block_;
  }
}

static ListStmt* YY_RESULT_ListStmt_ = 0;
ListStmt* pListStmt(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListStmt_;
  }
}
ListStmt* pListStmt(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListStmt_;
  }
}

static Stmt* YY_RESULT_Stmt_ = 0;
Stmt* pStmt(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Stmt_;
  }
}
Stmt* pStmt(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Stmt_;
  }
}

static Item* YY_RESULT_Item_ = 0;
Item* pItem(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Item_;
  }
}
Item* pItem(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Item_;
  }
}

static ListItem* YY_RESULT_ListItem_ = 0;
ListItem* pListItem(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListItem_;
  }
}
ListItem* pListItem(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListItem_;
  }
}

static BasicType* YY_RESULT_BasicType_ = 0;
BasicType* pBasicType(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_BasicType_;
  }
}
BasicType* pBasicType(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_BasicType_;
  }
}

static TypeName* YY_RESULT_TypeName_ = 0;
TypeName* pTypeName(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_TypeName_;
  }
}
TypeName* pTypeName(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_TypeName_;
  }
}

static Type* YY_RESULT_Type_ = 0;
Type* pType(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Type_;
  }
}
Type* pType(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Type_;
  }
}

static ListType* YY_RESULT_ListType_ = 0;
ListType* pListType(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListType_;
  }
}
ListType* pListType(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListType_;
  }
}

static LVal* YY_RESULT_LVal_ = 0;
LVal* pLVal(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_LVal_;
  }
}
LVal* pLVal(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_LVal_;
  }
}

static Expr* YY_RESULT_Expr_ = 0;
Expr* pExpr(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Expr_;
  }
}
Expr* pExpr(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Expr_;
  }
}

static ListExpr* YY_RESULT_ListExpr_ = 0;
ListExpr* pListExpr(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListExpr_;
  }
}
ListExpr* pListExpr(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListExpr_;
  }
}

static AddOp* YY_RESULT_AddOp_ = 0;
AddOp* pAddOp(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_AddOp_;
  }
}
AddOp* pAddOp(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_AddOp_;
  }
}

static MulOp* YY_RESULT_MulOp_ = 0;
MulOp* pMulOp(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_MulOp_;
  }
}
MulOp* pMulOp(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_MulOp_;
  }
}

static RelOp* YY_RESULT_RelOp_ = 0;
RelOp* pRelOp(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_RelOp_;
  }
}
RelOp* pRelOp(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_RelOp_;
  }
}




#line 823 "Parser.C" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    _ERROR_ = 258,
    _SYMB_0 = 259,
    _SYMB_1 = 260,
    _SYMB_2 = 261,
    _SYMB_3 = 262,
    _SYMB_4 = 263,
    _SYMB_5 = 264,
    _SYMB_6 = 265,
    _SYMB_7 = 266,
    _SYMB_8 = 267,
    _SYMB_9 = 268,
    _SYMB_10 = 269,
    _SYMB_11 = 270,
    _SYMB_12 = 271,
    _SYMB_13 = 272,
    _SYMB_14 = 273,
    _SYMB_15 = 274,
    _SYMB_16 = 275,
    _SYMB_17 = 276,
    _SYMB_18 = 277,
    _SYMB_19 = 278,
    _SYMB_20 = 279,
    _SYMB_21 = 280,
    _SYMB_22 = 281,
    _SYMB_23 = 282,
    _SYMB_24 = 283,
    _SYMB_25 = 284,
    _SYMB_26 = 285,
    _SYMB_27 = 286,
    _SYMB_28 = 287,
    _SYMB_29 = 288,
    _SYMB_30 = 289,
    _SYMB_31 = 290,
    _SYMB_32 = 291,
    _SYMB_33 = 292,
    _SYMB_34 = 293,
    _SYMB_35 = 294,
    _SYMB_36 = 295,
    _SYMB_37 = 296,
    _SYMB_38 = 297,
    _SYMB_39 = 298,
    _SYMB_40 = 299,
    _SYMB_41 = 300,
    _SYMB_42 = 301,
    _STRING_ = 302,
    _INTEGER_ = 303,
    _IDENT_ = 304
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 760 "LatteCPP.y" /* yacc.c:355  */

  int int_;
  char char_;
  double double_;
  char* string_;
  Program* program_;
  TopDef* topdef_;
  ListTopDef* listtopdef_;
  Arg* arg_;
  ListArg* listarg_;
  ClsElems* clselems_;
  ListClsElems* listclselems_;
  Block* block_;
  ListStmt* liststmt_;
  Stmt* stmt_;
  Item* item_;
  ListItem* listitem_;
  BasicType* basictype_;
  TypeName* typename_;
  Type* type_;
  ListType* listtype_;
  LVal* lval_;
  Expr* expr_;
  ListExpr* listexpr_;
  AddOp* addop_;
  MulOp* mulop_;
  RelOp* relop_;

#line 939 "Parser.C" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 956 "Parser.C" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  14
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   234

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  87
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  164

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   304

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   869,   869,   871,   872,   873,   875,   876,   878,   880,
     881,   882,   884,   885,   887,   888,   890,   892,   893,   895,
     896,   897,   898,   899,   900,   901,   902,   903,   904,   905,
     906,   907,   909,   910,   912,   913,   915,   916,   917,   918,
     920,   921,   923,   924,   930,   931,   932,   934,   935,   936,
     937,   938,   939,   940,   941,   942,   943,   944,   945,   946,
     947,   949,   950,   951,   953,   954,   956,   957,   959,   960,
     962,   963,   965,   966,   968,   969,   970,   972,   973,   975,
     976,   977,   979,   980,   981,   982,   983,   984
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "_ERROR_", "_SYMB_0", "_SYMB_1",
  "_SYMB_2", "_SYMB_3", "_SYMB_4", "_SYMB_5", "_SYMB_6", "_SYMB_7",
  "_SYMB_8", "_SYMB_9", "_SYMB_10", "_SYMB_11", "_SYMB_12", "_SYMB_13",
  "_SYMB_14", "_SYMB_15", "_SYMB_16", "_SYMB_17", "_SYMB_18", "_SYMB_19",
  "_SYMB_20", "_SYMB_21", "_SYMB_22", "_SYMB_23", "_SYMB_24", "_SYMB_25",
  "_SYMB_26", "_SYMB_27", "_SYMB_28", "_SYMB_29", "_SYMB_30", "_SYMB_31",
  "_SYMB_32", "_SYMB_33", "_SYMB_34", "_SYMB_35", "_SYMB_36", "_SYMB_37",
  "_SYMB_38", "_SYMB_39", "_SYMB_40", "_SYMB_41", "_SYMB_42", "_STRING_",
  "_INTEGER_", "_IDENT_", "$accept", "Program", "TopDef", "ListTopDef",
  "Arg", "ListArg", "ClsElems", "ListClsElems", "Block", "ListStmt",
  "Stmt", "Item", "ListItem", "BasicType", "TypeName", "Type", "LVal",
  "Expr6", "Expr5", "Expr4", "Expr3", "Expr2", "Expr1", "Expr", "ListExpr",
  "AddOp", "MulOp", "RelOp", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304
};
# endif

#define YYPACT_NINF -105

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-105)))

#define YYTABLE_NINF -47

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -15,  -105,   -23,  -105,  -105,  -105,  -105,    27,   -15,  -105,
    -105,    31,    -8,    -2,  -105,  -105,  -105,    44,  -105,    13,
     123,    74,    57,    67,    75,    39,  -105,  -105,    51,  -105,
     123,    98,  -105,    40,   175,  -105,  -105,  -105,   123,  -105,
    -105,    47,   103,   145,  -105,  -105,   161,   161,  -105,   106,
     111,   174,   139,  -105,   117,  -105,  -105,    -3,  -105,  -105,
      73,    49,    90,  -105,    45,     7,   201,   105,   115,    98,
      11,    99,   122,   124,    99,    99,   123,   155,   119,   129,
    -105,   136,   155,   155,   137,   138,   141,   155,   142,   143,
     155,   104,  -105,  -105,  -105,   155,  -105,  -105,   155,   155,
    -105,  -105,  -105,  -105,  -105,  -105,   155,   155,  -105,  -105,
     113,   155,   107,  -105,   112,   162,   155,   155,  -105,   164,
     152,   165,   155,    73,  -105,   167,  -105,  -105,   168,     9,
    -105,    45,  -105,     7,  -105,  -105,   180,   173,   158,    93,
     182,   184,    93,   155,  -105,  -105,  -105,  -105,    62,   155,
    -105,   131,   144,  -105,  -105,  -105,  -105,   185,   206,    93,
    -105,    93,  -105,  -105
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    38,     0,    36,    37,    39,    41,     0,     6,     2,
      40,    43,     0,     0,     1,     7,    42,     0,    14,     0,
       9,     0,     0,    10,     0,     0,     4,    15,     0,    14,
       9,     0,     8,     0,     0,    11,    17,     3,     9,    13,
       5,     0,     0,     0,    16,    19,     0,     0,    57,     0,
       0,     0,     0,    56,     0,    59,    55,    54,    20,    18,
       0,     0,    63,    65,    67,    69,    71,    73,     0,     0,
      54,    63,     0,    54,    61,    62,     0,     0,    53,     0,
      26,     0,     0,    74,    32,    34,     0,     0,     0,     0,
       0,     0,    79,    80,    81,     0,    78,    77,     0,     0,
      82,    83,    84,    85,    86,    87,     0,     0,    31,    12,
       0,     0,     0,    60,     0,     0,     0,     0,    25,     0,
      75,     0,     0,     0,    21,     0,    23,    24,     0,    47,
      64,    66,    70,    68,    72,    49,     0,    47,     0,     0,
       0,     0,     0,    74,    58,    33,    35,    22,    50,    74,
      50,     0,    27,    52,    51,    29,    76,     0,     0,     0,
      48,     0,    28,    30
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -105,  -105,  -105,   204,  -105,     1,  -105,   186,   -17,  -105,
    -104,  -105,   102,   171,  -105,     2,  -105,   -41,   121,   128,
     127,  -105,   135,   -40,   -85,  -105,  -105,  -105
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     7,     8,     9,    23,    24,    27,    21,    58,    41,
      59,    85,    86,    10,    11,    60,    61,    71,    63,    64,
      65,    66,    67,    68,   121,    98,    95,   106
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      62,    83,    12,    72,    18,    74,    75,   -44,   -44,   -44,
      12,   -41,    81,   149,    37,    83,   110,     1,     2,   -46,
     -46,   -46,    25,    28,     3,    96,    13,    14,     4,    97,
       5,    35,    25,    19,     6,   152,    28,   115,   155,    42,
      25,    17,   119,   120,    38,    16,   -41,   125,    20,    39,
     128,    43,   109,    36,    44,   162,    45,   163,   156,    87,
      88,    89,    22,    29,   157,    46,    47,   134,    92,    93,
      94,   136,   -45,   -45,   -45,    30,   140,   141,   114,     1,
      31,    26,   145,    48,    49,    50,     3,    51,    32,    52,
       4,    53,     5,    54,    55,    56,    57,    43,    62,    36,
      33,    62,    45,   120,    36,    90,     1,    91,    69,   120,
      76,    46,    47,     3,   111,    77,   112,     4,    62,     5,
      62,    82,    84,     6,   108,     1,   107,   113,    83,    48,
      49,    50,     3,    51,   116,    52,     4,    53,     5,    54,
      55,    56,    57,    43,   117,   118,   123,   122,    80,    43,
     124,   126,   127,   129,   135,     1,   137,    46,    47,    43,
     143,   138,     3,    46,    47,    43,     4,   139,     5,   142,
     144,   151,     6,    46,    47,    48,   147,   149,   159,    51,
     158,    48,    40,    53,   148,    51,    55,    56,    73,    53,
     160,    48,    55,    56,    70,    51,   150,    48,   153,    53,
     154,    51,    55,    56,    73,    53,     1,     1,    55,    56,
      73,   161,    15,     3,     3,    34,   130,     4,     4,     5,
       5,    99,    79,    78,     6,   146,   131,   100,   101,   102,
     103,   104,   105,   133,   132
};

static const yytype_uint8 yycheck[] =
{
      41,     4,     0,    43,     6,    46,    47,    10,    11,    12,
       8,    14,    52,     4,    31,     4,     5,    32,    33,    10,
      11,    12,    20,    21,    39,    18,    49,     0,    43,    22,
      45,    30,    30,    35,    49,   139,    34,    77,   142,    38,
      38,    49,    82,    83,     4,    14,    49,    87,     4,     9,
      90,     4,    69,     6,     7,   159,     9,   161,   143,    10,
      11,    12,    49,     6,   149,    18,    19,   107,    23,    24,
      25,   111,    10,    11,    12,     8,   116,   117,    76,    32,
       5,     7,   122,    36,    37,    38,    39,    40,    49,    42,
      43,    44,    45,    46,    47,    48,    49,     4,   139,     6,
      49,   142,     9,   143,     6,    15,    32,    17,     5,   149,
       4,    18,    19,    39,    15,     4,    17,    43,   159,    45,
     161,     4,    49,    49,     9,    32,    21,     5,     4,    36,
      37,    38,    39,    40,    15,    42,    43,    44,    45,    46,
      47,    48,    49,     4,    15,     9,     8,    10,     9,     4,
       9,     9,     9,    49,    41,    32,    49,    18,    19,     4,
       8,    49,    39,    18,    19,     4,    43,     5,    45,     5,
       5,    13,    49,    18,    19,    36,     9,     4,    34,    40,
      49,    36,     7,    44,    16,    40,    47,    48,    49,    44,
       5,    36,    47,    48,    49,    40,    16,    36,    16,    44,
      16,    40,    47,    48,    49,    44,    32,    32,    47,    48,
      49,     5,     8,    39,    39,    29,    95,    43,    43,    45,
      45,    20,    51,    49,    49,   123,    98,    26,    27,    28,
      29,    30,    31,   106,    99
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    32,    33,    39,    43,    45,    49,    51,    52,    53,
      63,    64,    65,    49,     0,    53,    14,    49,     6,    35,
       4,    57,    49,    54,    55,    65,     7,    56,    65,     6,
       8,     5,    49,    49,    57,    55,     6,    58,     4,     9,
       7,    59,    55,     4,     7,     9,    18,    19,    36,    37,
      38,    40,    42,    44,    46,    47,    48,    49,    58,    60,
      65,    66,    67,    68,    69,    70,    71,    72,    73,     5,
      49,    67,    73,    49,    67,    67,     4,     4,    49,    63,
       9,    73,     4,     4,    49,    61,    62,    10,    11,    12,
      15,    17,    23,    24,    25,    76,    18,    22,    75,    20,
      26,    27,    28,    29,    30,    31,    77,    21,     9,    58,
       5,    15,    17,     5,    65,    73,    15,    15,     9,    73,
      73,    74,    10,     8,     9,    73,     9,     9,    73,    49,
      68,    69,    72,    70,    73,    41,    73,    49,    49,     5,
      73,    73,     5,     8,     5,    73,    62,     9,    16,     4,
      16,    13,    60,    16,    16,    60,    74,    74,    49,    34,
       5,     5,    60,    60
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    50,    51,    52,    52,    52,    53,    53,    54,    55,
      55,    55,    56,    56,    57,    57,    58,    59,    59,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    61,    61,    62,    62,    63,    63,    63,    63,
      64,    64,    65,    65,    66,    66,    66,    67,    67,    67,
      67,    67,    67,    67,    67,    67,    67,    67,    67,    67,
      67,    68,    68,    68,    69,    69,    70,    70,    71,    71,
      72,    72,    73,    73,    74,    74,    74,    75,    75,    76,
      76,    76,    77,    77,    77,    77,    77,    77
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     6,     5,     7,     1,     2,     2,     0,
       1,     3,     6,     3,     0,     2,     3,     0,     2,     1,
       1,     3,     4,     3,     3,     3,     2,     5,     7,     5,
       8,     2,     1,     3,     1,     3,     1,     1,     1,     1,
       1,     1,     2,     1,     1,     4,     3,     3,     6,     4,
       4,     5,     5,     2,     1,     1,     1,     1,     4,     1,
       3,     2,     2,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     0,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 869 "LatteCPP.y" /* yacc.c:1646  */
    {  std::reverse((yyvsp[0].listtopdef_)->begin(),(yyvsp[0].listtopdef_)->end()) ;(yyval.program_) = new Prog((yyvsp[0].listtopdef_)); (yyval.program_)->line_number = yy_mylinenumber; YY_RESULT_Program_= (yyval.program_); }
#line 2163 "Parser.C" /* yacc.c:1646  */
    break;

  case 3:
#line 871 "LatteCPP.y" /* yacc.c:1646  */
    {  std::reverse((yyvsp[-2].listarg_)->begin(),(yyvsp[-2].listarg_)->end()) ;(yyval.topdef_) = new FnDef((yyvsp[-5].type_), (yyvsp[-4].string_), (yyvsp[-2].listarg_), (yyvsp[0].block_)); (yyval.topdef_)->line_number = yy_mylinenumber;  }
#line 2169 "Parser.C" /* yacc.c:1646  */
    break;

  case 4:
#line 872 "LatteCPP.y" /* yacc.c:1646  */
    {  (yyval.topdef_) = new ClsDef((yyvsp[-3].string_), (yyvsp[-1].listclselems_)); (yyval.topdef_)->line_number = yy_mylinenumber;  }
#line 2175 "Parser.C" /* yacc.c:1646  */
    break;

  case 5:
#line 873 "LatteCPP.y" /* yacc.c:1646  */
    {  (yyval.topdef_) = new ExtClsDef((yyvsp[-5].string_), (yyvsp[-3].string_), (yyvsp[-1].listclselems_)); (yyval.topdef_)->line_number = yy_mylinenumber;  }
#line 2181 "Parser.C" /* yacc.c:1646  */
    break;

  case 6:
#line 875 "LatteCPP.y" /* yacc.c:1646  */
    {  (yyval.listtopdef_) = new ListTopDef() ; (yyval.listtopdef_)->push_back((yyvsp[0].topdef_));  }
#line 2187 "Parser.C" /* yacc.c:1646  */
    break;

  case 7:
#line 876 "LatteCPP.y" /* yacc.c:1646  */
    {  (yyvsp[0].listtopdef_)->push_back((yyvsp[-1].topdef_)) ; (yyval.listtopdef_) = (yyvsp[0].listtopdef_) ;  }
#line 2193 "Parser.C" /* yacc.c:1646  */
    break;

  case 8:
#line 878 "LatteCPP.y" /* yacc.c:1646  */
    {  (yyval.arg_) = new Ar((yyvsp[-1].type_), (yyvsp[0].string_)); (yyval.arg_)->line_number = yy_mylinenumber;  }
#line 2199 "Parser.C" /* yacc.c:1646  */
    break;

  case 9:
#line 880 "LatteCPP.y" /* yacc.c:1646  */
    {  (yyval.listarg_) = new ListArg();  }
#line 2205 "Parser.C" /* yacc.c:1646  */
    break;

  case 10:
#line 881 "LatteCPP.y" /* yacc.c:1646  */
    {  (yyval.listarg_) = new ListArg() ; (yyval.listarg_)->push_back((yyvsp[0].arg_));  }
#line 2211 "Parser.C" /* yacc.c:1646  */
    break;

  case 11:
#line 882 "LatteCPP.y" /* yacc.c:1646  */
    {  (yyvsp[0].listarg_)->push_back((yyvsp[-2].arg_)) ; (yyval.listarg_) = (yyvsp[0].listarg_) ;  }
#line 2217 "Parser.C" /* yacc.c:1646  */
    break;

  case 12:
#line 884 "LatteCPP.y" /* yacc.c:1646  */
    {  std::reverse((yyvsp[-2].listarg_)->begin(),(yyvsp[-2].listarg_)->end()) ;(yyval.clselems_) = new ClsMethod((yyvsp[-5].type_), (yyvsp[-4].string_), (yyvsp[-2].listarg_), (yyvsp[0].block_)); (yyval.clselems_)->line_number = yy_mylinenumber;  }
#line 2223 "Parser.C" /* yacc.c:1646  */
    break;

  case 13:
#line 885 "LatteCPP.y" /* yacc.c:1646  */
    {  (yyval.clselems_) = new ClsField((yyvsp[-2].type_), (yyvsp[-1].string_)); (yyval.clselems_)->line_number = yy_mylinenumber;  }
#line 2229 "Parser.C" /* yacc.c:1646  */
    break;

  case 14:
#line 887 "LatteCPP.y" /* yacc.c:1646  */
    {  (yyval.listclselems_) = new ListClsElems();  }
#line 2235 "Parser.C" /* yacc.c:1646  */
    break;

  case 15:
#line 888 "LatteCPP.y" /* yacc.c:1646  */
    {  (yyvsp[-1].listclselems_)->push_back((yyvsp[0].clselems_)) ; (yyval.listclselems_) = (yyvsp[-1].listclselems_) ;  }
#line 2241 "Parser.C" /* yacc.c:1646  */
    break;

  case 16:
#line 890 "LatteCPP.y" /* yacc.c:1646  */
    {  (yyval.block_) = new Blk((yyvsp[-1].liststmt_)); (yyval.block_)->line_number = yy_mylinenumber;  }
#line 2247 "Parser.C" /* yacc.c:1646  */
    break;

  case 17:
#line 892 "LatteCPP.y" /* yacc.c:1646  */
    {  (yyval.liststmt_) = new ListStmt();  }
#line 2253 "Parser.C" /* yacc.c:1646  */
    break;

  case 18:
#line 893 "LatteCPP.y" /* yacc.c:1646  */
    {  (yyvsp[-1].liststmt_)->push_back((yyvsp[0].stmt_)) ; (yyval.liststmt_) = (yyvsp[-1].liststmt_) ;  }
#line 2259 "Parser.C" /* yacc.c:1646  */
    break;

  case 19:
#line 895 "LatteCPP.y" /* yacc.c:1646  */
    {  (yyval.stmt_) = new Empty(); (yyval.stmt_)->line_number = yy_mylinenumber;  }
#line 2265 "Parser.C" /* yacc.c:1646  */
    break;

  case 20:
#line 896 "LatteCPP.y" /* yacc.c:1646  */
    {  (yyval.stmt_) = new BStmt((yyvsp[0].block_)); (yyval.stmt_)->line_number = yy_mylinenumber;  }
#line 2271 "Parser.C" /* yacc.c:1646  */
    break;

  case 21:
#line 897 "LatteCPP.y" /* yacc.c:1646  */
    {  std::reverse((yyvsp[-1].listitem_)->begin(),(yyvsp[-1].listitem_)->end()) ;(yyval.stmt_) = new Decl((yyvsp[-2].type_), (yyvsp[-1].listitem_)); (yyval.stmt_)->line_number = yy_mylinenumber;  }
#line 2277 "Parser.C" /* yacc.c:1646  */
    break;

  case 22:
#line 898 "LatteCPP.y" /* yacc.c:1646  */
    {  (yyval.stmt_) = new Ass((yyvsp[-3].lval_), (yyvsp[-1].expr_)); (yyval.stmt_)->line_number = yy_mylinenumber;  }
#line 2283 "Parser.C" /* yacc.c:1646  */
    break;

  case 23:
#line 899 "LatteCPP.y" /* yacc.c:1646  */
    {  (yyval.stmt_) = new Incr((yyvsp[-2].lval_)); (yyval.stmt_)->line_number = yy_mylinenumber;  }
#line 2289 "Parser.C" /* yacc.c:1646  */
    break;

  case 24:
#line 900 "LatteCPP.y" /* yacc.c:1646  */
    {  (yyval.stmt_) = new Decr((yyvsp[-2].lval_)); (yyval.stmt_)->line_number = yy_mylinenumber;  }
#line 2295 "Parser.C" /* yacc.c:1646  */
    break;

  case 25:
#line 901 "LatteCPP.y" /* yacc.c:1646  */
    {  (yyval.stmt_) = new Ret((yyvsp[-1].expr_)); (yyval.stmt_)->line_number = yy_mylinenumber;  }
#line 2301 "Parser.C" /* yacc.c:1646  */
    break;

  case 26:
#line 902 "LatteCPP.y" /* yacc.c:1646  */
    {  (yyval.stmt_) = new VRet(); (yyval.stmt_)->line_number = yy_mylinenumber;  }
#line 2307 "Parser.C" /* yacc.c:1646  */
    break;

  case 27:
#line 903 "LatteCPP.y" /* yacc.c:1646  */
    {  (yyval.stmt_) = new Cond((yyvsp[-2].expr_), (yyvsp[0].stmt_)); (yyval.stmt_)->line_number = yy_mylinenumber;  }
#line 2313 "Parser.C" /* yacc.c:1646  */
    break;

  case 28:
#line 904 "LatteCPP.y" /* yacc.c:1646  */
    {  (yyval.stmt_) = new CondElse((yyvsp[-4].expr_), (yyvsp[-2].stmt_), (yyvsp[0].stmt_)); (yyval.stmt_)->line_number = yy_mylinenumber;  }
#line 2319 "Parser.C" /* yacc.c:1646  */
    break;

  case 29:
#line 905 "LatteCPP.y" /* yacc.c:1646  */
    {  (yyval.stmt_) = new While((yyvsp[-2].expr_), (yyvsp[0].stmt_)); (yyval.stmt_)->line_number = yy_mylinenumber;  }
#line 2325 "Parser.C" /* yacc.c:1646  */
    break;

  case 30:
#line 906 "LatteCPP.y" /* yacc.c:1646  */
    {  (yyval.stmt_) = new For((yyvsp[-5].type_), (yyvsp[-4].string_), (yyvsp[-2].string_), (yyvsp[0].stmt_)); (yyval.stmt_)->line_number = yy_mylinenumber;  }
#line 2331 "Parser.C" /* yacc.c:1646  */
    break;

  case 31:
#line 907 "LatteCPP.y" /* yacc.c:1646  */
    {  (yyval.stmt_) = new SExp((yyvsp[-1].expr_)); (yyval.stmt_)->line_number = yy_mylinenumber;  }
#line 2337 "Parser.C" /* yacc.c:1646  */
    break;

  case 32:
#line 909 "LatteCPP.y" /* yacc.c:1646  */
    {  (yyval.item_) = new NoInit((yyvsp[0].string_)); (yyval.item_)->line_number = yy_mylinenumber;  }
#line 2343 "Parser.C" /* yacc.c:1646  */
    break;

  case 33:
#line 910 "LatteCPP.y" /* yacc.c:1646  */
    {  (yyval.item_) = new Init((yyvsp[-2].string_), (yyvsp[0].expr_)); (yyval.item_)->line_number = yy_mylinenumber;  }
#line 2349 "Parser.C" /* yacc.c:1646  */
    break;

  case 34:
#line 912 "LatteCPP.y" /* yacc.c:1646  */
    {  (yyval.listitem_) = new ListItem() ; (yyval.listitem_)->push_back((yyvsp[0].item_));  }
#line 2355 "Parser.C" /* yacc.c:1646  */
    break;

  case 35:
#line 913 "LatteCPP.y" /* yacc.c:1646  */
    {  (yyvsp[0].listitem_)->push_back((yyvsp[-2].item_)) ; (yyval.listitem_) = (yyvsp[0].listitem_) ;  }
#line 2361 "Parser.C" /* yacc.c:1646  */
    break;

  case 36:
#line 915 "LatteCPP.y" /* yacc.c:1646  */
    {  (yyval.basictype_) = new Int(); (yyval.basictype_)->line_number = yy_mylinenumber;  }
#line 2367 "Parser.C" /* yacc.c:1646  */
    break;

  case 37:
#line 916 "LatteCPP.y" /* yacc.c:1646  */
    {  (yyval.basictype_) = new Str(); (yyval.basictype_)->line_number = yy_mylinenumber;  }
#line 2373 "Parser.C" /* yacc.c:1646  */
    break;

  case 38:
#line 917 "LatteCPP.y" /* yacc.c:1646  */
    {  (yyval.basictype_) = new Bool(); (yyval.basictype_)->line_number = yy_mylinenumber;  }
#line 2379 "Parser.C" /* yacc.c:1646  */
    break;

  case 39:
#line 918 "LatteCPP.y" /* yacc.c:1646  */
    {  (yyval.basictype_) = new Void(); (yyval.basictype_)->line_number = yy_mylinenumber;  }
#line 2385 "Parser.C" /* yacc.c:1646  */
    break;

  case 40:
#line 920 "LatteCPP.y" /* yacc.c:1646  */
    {  (yyval.typename_) = new BType((yyvsp[0].basictype_)); (yyval.typename_)->line_number = yy_mylinenumber;  }
#line 2391 "Parser.C" /* yacc.c:1646  */
    break;

  case 41:
#line 921 "LatteCPP.y" /* yacc.c:1646  */
    {  (yyval.typename_) = new ClsType((yyvsp[0].string_)); (yyval.typename_)->line_number = yy_mylinenumber;  }
#line 2397 "Parser.C" /* yacc.c:1646  */
    break;

  case 42:
#line 923 "LatteCPP.y" /* yacc.c:1646  */
    {  (yyval.type_) = new ArrayType((yyvsp[-1].typename_)); (yyval.type_)->line_number = yy_mylinenumber;  }
#line 2403 "Parser.C" /* yacc.c:1646  */
    break;

  case 43:
#line 924 "LatteCPP.y" /* yacc.c:1646  */
    {  (yyval.type_) = new NormalType((yyvsp[0].typename_)); (yyval.type_)->line_number = yy_mylinenumber;  }
#line 2409 "Parser.C" /* yacc.c:1646  */
    break;

  case 44:
#line 930 "LatteCPP.y" /* yacc.c:1646  */
    {  (yyval.lval_) = new LvVar((yyvsp[0].string_)); (yyval.lval_)->line_number = yy_mylinenumber;  }
#line 2415 "Parser.C" /* yacc.c:1646  */
    break;

  case 45:
#line 931 "LatteCPP.y" /* yacc.c:1646  */
    {  (yyval.lval_) = new LvTab((yyvsp[-3].expr_), (yyvsp[-1].expr_)); (yyval.lval_)->line_number = yy_mylinenumber;  }
#line 2421 "Parser.C" /* yacc.c:1646  */
    break;

  case 46:
#line 932 "LatteCPP.y" /* yacc.c:1646  */
    {  (yyval.lval_) = new LvAttr((yyvsp[-2].expr_), (yyvsp[0].string_)); (yyval.lval_)->line_number = yy_mylinenumber;  }
#line 2427 "Parser.C" /* yacc.c:1646  */
    break;

  case 47:
#line 934 "LatteCPP.y" /* yacc.c:1646  */
    {  (yyval.expr_) = new EAttr((yyvsp[-2].expr_), (yyvsp[0].string_)); (yyval.expr_)->line_number = yy_mylinenumber;  }
#line 2433 "Parser.C" /* yacc.c:1646  */
    break;

  case 48:
#line 935 "LatteCPP.y" /* yacc.c:1646  */
    {  std::reverse((yyvsp[-1].listexpr_)->begin(),(yyvsp[-1].listexpr_)->end()) ;(yyval.expr_) = new EMetCall((yyvsp[-5].expr_), (yyvsp[-3].string_), (yyvsp[-1].listexpr_)); (yyval.expr_)->line_number = yy_mylinenumber;  }
#line 2439 "Parser.C" /* yacc.c:1646  */
    break;

  case 49:
#line 936 "LatteCPP.y" /* yacc.c:1646  */
    {  (yyval.expr_) = new ECastNull((yyvsp[-2].string_)); (yyval.expr_)->line_number = yy_mylinenumber;  }
#line 2445 "Parser.C" /* yacc.c:1646  */
    break;

  case 50:
#line 937 "LatteCPP.y" /* yacc.c:1646  */
    {  (yyval.expr_) = new EAt((yyvsp[-3].expr_), (yyvsp[-1].expr_)); (yyval.expr_)->line_number = yy_mylinenumber;  }
#line 2451 "Parser.C" /* yacc.c:1646  */
    break;

  case 51:
#line 938 "LatteCPP.y" /* yacc.c:1646  */
    {  (yyval.expr_) = new ENewArr((yyvsp[-3].basictype_), (yyvsp[-1].expr_)); (yyval.expr_)->line_number = yy_mylinenumber;  }
#line 2457 "Parser.C" /* yacc.c:1646  */
    break;

  case 52:
#line 939 "LatteCPP.y" /* yacc.c:1646  */
    {  (yyval.expr_) = new ENewClArr((yyvsp[-3].string_), (yyvsp[-1].expr_)); (yyval.expr_)->line_number = yy_mylinenumber;  }
#line 2463 "Parser.C" /* yacc.c:1646  */
    break;

  case 53:
#line 940 "LatteCPP.y" /* yacc.c:1646  */
    {  (yyval.expr_) = new ENewCls((yyvsp[0].string_)); (yyval.expr_)->line_number = yy_mylinenumber;  }
#line 2469 "Parser.C" /* yacc.c:1646  */
    break;

  case 54:
#line 941 "LatteCPP.y" /* yacc.c:1646  */
    {  (yyval.expr_) = new EVar((yyvsp[0].string_)); (yyval.expr_)->line_number = yy_mylinenumber;  }
#line 2475 "Parser.C" /* yacc.c:1646  */
    break;

  case 55:
#line 942 "LatteCPP.y" /* yacc.c:1646  */
    {  (yyval.expr_) = new ELitInt((yyvsp[0].int_)); (yyval.expr_)->line_number = yy_mylinenumber;  }
#line 2481 "Parser.C" /* yacc.c:1646  */
    break;

  case 56:
#line 943 "LatteCPP.y" /* yacc.c:1646  */
    {  (yyval.expr_) = new ELitTrue(); (yyval.expr_)->line_number = yy_mylinenumber;  }
#line 2487 "Parser.C" /* yacc.c:1646  */
    break;

  case 57:
#line 944 "LatteCPP.y" /* yacc.c:1646  */
    {  (yyval.expr_) = new ELitFalse(); (yyval.expr_)->line_number = yy_mylinenumber;  }
#line 2493 "Parser.C" /* yacc.c:1646  */
    break;

  case 58:
#line 945 "LatteCPP.y" /* yacc.c:1646  */
    {  std::reverse((yyvsp[-1].listexpr_)->begin(),(yyvsp[-1].listexpr_)->end()) ;(yyval.expr_) = new EApp((yyvsp[-3].string_), (yyvsp[-1].listexpr_)); (yyval.expr_)->line_number = yy_mylinenumber;  }
#line 2499 "Parser.C" /* yacc.c:1646  */
    break;

  case 59:
#line 946 "LatteCPP.y" /* yacc.c:1646  */
    {  (yyval.expr_) = new EString((yyvsp[0].string_)); (yyval.expr_)->line_number = yy_mylinenumber;  }
#line 2505 "Parser.C" /* yacc.c:1646  */
    break;

  case 60:
#line 947 "LatteCPP.y" /* yacc.c:1646  */
    {  (yyval.expr_) = (yyvsp[-1].expr_);  }
#line 2511 "Parser.C" /* yacc.c:1646  */
    break;

  case 61:
#line 949 "LatteCPP.y" /* yacc.c:1646  */
    {  (yyval.expr_) = new Neg((yyvsp[0].expr_)); (yyval.expr_)->line_number = yy_mylinenumber;  }
#line 2517 "Parser.C" /* yacc.c:1646  */
    break;

  case 62:
#line 950 "LatteCPP.y" /* yacc.c:1646  */
    {  (yyval.expr_) = new Not((yyvsp[0].expr_)); (yyval.expr_)->line_number = yy_mylinenumber;  }
#line 2523 "Parser.C" /* yacc.c:1646  */
    break;

  case 63:
#line 951 "LatteCPP.y" /* yacc.c:1646  */
    {  (yyval.expr_) = (yyvsp[0].expr_);  }
#line 2529 "Parser.C" /* yacc.c:1646  */
    break;

  case 64:
#line 953 "LatteCPP.y" /* yacc.c:1646  */
    {  (yyval.expr_) = new EMul((yyvsp[-2].expr_), (yyvsp[-1].mulop_), (yyvsp[0].expr_)); (yyval.expr_)->line_number = yy_mylinenumber;  }
#line 2535 "Parser.C" /* yacc.c:1646  */
    break;

  case 65:
#line 954 "LatteCPP.y" /* yacc.c:1646  */
    {  (yyval.expr_) = (yyvsp[0].expr_);  }
#line 2541 "Parser.C" /* yacc.c:1646  */
    break;

  case 66:
#line 956 "LatteCPP.y" /* yacc.c:1646  */
    {  (yyval.expr_) = new EAdd((yyvsp[-2].expr_), (yyvsp[-1].addop_), (yyvsp[0].expr_)); (yyval.expr_)->line_number = yy_mylinenumber;  }
#line 2547 "Parser.C" /* yacc.c:1646  */
    break;

  case 67:
#line 957 "LatteCPP.y" /* yacc.c:1646  */
    {  (yyval.expr_) = (yyvsp[0].expr_);  }
#line 2553 "Parser.C" /* yacc.c:1646  */
    break;

  case 68:
#line 959 "LatteCPP.y" /* yacc.c:1646  */
    {  (yyval.expr_) = new ERel((yyvsp[-2].expr_), (yyvsp[-1].relop_), (yyvsp[0].expr_)); (yyval.expr_)->line_number = yy_mylinenumber;  }
#line 2559 "Parser.C" /* yacc.c:1646  */
    break;

  case 69:
#line 960 "LatteCPP.y" /* yacc.c:1646  */
    {  (yyval.expr_) = (yyvsp[0].expr_);  }
#line 2565 "Parser.C" /* yacc.c:1646  */
    break;

  case 70:
#line 962 "LatteCPP.y" /* yacc.c:1646  */
    {  (yyval.expr_) = new EAnd((yyvsp[-2].expr_), (yyvsp[0].expr_)); (yyval.expr_)->line_number = yy_mylinenumber;  }
#line 2571 "Parser.C" /* yacc.c:1646  */
    break;

  case 71:
#line 963 "LatteCPP.y" /* yacc.c:1646  */
    {  (yyval.expr_) = (yyvsp[0].expr_);  }
#line 2577 "Parser.C" /* yacc.c:1646  */
    break;

  case 72:
#line 965 "LatteCPP.y" /* yacc.c:1646  */
    {  (yyval.expr_) = new EOr((yyvsp[-2].expr_), (yyvsp[0].expr_)); (yyval.expr_)->line_number = yy_mylinenumber;  }
#line 2583 "Parser.C" /* yacc.c:1646  */
    break;

  case 73:
#line 966 "LatteCPP.y" /* yacc.c:1646  */
    {  (yyval.expr_) = (yyvsp[0].expr_);  }
#line 2589 "Parser.C" /* yacc.c:1646  */
    break;

  case 74:
#line 968 "LatteCPP.y" /* yacc.c:1646  */
    {  (yyval.listexpr_) = new ListExpr();  }
#line 2595 "Parser.C" /* yacc.c:1646  */
    break;

  case 75:
#line 969 "LatteCPP.y" /* yacc.c:1646  */
    {  (yyval.listexpr_) = new ListExpr() ; (yyval.listexpr_)->push_back((yyvsp[0].expr_));  }
#line 2601 "Parser.C" /* yacc.c:1646  */
    break;

  case 76:
#line 970 "LatteCPP.y" /* yacc.c:1646  */
    {  (yyvsp[0].listexpr_)->push_back((yyvsp[-2].expr_)) ; (yyval.listexpr_) = (yyvsp[0].listexpr_) ;  }
#line 2607 "Parser.C" /* yacc.c:1646  */
    break;

  case 77:
#line 972 "LatteCPP.y" /* yacc.c:1646  */
    {  (yyval.addop_) = new Plus(); (yyval.addop_)->line_number = yy_mylinenumber;  }
#line 2613 "Parser.C" /* yacc.c:1646  */
    break;

  case 78:
#line 973 "LatteCPP.y" /* yacc.c:1646  */
    {  (yyval.addop_) = new Minus(); (yyval.addop_)->line_number = yy_mylinenumber;  }
#line 2619 "Parser.C" /* yacc.c:1646  */
    break;

  case 79:
#line 975 "LatteCPP.y" /* yacc.c:1646  */
    {  (yyval.mulop_) = new Times(); (yyval.mulop_)->line_number = yy_mylinenumber;  }
#line 2625 "Parser.C" /* yacc.c:1646  */
    break;

  case 80:
#line 976 "LatteCPP.y" /* yacc.c:1646  */
    {  (yyval.mulop_) = new Div(); (yyval.mulop_)->line_number = yy_mylinenumber;  }
#line 2631 "Parser.C" /* yacc.c:1646  */
    break;

  case 81:
#line 977 "LatteCPP.y" /* yacc.c:1646  */
    {  (yyval.mulop_) = new Mod(); (yyval.mulop_)->line_number = yy_mylinenumber;  }
#line 2637 "Parser.C" /* yacc.c:1646  */
    break;

  case 82:
#line 979 "LatteCPP.y" /* yacc.c:1646  */
    {  (yyval.relop_) = new LTH(); (yyval.relop_)->line_number = yy_mylinenumber;  }
#line 2643 "Parser.C" /* yacc.c:1646  */
    break;

  case 83:
#line 980 "LatteCPP.y" /* yacc.c:1646  */
    {  (yyval.relop_) = new LE(); (yyval.relop_)->line_number = yy_mylinenumber;  }
#line 2649 "Parser.C" /* yacc.c:1646  */
    break;

  case 84:
#line 981 "LatteCPP.y" /* yacc.c:1646  */
    {  (yyval.relop_) = new GTH(); (yyval.relop_)->line_number = yy_mylinenumber;  }
#line 2655 "Parser.C" /* yacc.c:1646  */
    break;

  case 85:
#line 982 "LatteCPP.y" /* yacc.c:1646  */
    {  (yyval.relop_) = new GE(); (yyval.relop_)->line_number = yy_mylinenumber;  }
#line 2661 "Parser.C" /* yacc.c:1646  */
    break;

  case 86:
#line 983 "LatteCPP.y" /* yacc.c:1646  */
    {  (yyval.relop_) = new EQU(); (yyval.relop_)->line_number = yy_mylinenumber;  }
#line 2667 "Parser.C" /* yacc.c:1646  */
    break;

  case 87:
#line 984 "LatteCPP.y" /* yacc.c:1646  */
    {  (yyval.relop_) = new NE(); (yyval.relop_)->line_number = yy_mylinenumber;  }
#line 2673 "Parser.C" /* yacc.c:1646  */
    break;


#line 2677 "Parser.C" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
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
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
