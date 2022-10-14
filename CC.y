%{

#include "globals.h"

int linenum=1, token_listing=0, context_level=0, num_entry=0, num_id=0;
int num_float=0, num_int=0, num_char=0, num_string=0, num_illegal=0;
int num_lookup=0, num_searched=0, last_sym=0, statement_dump=0, node_dump=0;
int flag_modifier, flag_external, comment=0;

FILE *fp;			/* 'fp' points to a FILE */
struct entry *fn_p = NULL;	/* initialize function pointer */

struct entry *syntax_tree;
struct entry *hashtbl [PRIME];
struct entry *context [MAX_CONTEXT_LEVELS];

%}

/* define union for yylval */

%union {
  char *lexeme;		/* lexeme		*/
  struct entry *symp;	/* symbol table pointer */
  int token;		/* tokens		*/
}

%token ILLEGAL

%token AND OR
%token <lexeme> CCON FCON ICON SCON
%token INC DEC
%token MOD
%token EQUAL NOT EQUAL
%token LT, LE, GT, GE
%token SHIFTL SHIFTR
%token STRCTPTR

%token CHAR
%token DO
%token DOUBLE
%token ELSE
%token EXTERN
%token FLOAT
%token FOR
%token <lexeme> ID
%token IF
%token INT
%token REGISTER
%token RETURN
%token SIZEOF
%token STATIC
%token STRUCT
%token VOID
%token WHILE

%nonassoc END_IF
%nonassoc ELSE
%right '='
%left OR
%left AND
%left EQUAL NOT_EQUAL
%left LT, LE, GT, GE
%left '+' '-'
%left '*' '/' '%'
%right '!' INC DEC

%token STATEMENT
%token ITOF FTOI
%token DEF
%token X4
%token CALL
%token PARAMETER
%token ARRAY
%token LEAF
%token LVAL, RVAL, POSTFIX, PREFIX

%type <token> modifier type_name unary_op
%type <symp> program external_decls declaration var_list var_item
%type <symp> array_var scalar_var function_def function_hdr parm_type_list
%type <symp> parm_list parm_decl function_body internal_decls
%type <symp> statement_list statement compound_stmt constant
%type <symp> if_stmt for_stmt while_stmt dowhile_stmt return_stmt expression
%type <symp> binary_expr unary_expr postfix_expr primary_expr argument_list

%%

program		: {flag_external = TRUE;} external_decls
		;

external_decls	: declaration external_decls
		| function_def
		;

declaration	: modifier type_name var_list ';' {
			flag modifier = FALSE;
			$$ = $3;
		| type_name var_list ';' {$$ = $2;}
		;

modifier	: EXTERN	{flag_modifier = m_extern; $$ = m_extern;}
		| REGISTER	{flag_modifier = m_register; $$ = m_register;}
		;

type_name	: VOID {$$ = t_void;}
		| INT {$$ = t_int;}
		| CHAR {$$ = t_char;}
		| FLOAT {$$ = t_float;}
		;

var_list	: var_item {
			int r;	/* used for get_reg() */
			int size, width; /* used for offset calculations */
			$1->t_type = $<token>0;
			if ($1->e_type == e_var) {
			  switch ($1->t_type) {
			  case t_char: $1->type.var.width = 1; break;
			  case t_float:
			  case t_int: $1->type.var.width = 4; break;
			  default: $1->type.var.width = 0; break;
			  }
			  if ($1->c_type == c_pointer)
			    $1->type.var.width = 4;
			  if (flag_external || (flag_modifier == m_extern)) {
			    $1->type.var.m_type = m_extern;
			    fprintf(fp, "\t.common %s, %d, %d\n",
				    $1->lexeme,
				    $1->c_type == c_array ?
				    $1->type.var.width *
				    atoi($1->type.var.array_length) :
			$1->type.var.width,
			$1->type.var.width);
	    }
	    else {
	      if ($1->c_type == c_array) { /* offset of array */
	        size = atoi($1->type.var.array_length);
	        width = $1->type.var.width;
	        $1->type.var.offset = align(size*width, width);
	      }
	      else {			/* offset of scalar */
	        width = $1->type.var.width;
	        $1->type.var.offset = align(width, width);
	      }
	    }
	    if (flag_modifier) { /* if modifier was specified */
	      if (flag_modifier == m_register) {
	        if (r = get_local($1)) {
	          $1->type.var.m_type = m_register;
	          printf("e_var '%s' is assigned ", $1->lexeme);
	          printf("register: %s\n", print_reg(r));
	          $1->type.var.reg = r;
	          $1->where = r;
	        }
	        else /* no more local register available */
	          $1->type.var.m_type = m_none;
	      }
	    }
	  }
	  if ($1->e_type == e_fn && flag_external)
	    fprintf(fp, "\t.global %s\n", $1->lexeme);
	}
  | var_list ',' var_item {
	  int r;   /* used for get_reg() */
	  int size, width; /* used for offset calculations */
	  $3->t_type = $<token>0;
	  if ($3->e_type == e_var) {
	    switch ($3->t_type) {
	    case t_char: $3->type.var.width = 1; break;
	    case t_float:
	    case t_int: $3->type.var.width = 4; break;
	    default: $3->type.var.width = 0; break;
	    }
	    if ($3->c_type == c_pointer)
	      $3->type.var.width = 4;
	    if (flag_external || (flag_modifier == m_extern)) {
	      $3->type.var.m_type = m_extern;
	      fprintf(fp, "\t.common %s, %d, %d\n",
		      $3->lexeme,
		      $3->c_type == c_array ?
		      $3->type.var.width *
		      atoi($3->type.var.array_length) :
		      $3->type.var.width,
		      $3->type.var.width);
	   }
	   else {
	     if ($3->c_type == c_array) { /* offset of array */
	       size = atoi($3->type.var.array_length);
	       width = $3->type.var.width;
	       $3->type.var.offset = align(size*width, width);
	     }
	     else {			 /* offset of scalar */
	       width = $3->type.var.width;
	       $3->type.var.offset = align(width, width);
	     }
	   }
			  if (flag_modifier) { /* if modifier was specified */
			    if (flag_modifier == m_register) {
			      if (r = get_local($3)) {
				$3->type.var.m_type = m_register;
				printf("e_var '%s' is assigned ", $3->lexeme);
				printf("register: %s\n", print_reg(r));
				$3->type.var.reg = r;
				$3->where = r;
			      }
			      else   /* no more local register available */
				$3->type.var.m_type = m_none;
			    }
			  }
			}
			if ($3->e_type == e_fn && flag_external)
			  fprintf(fp, "\t.global %s\n", $3->lexeme);
		      }
		;

var_item	: scalar_var {
			$1->c_type = c_scalar;
			$$ = $1;
			}
		| array_var {
			$1->c_type = c_array;
			$$ = $1;
			}
		| '*' scalar_var {
			$2->c_type = c_pointer;
			$$ = $2;
			}
		;

array_var	: ID '[' ICON ']' {
			if (!($$ = lookup($3)))	  /* if ICON doesn't exist */
			  $$ = insert(ICON, $3, 0);   /* create one */
			if (($$ = lookup($1)) && ($$->scope == context_level))
			  yyerror("multiply defined identifier");
			if ($$)
			  $$->references--;	/* see 121.t page 1 */
			$$ = insert (ID, $1, context_level);
			$$->e_type = e_var;
			$$->c_type =c_array;
			$$->type.var.array_length = $3;
			}
		;

scalar_var	: ID {
			if (($$ = lookup($1)) && ($$->scope == context_level))
			  yyerror("multiply defined identifier");
			if ($$)
			  $$->references--;	/* see 121.t page 1 */
			$$ insert (ID, $1, context_level);
			}
		| ID '(' parm_type_list ')' {
			if (($$ = lookup($1)) && ($$->scope == context_level))
			  yyerror("multiply defined identifier");
			if ($$)
			  $$->references--;	/* see 121.t page 1 */
			$$ = insert (ID, $1, context_level);
			$$->e_type = e_fn;
			/* we must connect the fn_parms liked list to ID */
			$$->type.fn.parameters = $3;
			/* we must erase the function's context_level vars */
			/* because it has no function body (prototype?)	   */
			context_level++; delete_level();
			}
		;

function_def	: function_hdr '{' {context_level++; flag_external = FALSE;) function_bo
dy '}' {delete_level();}
		;

function_hdr	: type_name '*' ID '(' parm_type_list ')' {
			if (($$ lookup($3)) && ($$->scope == context_level))
			  yyerror("multiply defined identifier");
			if ($$)
			  $$->references--;	/* see 121.t page 1 */
			$$ = insert (ID, $3, context_level);
			fn_p = $$; /* for RETURN type verification */
			$$->e_type = e_fn;
			$$->t_type = $1;
			$$->c_type = c_pointer;
			/* we must connect the fn_parms liked list to ID */
			$$->type.fn.parameters = $5;
			}
		| type_name ID '(' parm_type_list ')' {
			if (($$ = lookup($2)) && ($$->scope == context_level))
			  yyerror("multiply defined identifier");
			if ($$)
			  $$->references--;	/* see 121.t page 1 */
			$$ = insert(ID, $2, context_level);
			fn_p = $$; /* for RETURN type verification */
			$$->e_type = e_fn;
			$$->t_type = $1;
			$$->c_type = c_scalar;
			/* we must connect the fn_parms liked list to ID */
			$$->type.fn.parameters = $4;
			}
		| ID '(' parm_type_list ')' {
			if (($$ = lookup($1)) && ($$->scope == context_level))
			  yyerror("multiply defined identifier");
			if ($$)
			  $$->references--;	/* see 121.t page 1 */
			$$ = insert(ID, $1, context_level);
			fn_p = $$; /* for RETURN type verification */
			$$->e_type = e_fn;
			$$->t_type t_void; /* c_type = ??? */
			/* we must connect the fn_parms liked list to ID */
			$$->type.fn.parameters = $3;
			}
		;

parm_type_list	: parm_list
		| ($$ = NULL;)
		;

parm_list	: parm_decl {
			$1->fn_parms = NULL;	/* the last fn_parm in list */
			}
		| parm_list ',' parm_decl {
			struct entry *p = $1;	/* make list of all fn_parms */
			while (p->fn_parms)
			  p = p->fn_parms;
			p->fn_parms = $3;
			$3->fn_parms = NULL;
			}
		;

parm_decl	: type_name ID {
			if (($$ = lookup($2)) && ($$->scope == context_level+1))
			  yyerror("multiply defined identifier");
			if ($$)
			  $$->references--;	/* see 121.t page 1 */
			$$ = insert (ID, $2, context_level+1);
			$$->t_type = $1;
			$$->c_type = c_scalar;
			switch ($$->t_type) {
			case t_char: $$->type.var.width = 1; break;
			case t_float:
			case t_int: $$->type.var.width = 4; break;
			default: $$->type.var.width = 0; break;
			}
			}
		| type_name '*' ID {
			if (($$ = lookup($3)) && ($$->scope == context_level+1))
			  yyerror("multiply defined identifier");
			if ($$)
			  $$->references--;	/* see 121.t page 1 */
			$$ = insert (ID, $3, context_level+1);
			$$->t_type = $1;
			$$->c_type = c_pointer;
			$$->type.var.width = 4; /* pointer is always 4 bytes */
			}
		;

function_body	: internal_decls statement_list {
			if (node_dump)
			  printf("\nsyntax tree root = [%d]\n", $2);
			syntax_tree = $2;
			}
		;
internal_decls	: declaration internal_decls
		| {$$ = NULL;}
		;

statement_list	: statement statement_list {
			$$ = make_node (STATEMENT, $1, $2);
			}
		| {$$ = NULL;}
		;

statement	: compound_stmt {delete_level(); $$ = $1;}
		| ';' {$$ = NULL;}
		| expression ';'
		| if_stmt
		| for_stmt
		| while stmt
		| dowhile_stmt
		| return_stmt
		;

compound_stmt	: {context_level++;} '{' internal_decls statement_list '}' {
			$$ = $4; /* $4 not $3 because of embedded actions */
			}
		;

if_stmt		: IF '('expression ')' statement %prec END_IF {
			$$ = make_node(IF, $3, $5);
			}
		| IF '(' expression ')' statement ELSE statement {
			$$ = make_node (IF, $3, make_node (ELSE, $5, $7));
			}
		;     

for_stmt	: FOR '(' expression ';' expression ';' expression')' statement {

			$$ = make_node (STATEMENT, $3,
				make_node (STATEMENT,
				   make_node (WHILE, $5,
				      make_node (STATEMENT, $9,
					 make_node (STATEMENT, $7, NULL))),
				   NULL));
			}
		;

while_stmt	: WHILE '(' expression ')' statement {
			$$ = make_node(WHILE, $3, $5);
			}
		;

dowhile_stmt	: DO statement WHILE '(' expression ')' ';' {
			$$ = make_node(DO, make_node(STATEMENT, $2, NULL), $5);
			}
		;

return_stmt	: RETURN expression ';' {$$ = make_node (RETURN, $2, NULL);}
		| RETURN ';' {$$ = make_node(RETURN, NULL, NULL);}
		;

expression	: unary_expr '=' expression {
			$$ = make_node('=', $1, $3);
			}
		|binary_expr
		;

binary_expr	: binary_expr OR binary_expr {
			$$ = make_node (OR, $1, $3);
			}
		| binary_expr AND binary_expr {
			$$ = make_node(AND, $1, $3);
			}
		| binary_expr '+' binary_expr {
			$$ = make_node('+', $1, $3);
			}
		| binary_expr '-' binary_expr {
			$$ = make_node('-', $1, $3);
			}
		| binary_expr '*' binary_expr {
			$$ = make_node('*', $1, $3);
			}
		| binary_expr '/' binary_expr {
			$$ = make_node('/', $1, $3);
			}
		| binary_expr '%' binary_expr {
			$$ = make_node('%', $1, $3);
			}
		| binary_expr EQUAL binary_expr {
			$$ = make_node(EQUAL, $1, $3);
			}
		| binary_expr NOT_EQUAL binary_expr {
			$$ = make_node (NOT_EQUAL, $1, $3);
			}
		| binary_expr LT binary_expr {
			$$ = make_node (LT, $1, $3);
			}
		| binary_expr LE binary_expr {
			$$ = make_node (LE, $1, $3);
			}
		| binary_expr GT binary_expr {
			$$ = make_node (GT, $1, $3);
			}
		| binary_expr GE binary_expr {
			$$ = make_node (GE, $1, $3);
			}
		| unary_expr
		;

unary_expr	: unary_op_unary_expr {
			$$ = make_node ($1, $2, NULL);
			$$->node_class = PREFIX;
			}
		| postfix_expr
		;

unary_op	: '!' {$$ = '!';}
		| '+' {$$ = '+';}
		| '-' {$$ = '-';}
		| INC {$$ = INC;}
		| DEC {$$ = DEC;}
		| '&' {$$ = '&';}
		| '*' {$$ = '*';}
		;

postfix_expr	: postfix_expr '['expression ']' {
			$$ = make_node(DEF, make_node(ARRAY, $1, $3), NULL);
			}
		| ID '(' argument_list ')' {
			struct entry *fn;
			if (!(fn = lookup($1)))	/* is function defined? */
			  yyerror("undefined function");
			fn->node_type = LEAF;
			$$ = make_node(CALL, fn, $3);
			}
		| ID '(' ')' {
			struct entry *fn;
			if (!(fn = lookup($1))) /* is function defined? */
			  yyerror("undefined function");
			fn->node_type = LEAF;
			$$ = make_node (CALL, fn, NULL);
			}
		| postfix_expr INC {
			$$ = make_node(INC, $1, NULL);
			$$->node_class = POSTFIX;
			}
		| postfix_expr DEC {
			$$ = make_node (DEC, $1, NULL);
			$$->node_class = POSTFIX;
			}
		| primary_expr
		;

primary_expr	: ID {
			if (!($$ = lookup($1)))	  /* is variable defined? */
			  yyerror("undefined variable");
			$$->node_type = LEAF;
			}
		| constant {
			$1->node_type = LEAF;
			$$ = $1;
			}
		| '('expression ')' {$$ = $2;}
		;                                   

constant	: ICON {
			if (!($$ = lookup($1)))	    /* if ICON doesn't exist */
			  $$ = insert(ICON, $1, 0);	/* create one */
			}
		| CCON {
			if (!($$ = lookup($1)))	    /* if CCON doesn't exist */
			  $$ = insert(CCON, $1, 0);	/* create one */
			}
		| SCON {
			char 1[6];
			if (!($$ = lookup($1))) {   /* if SCON doesn't exist */
			  $$ = insert(SCON, $1, 0);	/* create one */
			  fprintf(fp, "%s:\t.asciz\t%s\n",
				  newlabel(1, 'C'), $$->lexeme);
			  strcpy($$->type.con.label, 1);
			}
			}
		| FCON {
			if (!($$ = lookup($1)))      /* if FCON doesn't exist */
			  $$ = insert(FCON, $1, 0);	/* create one */
			}
		;

argument_list	: expression ',' argument_list {
			$$ = make_node(PARAMETER, $1, $3);
			}
		| expression {$$ = make_node(PARAMETER, $1, NULL);}
		;

%%

main()
{
  if ((fp = fopen("output.s", "w")) == NULL) {
    printf("CC: can't open 'output.s'\n");
    exit(1);
  }
  init_reg_tbl();
  yyparse();
  check(syntax_tree);
  if (statement_dump) {
    printf("\n*** STATEMENT DUMP\n");
    syntax_tree_dump(syntax_tree);
  }
  /* output function header & save stack space */
  fprintf(fp, "\t.align\t4\n");
  fprintf(fp, "\t.global\t%s\n", fn_p->lexeme);
  fprintf(fp, "%s:\tsave\t%%sp, STACK_SPACE, %%sp\n", fn_p->lexeme);
  fn_args();		/* assign fn_p args to IN registers */
  code (syntax_tree);	/* code function body */
  if (!fn_p->t_type)	/* if function returns 'void' */
    fprintf(fp, "\tret\n\trestore\n");	/* then just 'ret' & 'restore' */
  fprintf(fp, "\tSTACK_SPACE = %d\n", align (92, 8));
  fclose(fp);
  }        