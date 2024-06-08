/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_Y_TAB_HPP_INCLUDED
# define YY_YY_Y_TAB_HPP_INCLUDED
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
    IF = 258,
    ELSE = 259,
    FOR = 260,
    WHILE = 261,
    DO = 262,
    BREAK = 263,
    RETURN = 264,
    SWITCH = 265,
    CASE = 266,
    DEFAULT = 267,
    CONTINUE = 268,
    LPAREN = 269,
    RPAREN = 270,
    LCURL = 271,
    RCURL = 272,
    LTHIRD = 273,
    RTHIRD = 274,
    COMMA = 275,
    SEMICOLON = 276,
    PRINTLN = 277,
    PRINT = 278,
    INCOP = 279,
    DECOP = 280,
    ASSIGNOP = 281,
    NOT = 282,
    ID = 283,
    INT = 284,
    FLOAT = 285,
    DOUBLE = 286,
    CONST_INT = 287,
    CONST_FLOAT = 288,
    CHAR = 289,
    VOID = 290,
    ADDOP = 291,
    MULOP = 292,
    RELOP = 293,
    LOGICOP = 294,
    BITOP = 295,
    CONST_STRING = 296,
    SCANINT = 297,
    LOWER_THAN_ELSE = 298
  };
#endif
/* Tokens.  */
#define IF 258
#define ELSE 259
#define FOR 260
#define WHILE 261
#define DO 262
#define BREAK 263
#define RETURN 264
#define SWITCH 265
#define CASE 266
#define DEFAULT 267
#define CONTINUE 268
#define LPAREN 269
#define RPAREN 270
#define LCURL 271
#define RCURL 272
#define LTHIRD 273
#define RTHIRD 274
#define COMMA 275
#define SEMICOLON 276
#define PRINTLN 277
#define PRINT 278
#define INCOP 279
#define DECOP 280
#define ASSIGNOP 281
#define NOT 282
#define ID 283
#define INT 284
#define FLOAT 285
#define DOUBLE 286
#define CONST_INT 287
#define CONST_FLOAT 288
#define CHAR 289
#define VOID 290
#define ADDOP 291
#define MULOP 292
#define RELOP 293
#define LOGICOP 294
#define BITOP 295
#define CONST_STRING 296
#define SCANINT 297
#define LOWER_THAN_ELSE 298

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 17 "1905066.y"

    SymbolInfo* symbolInfo; 

#line 147 "y.tab.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_HPP_INCLUDED  */
