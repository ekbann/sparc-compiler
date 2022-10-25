/* SUPPORT.C - all functions needed by the lexer and the parser. */

#include "CC.tab.h"
#include "globals.h"

/* define the hash function */

int hashpjw(char *s) {
  char *p;
  unsigned h = 0, g;
  for (p = s; *p != EOS; p++) {
    h = (h << 4) + (*p);
    if (g = h & 0xf0000000) {
      h = h ^ (g >> 24);
      h = h ^ g;
    }
  }
  return h % PRIME;
}

/* hashes the lexeme into the appropriate bucket if not in the table */

struct entry *insert(int token, char *lexeme, int scope) {
  int bucket = hashpjw(lexeme);
  struct entry *lexptr;

  /* keep count of the number of entries inserted */

  num_entry++;

  /* allocate memory for a new entry */

  lexptr = (struct entry *)malloc(sizeof(struct entry));
  lexptr->hash_link = hashtbl[bucket]; /* insert entry at head of list */
  hashtbl[bucket] = lexptr;            /* reconnect to main hash table */

  /* link every entry within the same context level in context[] */

  lexptr->scope_link = context[scope];
  context[scope] = lexptr;

  /* have to copy the lexeme itself as well and fill in info */

  lexptr->lexeme = lexeme;
  lexptr->token = token;
  lexptr->scope = scope;
  lexptr->references = 1;    /* first time entry is seen */
  lexptr->linenum = linenum; /* in line number 'linenum' */
  lexptr->type.var.reg = 0;
  lexptr->type.var.offset = 0;
  lexptr->left = NULL;
  lexptr->right = NULL;
  if (token == ID) {
    num_id++;
    lexptr->t_type = t_unknown;
    lexptr->c_type = c_unknown;
    lexptr->e_type = e_var; /* assume e-var, change otherwise */
  } else if (token == FCON) {
    num_float++;
    lexptr->t_type = t_float;
    lexptr->c_type = c_scalar;
    lexptr->e_type = e_const;
  } else if (token == ICON) {
    num_int++;
    lexptr->t_type = t_int;
    lexptr->c_type = c_scalar;
    lexptr->e_type = e_const;
  } else if (token == CCON) {
    num_char++;
    lexptr->t_type = t_char;
    lexptr->c_type = c_scalar;
    lexptr->e_type = e_const;
  } else if (token == SCON) {
    num_string++;
    lexptr->t_type = t_char;
    lexptr->c_type = c_array;
    lexptr->e_type = e_const;
  }
  return lexptr;
}

struct entry *lookup(char *lexeme) {
  int bucket = hashpjw(lexeme);
  struct entry *lexptr = hashtbl[bucket];

  num_lookup++; /* increment lookup count */

  /* search down the current scope list of the specific bucket looking for */
  /* the lexeme. The current scope is the first item in the bucket.	   */

  while (num_searched++, lexptr) {
    if (!strcmp(lexptr->lexeme, lexeme)) {
      lexptr->references++; /* lexeme already in the symbol table */
      return lexptr;        /* return pointer of lexptr to BISON */
    } else
      lexptr = lexptr->hash_link;
  }
  return NULL; /* not found */
}

struct entry *make_node(int n_type, struct entry *l, struct entry *r) {
  struct entry *node;

  node = (struct entry *)malloc(sizeof(struct entry));
  node->lexeme = NULL;
  node->node_type = n_type;
  node->linenum = linenum;
  node->left = l;
  node->right = r;
  node->e_type = e_unknown;
  node->t_type = t_unknown;
  node->c_type = c_unknown;
  if (node_dump) {
    printf("\nnode_type: %s [%d]\n", print_n_type(n_type), node);
    if (l && (l->node_type == LEAF))
      printf("	left:	LEAF [%d]\n", l);
    else
      printf("	left:	NODE [%d]\n", l);
    if (r && (r->node_type == LEAF))
      printf("	right:	LEAF [%d]\n", r);
    else
      printf("    right: NODE [%d]\n", r);
  }
  return node;
}

int align(int var_size, int width) {
  /* memory alignment of variable offsets of corresponding width */
  last_sym -= var_size;
  last_sym = width * ((int)((last_sym + 1) / width) - 1);
  return (last_sym);
}

void delete_level(void) {
  struct entry *item = context[context_level];
  int bucket;

  while (item) {
    bucket = hashpjw(item->lexeme); /* retrieve bucket location of entry    */
    hashtbl[bucket] = item->hash_link; /* unlink first entry of bucket list */
    item = item->scope_link; /* point to next item in same level     */
  }
  context[context_level] = NULL; /* now an empty list                   */
  context_level--;               /* a context level has been deleted    */
}
int level = 0;         /* indentation level for statement dump		*/
int loop_body = FALSE; /* if inside DO/WHILE loop body, STATEMENT	*/
                       /* nodes doesn't get indented to column 0,	*/
int loop_indent;       /* it gets indented to this column		*/

void syntax_tree_dump(struct entry *node) {
  int i, n_type;

  if (node) { /*process only if it is NOT a NULL node */
    n_type = node->node_type;
    if ((n_type == DO) || (n_type == WHILE)) {
      loop_body = TRUE;
      loop_indent = level;
    }
    if (n_type == STATEMENT) {
      putchar('\n');
      if (!loop_body)
        level--;
      else
        level = loop_indent;
    }

    else {
      if (n_type != LEAF) {
        for (i = level; i > 0; i--)
          printf("  ");
        /*  if (level !=0)
                printf("%s", print_n_class(node->node_class)); */
        printf("%s, ", print_n_type(node->node_type));
        printf("%s, ", print_e_type(node->e_type));
        printf("%s,", print_t_type(node->t_type));
        printf("%s\n", print_c_type(node->c_type));
      } else {
        for (i = level; i > 0; i--)
          printf("  ");
        /* if (level !=0)
        printf ("%s, ", print_n_class(node->node_class) ); */
        printf("%s, ", node->lexeme);
        printf("%s, ", print_e_type(node->e_type));
        printf("%s, ", print_t_type(node->t_type));
        printf("%s\n", print_c_type(node->c_type));
      }
    }
    level++;
    syntax_tree_dump(node->left);
    syntax_tree_dump(node->right);
    level--;
    if (level < 0)
      level = 0;
    if ((n_type == DO) || (n_type == WHILE))
      loop_body = FALSE;
  }
}

void symtab_dump(void) {
  int bucket;
  struct entry *lexptr;
  struct entry *fn_parms; /* pointer used to print function parameters	*/
  enum entry_type et;     /* if e_type = e_fn then print (fn_parameters) */

  printf("\n*** SYMBOL TABLE DUMP, e_<entry type>, t_<variable type>, ");
  printf("c_<constructor type>\n\n");
  for (bucket = PRIME - 1; bucket >= 0; bucket--) {
    lexptr = hashtbl[bucket];
    if (lexptr != 0) {
      printf("bucket %d\n", bucket);
      for (; lexptr; lexptr = lexptr->hash_link) {
        printf("<\"%s\" ", lexptr->lexeme);
        printf("scope %d, ", lexptr->scope);
        printf("%s, ", print_e_type(et = lexptr->e_type));
        printf("%s, ", print_t_type(lexptr->t_type));
        printf("%s, ", print_c_type(lexptr->c_type));
        if (et == e_var) {
          printf("width %d, ", lexptr->type.var.width);
          printf("offset %d, ", lexptr->type.var.offset);
          switch (lexptr->type.var.m_type) {
          case m_extern:
            printf("extern, ");
            break;
          case m_register:
            printf("register, ");
            break;
          default:
            break;
          }
          if (lexptr->c_type == c_array)
            printf("size %s, ", lexptr->type.var.array_length);
        }
        printf("references: %d>\n", lexptr->references);
        if (et == e_fn) {
          fn_parms = lexptr->type.fn.parameters; /* dump list of fn_parms */
          while (fn_parms) {
            printf(" <\"%s\" ", fn_parms->lexeme);
            printf("scope %d, ", fn_parms->scope);
            printf("%s, ", print_e_type(fn_parms->e_type));
            printf("%s, ", print_t_type(fn_parms->t_type));
            printf("%s, ", print_c_type(fn_parms->c_type));
            printf("width %d>\n", fn_parms->type.var.width);
            fn_parms = fn_parms->fn_parms;
          }
        }
      }
      putchar('\n');
    }
  }
}
char *print_n_class(int n_class) {
  switch (n_class) {
  case LVAL:
    return ("lval");
  case RVAL:
    return ("rval");
  case POSTFIX:
    return ("postfix");
  case PREFIX:
    return ("prefix");
  default:
    return ("unknown");
  }
}

char *print_n_type(int n_type) {
  switch (n_type) {
  case '=':
    return ("=");
  case '+':
    return ("+");
  case '-':
    return ("-");
  case '*':
    return ("*");
  case '/':
    return ("/");
  case '%':
    return ("%");
  case '&':
    return ("&");
  case '!':
    return ("!");
  case OR:
    return ("||");
  case AND:
    return ("&& ");
  case EQUAL:
    return ("==");
  case NOT_EQUAL:
    return ("!=");
  case LT:
    return ("<");
  case LE:
    return ("<=");
  case GT:
    return (">");
  case GE:
    return (">=");
  case DEC:
    return ("--");
  case INC:
    return ("++");
  case ARRAY:
    return ("ARRAY");
  case STATEMENT:
    return ("STATEMENT");
  case PARAMETER:
    return ("PARAMETER");
  case IF:
    return ("IF");
  case ELSE:
    return ("ELSE");
  case DO:
    return ("DO");
  case WHILE:
    return ("WHILE");
  case RETURN:
    return ("RETURN");
  case CALL:
    return ("CALL");
  case ITOF:
    return ("ITOF");
  case FTOI:
    return ("FTOI");
  case DEF:
    return ("@");
  case X4:
    return ("X4");
  default:
    return ("unknown");
  }
}
char *print_t_type(enum variable_type t) {
  switch (t) {
  case t_unknown:
    return ("t_unknown");
  case t_void:
    return ("t_void");
  case t_char:
    return ("t_char");
  case t_int:
    return ("t_int");
  case t_float:
    return ("t_float");
  default:
    return ("t_invalid");
  }
}
char *print_c_type(enum constructor_type t) {
  switch (t) {
  case c_unknown:
    return ("c_unknown");
  case c_scalar:
    return ("c_scalar");
  case c_pointer:
    return ("c_pointer");
  case c_array:
    return ("c_array");
  default:
    return ("c_invalid");
  }
}
char *print_e_type(enum entry_type t) {
  switch (t) {
  case e_unknown:
    return ("e_unknown");
  case e_var:
    return ("e_var");
  case e_fn:
    return ("e_fn");
  case e_const:
    return ("e_const");
  default:
    return ("e_invalid");
  }
}
void debug(char *text) {
  if (token_listing)
    printf("%d: <%s,>\n", linenum, text);
}
void debug_entry(int token, char *lexeme) {
  printf("%d: <", linenum);
  switch (token) {
  case CCON:
    printf("ccon");
    break;
  case FCON:
    printf("fcon");
    break;
  case ICON:
    printf("icon");
    break;
  case ID:
    printf("id");
    break;
  case SCON:
    printf("scon");
    break;
  default:
    printf("*** ERROR ***");
  }
  printf(", %s>\n", lexeme);
}
void symtab_stats(void) {
  printf("\n*** SYMBOL TABLE STATISTICS\n");
  printf("\nTotal number of table entries: %d\n", num_entry);
  printf("\t%d identifiers\n", num_id);
  printf("\t%d floating constants\n", num_float);
  printf("\t%d integer constants\n", num_int);
  printf("\t%d character constants\n", num_char);
  printf("\t%d string constants\n", num_string);
  printf("\nTotal number of illegal symbols: %d\n", num_illegal);
  printf("\nTotal number of lookups: %d\n", num_lookup);
  printf("Total number of entries searched: %d\n", num_searched);
  printf("Hash table efficiency: %.2f (entries searched per lookup) \n",
         (float)num_searched / num_lookup);
}
void check(struct entry *p) {
  struct entry *next, *l, *r;
  if (!p)
    return;
  else if (p->lexeme) {
    if (p->t_type == t_char && p->c_type == c_scalar)
      p->t_type = t_int; /* promote chars to int */
    /*  if (p->c_type == c_array) { */
    if (p->token == SCON) {
      p->c_type = c_pointer;
      p->e_type = e_const; /* SCON but array is e_var */
    }
  } else {
    check(l = p->left);
    check(r = p->right);
    switch (p->node_type) {
    case STATEMENT:
      break;
    case RETURN:
      return_op(p, l);
      break;
    case CALL:
      call_op(p, l, r);
      break;
    case X4:
      x4_op(p, l);
      break;
    case ARRAY:
      array_op(p, l, r);
      break;
    case DEF:
      def_op(p, l);
      break;
    case '+':
    case '-':
      plus_minus_op(p, l, r);
      break;
    case '*':
    case '/':
      mul_div_op(p, l, r);
      break;
    case '%':
      mod_op(p, l, r);
      break;
    case '=':
      assignment_op(p, l, r);
      break;
    case '!':
      not_op(p, l);
      break;
    case '&':
      address_op(p, l);
      break;
    case INC:
    case DEC:
      inc_dec_op(p, l);
      break;
    case EQUAL:
    case NOT_EQUAL:
    case LT:
    case LE:
    case GT:
    case GE:
      relational_op(p, l, r);
      break;
    case AND:
    case OR:
      logical_op(p, l, r);
      break;
    }
  }
}
x4_op(struct entry *p, struct entry *l) {
  if (l->t_type == t_int) {
    p->e_type = e_var;
    p->t_type = l->t_type;
    p->c_type = c_pointer;
    return;
  } else
    type_error(p->linenum,"x4_op");
}
def_op(struct entry *p, struct entry *l) {
  if (l->c_type == c_pointer) {
    p->e_type = e_var;
    if (l->t_type == t_char)
      p->t_type = t_int;
    else
      p->t_type = l->t_type;
    p->c_type = c_scalar; /* not sure this is correct */
    return;
  } else
    type_error(p->linenum,"def_op");
}
array_op(struct entry *p, struct entry *l, struct entry *r) {
  if (r->t_type != t_int) /* array index is not an INT */
    type_error(p->linenum,"array_op");
  if (l->type.var.width == 4) {
    p->right = make_node(X4, r, NULL);
    p->right->e_type = r->e_type;
    p->right->t_type = t_int; /* has to be an int */
    p->right->c_type = r->c_type;
    /* MAYBE I should force it to c_scalar */
  }
  p->e_type = e_var;
  p->t_type = l->t_type;
  p->c_type = c_pointer;
}

mod_op(struct entry *p, struct entry *l, struct entry *r) {
  if (l->t_type == t_int && r->t_type == t_int) {
    p->e_type = e_var;
    p->t_type = t_int;
    p->c_type = c_scalar; /* is this right? */
    return;
  } else
    type_error(p->linenum,"mod_op");
}
call_op(struct entry *p, struct entry *l, struct entry *r) {
  struct entry *fn_parms; /* pointer for function parameters */

  p->e_type = e_var;
  p->t_type = l->t_type;
  p->c_type = l->c_type;
  /* PARAMETER function parameters --> STATEMENT assignment_ops */
  fn_parms = l->type.fn.parameters; /* linked list of fn parameters */
  while (fn_parms) {
    if (r) { /* if not NULL, then it is PARAMETER */
      r->node_type = STATEMENT;
      fn_parms->node_type = LEAF; /* assign node type */
      r->left = make_node('=', fn_parms, r->left);
      /* must type check the parameters */
      assignment_op(r->left, r->left->left, r->left->right);
    } else /* encountered NULL before function got all parms needed */
      type_error(p->linenum,"call_op: not enough parameters");
    fn_parms = fn_parms->fn_parms; /* check next function parameter */
    r = r->right;                  /* move to next call parameter */
  }
  if (r)
    type_error(p->linenum,"call_op: too much parameters"); /* still more CALL parms */
  return;
}

return_op(struct entry *p, struct entry *l) {
  p->e_type = e_var; /* make sure RETURN has same type as function */
  p->t_type = fn_p->t_type;
  p->c_type = fn_p->c_type;
  if (p->t_type == l->t_type && p->c_type == l->c_type)
    return; /* everything checks out */
  else if (p->c_type == c_scalar && l->c_type == c_scalar) {
    if (p->t_type == t_int && l->t_type == t_float) {
      p->left = make_node(FTOI, l, NULL);
      p->left->e_type = e_var;
      p->left->t_type = t_int;
      p->left->c_type = c_scalar;
      return;
    } else if (p->t_type == t_float && l->t_type == t_int) {
      p->left = make_node(ITOF, l, NULL);
      p->left->e_type = e_var;
      p->left->t_type = t_float;
      p->left->c_type = c_scalar;
      return;
    } else
      type_error(p->linenum,"return_op: return type not INT or FLOAT");
  } else
    type_error(p->linenum,"return_op: unknown return type");
}
address_op(struct entry *p, struct entry *l) {
  if ((l->e_type == e_var && l->type.var.m_type != m_register) ||
      l->e_type == e_fn) {
    p->e_type = e_var;
    p->c_type = c_pointer;
    if ((l->node_type == DEF) && (l->left->node_type == ARRAY))
      p->left = p->left->left; /* skip de-referencing to ARRAY */
    p->t_type = p->left->t_type;
    return;
  } else
    type_error(p->linenum,"address_op");
}

inc_dec_op(struct entry *p, struct entry *l) {
  if (l->e_type == e_var) {
    p->e_type = e_var;
    p->t_type = l->t_type;
    p->c_type = l->c_type;
    return;
  } else
    type_error(p->linenum,"inc_dec_op");
}

logical_op(struct entry *p, struct entry *l, struct entry *r) {
  if ((l->t_type == t_int || l->t_type == t_float) &&
      (r->t_type == t_int || r->t_type == t_float)) {
    p->e_type = e_var;
    p->t_type = t_int;
    p->c_type = c_scalar;
    return;
  } else
    type_error(p->linenum,"logical_op");
}
relational_op(struct entry *p, struct entry *l, struct entry *r) {
  if (l->t_type == r->t_type && (l->t_type == t_int || l->t_type == t_float)) {
    p->e_type = e_var;
    p->t_type = t_int;
    p->c_type = c_scalar;
    return;
  } else if (l->t_type == t_int && r->t_type == t_float) {
    p->left = make_node(ITOF, l, NULL);
    p->left->t_type = t_float;
    p->left->c_type = c_scalar;
    p->left->e_type = e_var;
    p->e_type = e_var;
    p->t_type = t_int;
    p->c_type = c_scalar;
    return;
  } else if (r->t_type == t_int && l->t_type == t_float) {
    p->right = make_node(ITOF, r, NULL);
    p->right->t_type = t_float;
    p->right->c_type = c_scalar;
    p->right->e_type = e_var;
    p->e_type = e_var;
    p->t_type = t_int;
    p->c_type = c_scalar;
    return;
  } else
    type_error(p->linenum,"relational_op");
}

not_op(struct entry *p, struct entry *l) {
  if (l->t_type == t_int || l->t_type == t_float) {
    p->e_type = e_var;
    p->t_type = t_int;
    p->c_type = c_scalar;
    return;
  } else
    type_error(p->linenum,"not_op");
}
assignment_op(struct entry *p, struct entry *l, struct entry *r) {
  if (l->e_type != e_var) /* must be lvalue */
    type_error(p->linenum,"assignment_op: l not e_var");
  else if (l->t_type == r->t_type && l->c_type == r->c_type) {
    p->e_type = e_var; /* does it matter? */
    p->t_type = l->t_type;
    p->c_type = l->c_type;
    return;
  } else if (l->c_type == c_scalar && r->c_type == c_scalar) {
    if (l->t_type == t_int && r->t_type == t_float) {
      p->right = make_node(FTOI, r, NULL);
      p->right->e_type = e_var;
      p->right->t_type = t_int;
      p->right->c_type = c_scalar;
      p->e_type = e_var;
      p->t_type = t_int;
      p->c_type = c_scalar;
      return;
    }
    if (l->t_type == t_float && r->t_type == t_int) {
      p->right = make_node(ITOF, r, NULL);
      p->right->e_type = e_var;
      p->right->t_type = t_float;
      p->right->c_type = c_scalar;
      p->e_type = e_var;
      p->t_type = t_float;
      p->c_type = c_scalar;
      return;
    } else
      type_error(p->linenum,"assignment_op: l and r not INT or FLOAT");
  } else
    type_error(p->linenum,"assignment_op: unknown type");
}

plus_minus_op(struct entry *p, struct entry *l, struct entry *r) {
  if (!p->right) { /* it is unary minus or unary plus */
    if (l->t_type == t_int || l->t_type == t_float) {
      p->e_type = l->e_type;
      p->t_type = l->t_type;
      p->c_type = l->c_type;
      return;
    } else
      type_error(p->linenum,"plus_minus_op: unary");
  } else if (l->t_type == r->t_type && l->c_type == r->c_type) {
    p->e_type = e_var;
    p->t_type = l->t_type;
    p->c_type = l->c_type;
    return;
  } else if (l->t_type == r->t_type &&
             (l->c_type == t_int || l->t_type == t_float) &&
             ((l->c_type == c_scalar || l->c_type == c_pointer) &&
              (r->c_type == c_scalar || r->c_type == c_pointer))) {
    p->e_type = e_var;
    p->t_type = l->t_type;
    p->c_type = l->c_type;
    return;
  } else if (l->c_type == c_pointer && r->t_type == t_int) {
    if (l->t_type != t_char) {
      p->right = make_node(X4, r, NULL);
      p->right->e_type = e_var;
      p->right->t_type = l->t_type;
      p->right->c_type = c_pointer;
    }
    p->e_type = e_var;
    p->t_type = l->t_type;
    p->c_type = c_pointer;
    return;
  } else if (r->c_type == c_pointer && l->t_type == t_int) {
    if (r->t_type != t_char) {
      p->left = make_node(X4, l, NULL);
      p->left->e_type = e_var;
      p->left->t_type = r->t_type;
      p->left->c_type = c_pointer;
    }
    p->e_type = e_var;
    p->t_type = r->t_type;
    p->c_type = c_pointer;
    return;
  } else if (l->t_type == t_int && r->t_type == t_float) {
    p->left = make_node(ITOF, l, NULL);
    p->left->t_type = t_float;
    p->left->c_type = c_scalar;
    p->left->e_type = e_var;
    p->e_type = e_var;
    p->t_type = t_float;
    p->c_type = c_scalar;
    return;
  } else if (r->t_type == t_int && l->t_type == t_float) {
    p->right = make_node(ITOF, r, NULL);
    p->right->t_type = t_float;
    p->right->c_type = c_scalar;
    p->right->e_type = e_var;
    p->e_type = e_var;
    p->t_type = t_float;
    p->c_type = c_scalar;
    return;
  } else
    type_error(p->linenum,"plus_minus_op: not unary");
}

mul_div_op(struct entry *p, struct entry *l, struct entry *r) {
  /*		int	float	*char	*int	*float
        int	1	itof
        float	itof	1
        *char
        *int
        *float						*/

  if (!p->right) { /* it is an indirection op */
    if (l->c_type == c_pointer) {
      p->node_type = DEF;
      p->e_type = e_var;
      if (l->t_type == t_char)
        p->t_type = t_int;
      else
        p->t_type = l->t_type;
      p->c_type = c_scalar; /* not sure this is correct */
      return;
    } else
      type_error(p->linenum,"mul_div_op: indirection");
  }
  if (l->t_type == r->t_type && (l->t_type == t_int || l->t_type == t_float) &&
      ((l->c_type == c_scalar || l->c_type == c_pointer) &&
       (r->c_type == c_scalar || r->c_type == c_pointer))) {
    p->e_type = e_var;
    p->t_type = l->t_type;
    p->c_type = l->c_type;
    return;
  } else if (l->c_type != c_scalar || r->c_type != c_scalar)
    type_error(p->linenum,"mul_div_op: not indirection");
  else if (l->t_type == t_int && r->t_type == t_float) {
    p->left = make_node(ITOF, l, NULL);
    p->left->t_type = t_float;
    p->left->c_type = c_scalar;
    p->left->e_type = e_var;
    p->e_type = e_var;
    p->t_type = t_float;
    p->c_type = c_scalar;
    return;
  } else if (r->t_type == t_int && l->t_type == t_float) {
    p->right = make_node(ITOF, r, NULL);
    p->right->t_type = t_float;
    p->right->c_type = c_scalar;
    p->right->e_type = e_var;
    p->e_type = e_var;
    p->t_type = t_float;
    p->c_type = c_scalar;
    return;
  } else
    type_error(p->linenum,"mul_div_op");
}

void type_error(int line, char *str) {
  printf("\n*** Type mismatch in line %d: %s\n", line, str);
  exit(1);
}
