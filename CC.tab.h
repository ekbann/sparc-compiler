/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ILLEGAL = 258,
     AND = 259,
     OR = 260,
     CCON = 261,
     FCON = 262,
     ICON = 263,
     SCON = 264,
     INC = 265,
     DEC = 266,
     MOD = 267,
     EQUAL = 268,
     NOT_EQUAL = 269,
     LT = 270,
     LE = 271,
     GT = 272,
     GE = 273,
     SHIFTL = 274,
     SHIFTR = 275,
     STRCTPTR = 276,
     CHAR = 277,
     DO = 278,
     DOUBLE = 279,
     ELSE = 280,
     EXTERN = 281,
     FLOAT = 282,
     FOR = 283,
     ID = 284,
     IF = 285,
     INT = 286,
     REGISTER = 287,
     RETURN = 288,
     SIZEOF = 289,
     STATIC = 290,
     STRUCT = 291,
     VOID = 292,
     WHILE = 293,
     END_IF = 294,
     STATEMENT = 295,
     ITOF = 296,
     FTOI = 297,
     DEF = 298,
     X4 = 299,
     CALL = 300,
     PARAMETER = 301,
     ARRAY = 302,
     LEAF = 303,
     LVAL = 304,
     RVAL = 305,
     POSTFIX = 306,
     PREFIX = 307
   };
#endif
/* Tokens.  */
#define ILLEGAL 258
#define AND 259
#define OR 260
#define CCON 261
#define FCON 262
#define ICON 263
#define SCON 264
#define INC 265
#define DEC 266
#define MOD 267
#define EQUAL 268
#define NOT_EQUAL 269
#define LT 270
#define LE 271
#define GT 272
#define GE 273
#define SHIFTL 274
#define SHIFTR 275
#define STRCTPTR 276
#define CHAR 277
#define DO 278
#define DOUBLE 279
#define ELSE 280
#define EXTERN 281
#define FLOAT 282
#define FOR 283
#define ID 284
#define IF 285
#define INT 286
#define REGISTER 287
#define RETURN 288
#define SIZEOF 289
#define STATIC 290
#define STRUCT 291
#define VOID 292
#define WHILE 293
#define END_IF 294
#define STATEMENT 295
#define ITOF 296
#define FTOI 297
#define DEF 298
#define X4 299
#define CALL 300
#define PARAMETER 301
#define ARRAY 302
#define LEAF 303
#define LVAL 304
#define RVAL 305
#define POSTFIX 306
#define PREFIX 307




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 24 "CC.y"
{
  char *lexeme;				/* lexeme				*/
  struct entry *symp;		/* symbol table pointer */
  int token;				/* tokens				*/
}
/* Line 1529 of yacc.c.  */
#line 159 "CC.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

