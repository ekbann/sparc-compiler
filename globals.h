/*** globals.h ***/

#include <string.h>             /* for strcpy() used in CC.y */
#include <stdlib.h>             /* for malloc() used in support.c */
#include <stdio.h>		        /* standard i/o */
#include <ctype.h>		        /* character test routines */

#define PRIME 211		        /* a prime number of buckets in hash table */
#define MAX_CONTEXT_LEVELS 256	/* maximum context levels */
#define EOS '\0'		        /* used in hashpjw */
#define TRUE 1			        /* used to toggle flags */
#define FALSE 0			        /* used to toggle flags */

enum entry_type {e_var, e_fn, e_type, e_const, e_field, e_unknown};
enum variable_type {t_void, t_char, t_int, t_float, t_unknown};
enum constructor_type {c_scalar, c_pointer, c_array, c_unknown};
enum modifier_type {m_none, m_extern, m_register};
enum loc_type 	{g0, g1, g2, g3, g4, g5, g6, g7,
		         o0, o1, o2, o3, o4, o5, o6, o7,
		         l0, l1, l2, l3, l4, l5, l6, l7,
		         i0, i1, i2, i3, i4, i5, i6, i7};

/* define a lexeme structure to be used in a hash table linked list 	   */
/* this structure is also used as a node structure from which syntax trees */
/* of statements are made (because they share very similar features)	   */
/* nodes use the fields: node_type e_type c_type t_type *left *right	   */ 
/* a separate structure could have been built but then the parser symbols  */
/* must be assigned the correct symbol value type (very carefully) 	       */
/* now we simply assign all non-terminals to be of type *symp (from union) */

struct entry {
    char *lexeme;
    enum variable_type t_type : 3;
    enum constructor_type c_type : 3;
    enum entry_type e_type : 3;
    enum loc_type where;   /* the register this node is stored in */
    int node_type;	       /* what type of node, i.e. STATEMENT, OR, +, ... */
    int node_class;	       /* the class type, i.e. lval, rval, postfix, ... */
    int token;
    int scope;	
    int references;
    int linenum;
    struct entry *left;
    struct entry *right;
    struct entry *scope_link;
    struct entry *hash_link;
    struct entry *fn_parms;
    union {
        struct variables {
            enum modifier_type m_type;  /* EXTERN or REGISTER?     */
            unsigned width: 3;          /* variable width in bytes */
            int offset : 13;	        /* stack offset 	       */
            enum loc_type reg : 5;      /* register stored in      */
            char * array_length;        /* array length            */ 
        } var;
        struct functions {
            struct entry *parameters;   /* linked list of function parameters */
            char locals[6] ;            /* constant assigned max locals in fn */
        } fn;
        struct constants {
            char label[6] ;            /* label of string */
        } con;
    } type;
};

/* define a register structure to keep track of register usage */

struct reg {
    int free;		        /* is the register free? */
    struct entry *node;	    /* what is in this register? */
};

/* define a hash table of buckets where each bucket represents the start */
/* of an individual symbol table, i.e. a linked list of lexemes. 	     */

extern struct entry *hashtbl[];

/* define a context table of linked lists of entries within the same */
/* context level                                                     */

extern struct entry *context[];

/* define a syntax tree which is the root of the entire program statements */

extern struct entry *syntax_tree;

/* define global variables */

extern FILE *fp;		    /* pointer to code output file */
extern int linenum;		    /* line number counter variable */
extern int token_listing;	/* debug directive; default = off */
extern int statement_dump;	/* debug directive; default = off */
extern int node_dump;		/* debug directive; default = off */
extern int comment;		    /* debug directive; default = off */
extern int context_level;	/* initialize context level */
extern int last_sym;		/* framepointer stack offset */
extern struct entry *fn_p;	/* pointer to function name so that RETURN */
				            /* can check the return argument type.     */ 

/* initialize debug(symtab_stats) counter variables */

extern int num_entry;
extern int num_id;
extern int num_float;
extern int num_int;
extern int num_char;
extern int num_string;
extern int num_illegal;
extern int num_lookup;
extern int num_searched;

/* function prototypes */

void symtab_stats(void) ;
void symtab_dump(void) ;
void debug(char *);
void debug_stats(int);
void debug_entry(int, char *);
void delete_level(void);
void syntax_tree_dump(struct entry *);
void type_error(int, char *);
void free_reg(struct entry *);
void init_reg_tbl();
void flush_one_reg(int);
void flush_regs();
void free_outs();
void check_operands(struct entry *);
void fn_args();
char * print_n_type(int);
char * print_n_class(int);
char * print_t_type(enum variable_type);
char * print_e_type(enum entry_type);
char * print_c_type(enum constructor_type);
char * print_reg(int);
char * newlabel(char *, char);
char * inv_relop(int);
struct entry * lookup(char *);
struct entry * insert(int, char *, int);
struct entry * make_node(int, struct entry *, struct entry *);
void check(struct entry *);
int hashpjw(char *);
int align(int, int);
int get_local(struct entry *);		/* %l0-l7 */
int get_in(struct entry *);		    /* %i0-i5 */
int get_reg(struct entry *);		/* %o0-o5 */
int load_reg(struct entry *);
int check_regs();
void code(struct entry *);
void x4_op(struct entry *, struct entry *);
void def_op(struct entry *, struct entry *);
void array_op(struct entry *, struct entry *, struct entry *);
void mod_op(struct entry *, struct entry *, struct entry *);
void call_op(struct entry *, struct entry *, struct entry *);
void return_op(struct entry *, struct entry *);
void address_op(struct entry *, struct entry *);
void inc_dec_op(struct entry *, struct entry *);
void logical_op(struct entry *, struct entry *, struct entry *);
void relational_op(struct entry *, struct entry *, struct entry *);
void not_op(struct entry *, struct entry *);
void assignment_op(struct entry *, struct entry *, struct entry *);
void plus_minus_op(struct entry *, struct entry *, struct entry *);
void mul_div_op(struct entry *, struct entry *, struct entry *);
