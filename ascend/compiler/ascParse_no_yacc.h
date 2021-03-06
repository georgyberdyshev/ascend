
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ADD_TOK = 258,
     ALIASES_TOK = 259,
     AND_TOK = 260,
     ANY_TOK = 261,
     AREALIKE_TOK = 262,
     ARETHESAME_TOK = 263,
     ARRAY_TOK = 264,
     ASSERT_TOK = 265,
     ATOM_TOK = 266,
     BEQ_TOK = 267,
     BNE_TOK = 268,
     BREAK_TOK = 269,
     CALL_TOK = 270,
     CARD_TOK = 271,
     CASE_TOK = 272,
     CHOICE_TOK = 273,
     CHECK_TOK = 274,
     CONDITIONAL_TOK = 275,
     CONSTANT_TOK = 276,
     CONTINUE_TOK = 277,
     CREATE_TOK = 278,
     DATA_TOK = 279,
     DECREASING_TOK = 280,
     DEFAULT_TOK = 281,
     DEFINITION_TOK = 282,
     DIMENSION_TOK = 283,
     DIMENSIONLESS_TOK = 284,
     DO_TOK = 285,
     ELSE_TOK = 286,
     END_TOK = 287,
     EXPECT_TOK = 288,
     EXTERNAL_TOK = 289,
     FALSE_TOK = 290,
     FALLTHRU_TOK = 291,
     FIX_TOK = 292,
     FOR_TOK = 293,
     FREE_TOK = 294,
     FROM_TOK = 295,
     GLOBAL_TOK = 296,
     IF_TOK = 297,
     IMPORT_TOK = 298,
     IN_TOK = 299,
     INPUT_TOK = 300,
     INCREASING_TOK = 301,
     INTERACTIVE_TOK = 302,
     INTERSECTION_TOK = 303,
     ISA_TOK = 304,
     _IS_T = 305,
     ISREFINEDTO_TOK = 306,
     MAXIMIZE_TOK = 307,
     MAXINTEGER_TOK = 308,
     MAXREAL_TOK = 309,
     METHODS_TOK = 310,
     METHOD_TOK = 311,
     MINIMIZE_TOK = 312,
     MODEL_TOK = 313,
     NOT_TOK = 314,
     NOTES_TOK = 315,
     OF_TOK = 316,
     OPTION_TOK = 317,
     OR_TOK = 318,
     OTHERWISE_TOK = 319,
     OUTPUT_TOK = 320,
     PATCH_TOK = 321,
     PROD_TOK = 322,
     PROVIDE_TOK = 323,
     REFINES_TOK = 324,
     REPLACE_TOK = 325,
     REQUIRE_TOK = 326,
     RETURN_TOK = 327,
     RUN_TOK = 328,
     SATISFIED_TOK = 329,
     SELECT_TOK = 330,
     SIZE_TOK = 331,
     SOLVE_TOK = 332,
     SOLVER_TOK = 333,
     STOP_TOK = 334,
     SUCHTHAT_TOK = 335,
     SUM_TOK = 336,
     SWITCH_TOK = 337,
     THEN_TOK = 338,
     TRUE_TOK = 339,
     UNION_TOK = 340,
     UNITS_TOK = 341,
     UNIVERSAL_TOK = 342,
     WHEN_TOK = 343,
     WHERE_TOK = 344,
     WHILE_TOK = 345,
     WILLBE_TOK = 346,
     WILLBETHESAME_TOK = 347,
     WILLNOTBETHESAME_TOK = 348,
     ASSIGN_TOK = 349,
     CASSIGN_TOK = 350,
     DBLCOLON_TOK = 351,
     USE_TOK = 352,
     LEQ_TOK = 353,
     GEQ_TOK = 354,
     NEQ_TOK = 355,
     DOTDOT_TOK = 356,
     WITH_TOK = 357,
     VALUE_TOK = 358,
     WITH_VALUE_T = 359,
     REAL_TOK = 360,
     INTEGER_TOK = 361,
     IDENTIFIER_TOK = 362,
     BRACEDTEXT_TOK = 363,
     SYMBOL_TOK = 364,
     DQUOTE_TOK = 365,
     UPLUS_TOK = 366,
     UMINUS_TOK = 367
   };
#endif
/* Tokens.  */
#define ADD_TOK 258
#define ALIASES_TOK 259
#define AND_TOK 260
#define ANY_TOK 261
#define AREALIKE_TOK 262
#define ARETHESAME_TOK 263
#define ARRAY_TOK 264
#define ASSERT_TOK 265
#define ATOM_TOK 266
#define BEQ_TOK 267
#define BNE_TOK 268
#define BREAK_TOK 269
#define CALL_TOK 270
#define CARD_TOK 271
#define CASE_TOK 272
#define CHOICE_TOK 273
#define CHECK_TOK 274
#define CONDITIONAL_TOK 275
#define CONSTANT_TOK 276
#define CONTINUE_TOK 277
#define CREATE_TOK 278
#define DATA_TOK 279
#define DECREASING_TOK 280
#define DEFAULT_TOK 281
#define DEFINITION_TOK 282
#define DIMENSION_TOK 283
#define DIMENSIONLESS_TOK 284
#define DO_TOK 285
#define ELSE_TOK 286
#define END_TOK 287
#define EXPECT_TOK 288
#define EXTERNAL_TOK 289
#define FALSE_TOK 290
#define FALLTHRU_TOK 291
#define FIX_TOK 292
#define FOR_TOK 293
#define FREE_TOK 294
#define FROM_TOK 295
#define GLOBAL_TOK 296
#define IF_TOK 297
#define IMPORT_TOK 298
#define IN_TOK 299
#define INPUT_TOK 300
#define INCREASING_TOK 301
#define INTERACTIVE_TOK 302
#define INTERSECTION_TOK 303
#define ISA_TOK 304
#define _IS_T 305
#define ISREFINEDTO_TOK 306
#define MAXIMIZE_TOK 307
#define MAXINTEGER_TOK 308
#define MAXREAL_TOK 309
#define METHODS_TOK 310
#define METHOD_TOK 311
#define MINIMIZE_TOK 312
#define MODEL_TOK 313
#define NOT_TOK 314
#define NOTES_TOK 315
#define OF_TOK 316
#define OPTION_TOK 317
#define OR_TOK 318
#define OTHERWISE_TOK 319
#define OUTPUT_TOK 320
#define PATCH_TOK 321
#define PROD_TOK 322
#define PROVIDE_TOK 323
#define REFINES_TOK 324
#define REPLACE_TOK 325
#define REQUIRE_TOK 326
#define RETURN_TOK 327
#define RUN_TOK 328
#define SATISFIED_TOK 329
#define SELECT_TOK 330
#define SIZE_TOK 331
#define SOLVE_TOK 332
#define SOLVER_TOK 333
#define STOP_TOK 334
#define SUCHTHAT_TOK 335
#define SUM_TOK 336
#define SWITCH_TOK 337
#define THEN_TOK 338
#define TRUE_TOK 339
#define UNION_TOK 340
#define UNITS_TOK 341
#define UNIVERSAL_TOK 342
#define WHEN_TOK 343
#define WHERE_TOK 344
#define WHILE_TOK 345
#define WILLBE_TOK 346
#define WILLBETHESAME_TOK 347
#define WILLNOTBETHESAME_TOK 348
#define ASSIGN_TOK 349
#define CASSIGN_TOK 350
#define DBLCOLON_TOK 351
#define USE_TOK 352
#define LEQ_TOK 353
#define GEQ_TOK 354
#define NEQ_TOK 355
#define DOTDOT_TOK 356
#define WITH_TOK 357
#define VALUE_TOK 358
#define WITH_VALUE_T 359
#define REAL_TOK 360
#define INTEGER_TOK 361
#define IDENTIFIER_TOK 362
#define BRACEDTEXT_TOK 363
#define SYMBOL_TOK 364
#define DQUOTE_TOK 365
#define UPLUS_TOK 366
#define UMINUS_TOK 367




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 304 "ascend/compiler/ascParse.y"

  double real_value;
  long   int_value;
  struct fraction frac_value;
  symchar *id_ptr;
  CONST char *braced_ptr;	/* pointer for units, explanations, tables */
  symchar *sym_ptr;		/* pointer for symbols */
  CONST char *dquote_ptr;       /* for text in "double quotes" */
  struct Name *nptr;
  struct Expr *eptr;
  struct Set *sptr;
  struct VariableList *lptr;
  struct Statement *statptr;
  struct StatementList *slptr;
  struct SelectList *septr;
  struct SwitchList *swptr;
  struct WhenList *wptr;
  struct NoteTmp *notesptr;	/* change this once struct Notes is defined */
  struct gl_list_t *listp;
  struct InitProcedure *procptr;
  CONST dim_type *dimp;
  struct TypeDescription *tptr;
  struct UnitDefinition *udefptr;
  dim_type dimen;
  enum ForOrder order;
  enum ForKind fkind;



/* Line 1676 of yacc.c  */
#line 306 "ascend/compiler/ascParse.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE zz_lval;


