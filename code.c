#include "globals.h"
#include "CC.tab.h"

/* flag to identify postfix INC/DEC; if true, then INC/DEC the e_var;	*/
/* flag_postfix->node_class field will store info if INC or DEC,	*/
/* i.e. copy of p->node_type						*/

struct entry *flag_postfix = NULL;

/* flag to signal if it is necessary to load a REGISTER variable to	*/
/* an 'out' register as is needed in calls to .mul and .div		*/

int flag_load = 0; /* default is NOT to load */

/* initialize register table */

struct reg reg_tbl[32];

void init_reg_tbl()
{
  int i;

  for (i=0; i<=32; i++)
    reg_tbl[i].free = 0;	/* make all registers not available */
  for (i=16; i<=23; i++)
    reg_tbl[i].free = 1;	/* make %10-17 available */
  for (i=8; i<=13; i++)
    reg_tbl[i].free = 1;	/* make %o0-o5 available */
  for (i=24; i<=29; i++)
    reg_tbl[i].free = 1;	/* make %i0-i5 available */
}

void code(struct entry *p)
{
  if (!p) { /* NULL */
    if (flag_postfix) {	  /* maybe we still have to update variables */
      if (flag_postfix->type.var.m_type == m_register) { /* var in local reg */
	fprintf(fp, "\t%s\t%s",
		flag_postfix->node_class == INC ? "inc" : "dec",
		print_reg(flag_postfix->where));
	if (comment)
	  fprintf(fp, "\t\t\t! %s++", flag_postfix->lexeme);
	putc('\n', fp);
      }
      else {						/* var in stack */
	free_outs();	/* !!! end of STATEMENT, now do INC/DEC */
	load_reg(flag_postfix);	   /* load variable to inc/dec */
	fprintf(fp, "\t%s\t%s",
		flag_postfix->node_class == INC ? "inc" : "dec",
		print_reg(flag_postfix->where));
	if (comment)
	  fprintf(fp, "\t\t\t! %s++", flag_postfix->lexeme);
	putc('\n', fp);
	fprintf(fp, "\tst\t%s, [%%fp%d]\n",
		print_reg (flag_postfix->where),
		flag_postfix->type.var.offset);
	free_reg(flag_postfix);	  /* free reg since we just need to update */
      }
      flag_postfix = NULL;   /* no more postfix variable to update */
    }
    return;
  }
  switch(p->node_type) {
  case STATEMENT:
    if (flag_postfix) {
      if (flag_postfix->type.var.m_type == m_register) { /* var in local reg */
        fprintf(fp, "\t%s\t%s",
		flag_postfix->node_class == INC ? "inc" : "dec",
		print_reg(flag_postfix->where));
	if (comment)
	  fprintf(fp, "\t\t\t! %s++", flag_postfix->lexeme);
	putc('\n', fp);
      }
      else {						/* var in stack */
	free_outs();	/* !!! end of STATEMENT, now do INC/DEC */
	load_reg(flag_postfix);	   /* load variable to inc/dec */
	fprintf(fp, "\t%s\t%s",
		flag_postfix->node_class == INC ? "inc" : "dec",
		print_reg(flag_postfix->where));
	if (comment)
	  fprintf(fp, "\t\t\t! %s++", flag_postfix->lexeme);
	putc('\n', fp);
	fprintf(fp, "\tst\t%s, [%%fp%d]\n",
		print_reg(flag_postfix->where),
		flag_postfix->type.var.offset);
	free_reg(flag_postfix);	  /* free reg since we just need to update */
      }
      flag_postfix = NULL;   /* no more postfix variable to update */
    }
/*  flush_regs();   /* do i really need to flush? how about just free regs? */
    free_outs();    /* this is better because no need to save data */
    code (p->left);
    code (p->right);
    break;
  case Do: {
    char loop[6];
    fprintf(fp, "%s:\n", newlabel(loop, 'L'));
    code(p->left);
    free_reg(p->left);	 /* end of STATEMENT; not needed anymore */
    code(p->right);
    fprintf(fp, "\ttst\t%s\n", print_reg(p->right->where));
    fprintf(fp, "\tbne\t%s\n\tnop\n", loop);
  }
    break;
  case WHILE: {
    char loop[6], test[6];
    newlabel(loop, 'L');
    fprintf(fp, "\tba\t%s\n\tnop\n", newlabel(test, 'L'))
    fprintf(fp, "%s:\n", loop);
    code(p->right);
    fprintf(fp, "%s:\n", test);
    code(p->left);
    fprintf(fp, "\ttst\t%s\n", print_reg (p->left->where));
    fprintf(fp, "\tbne\t%s\n\tnop\n", loop);
  }
    break;
  case INC:
  case DEC: {
    int r;
    if (p->node_class == PREFIX) {		   /* if PREFIX, inc/dec_now */
      if (p->left->type.var.m_type == m_register) {	 /* var in local reg */
	fprintf(fp, "\t%s\t%s",
		p->node_type == INC ? "inc" : "dec",
		print_reg(p->left->where));
	if (comment)
	  fprintf(fp, "\t\t\t! ++%s", p->left->lexeme);
	putc('\n', fp);
	/* now load REGISTER variable if needed */
	if (flag_load) {      /* if need to load, update location of operand */
	r = p->left->where;	   /* need to make copy since it gets erased */
fprintf(fp, "\tmov\t%s, %s\n",
	print_reg(r), print_reg(get_reg(p->left)));
}
p->where = p->left->where;	/* let '++' NODE know where operand is */
}
else {						/* var in stack */
load_reg (p->left);	/* load variable to inc/dec */
fprintf(fp, "\t%s\t%s",
	p->node_type == INC ? "inc" : "dec",
	print_reg(p->left->where));
if (comment)
fprintf(fp, "\t\t\t! ++%s", p->left->lexeme);
putc('\n', fp);
fprintf(fp, "\tst\t%s, [%%fp%d]\n",
	print_reg(p->left->where),
	p->left->type.var.offset);
free_reg(p->left);
get_reg (p);
}
}
else { /* it is POSTFIX; store variable in flag_postfix */
flag_postfix = p->left;
if (p->node_type == INC)
flag_postfix->node_class = INC;
else
flag_postfix->node_class = DEC;
load_reg (p->left);	/* load untouched variable */
free_reg (p->left);
get_reg (p);
}
}
break;
case X4:
code(p->left);
fprintf(fp, "\tsll\t%s, 2",
	print_reg(p->left->where));
free_reg(p->left);
get_reg(p);
fprintf(fp, ", %s\n", print_reg(p->where));
break;
case ARRAY: {
int r;
code(p->right);	   /* code the array index */
if (p->left->type.var.m_type == m_extern) {
fprintf(fp, "\tset\t%s, %s\n",
	p->left->lexeme,
	print_reg(r = get_reg(p->left)));
fprintf(fp, "\tadd\t%s, %s",
	print_reg(r),
	print_reg(p->right->where));
free_reg (p->left);
}
else
fprintf(fp, "\tadd\t%d, %s",
	p->left->type.var.offset,
	print_reg(p->right->where));
free_reg(p->right);
get_reg(p);
fprintf(fp, ", %s\n", print_reg(p->where));
}
break:
case DEF:
code(p->left);    /* code the pointer */
if (p->left->left->type.var.m_type == m_extern)
fprintf(fp, "\tld\t[%s]",
	print_reg(p->left->where));
else
fprintf(fp, "\tld\t[%%fp+%s]",
	print_reg(p->left->where));
free_reg(p->left);
get_reg(p);
fprintf(fp, ", %s\n", print_reg(p->where));
break;
case RETURN:
if (!p->left)			/* simply RETURN */
fprintf(fp, "\tret\n\trestore\n");
else {				/* RETURN <expression> */
flush_one_reg(8);		/* flush %00 */
code(p->left);
fprintf(fp, "\tret\n\trestore\t%%g0, %s, %%o0\n",
	print_reg(p->left->where));
}
break;
case CALL: {
int flushed = 0;	/* flag if parameters are out of order due to flushing */
int n = 0;		/* keep track of the number of parameters */
struct entry *parm;

flag_load= 1;
if (parm = p->right) { /* are there any arguments? */
flush_regs();	/* yes; then flush all out registers */
while (parm) {
n++;
if (n < 7) { /* only six parms can go in %o0-o5 */
code(parm->left->right);
if(parm->left->right->where != (7+n))
flushed = 1; /* parameter not in register it should be in */
parm = parm->right;
}
else { /* the rest has to go to the stack */
/* NOT IMPLEMENTED YET */
printf("!!! Function called with more than 6 parameters\n");
exit(1);
}
}
if (flushed) { /* some parms got flushed; so flush all and load all */
parm = p->right;
flush_regs();	/* flush 'out of order' parameters */
for (flushed = n; flushed > 0; flushed--) {
load_reg(parm->left->right);
parm = parm->right;
}
}
}
flag_load = 0;
fprintf(fp, "\tcall\t%s\n\tnop\n", p->left->lexeme);
free_outs();
if (p->c_type == c_scalar)	/* function called returns a value */
get_reg (p);	/* must save it for whomever wants it */
}
break;
case '&':
/* returns the address of an object in memory only, i.e. variables and */
/* array elements, not applicable to expressions, constants, or REGISTER */
if (p->left->node_type == ARRAY) {
code(p->left);
free_reg(p->left);
get_reg(p);
}
else if ((p->left->e_type == e_var) &&    
(p->left->type.var.m_type != m_register)) {
fprintf(fp, "\tadd\t%%fp, %d, %s",
p->left->type.var.offset,
print_reg (get_reg (p)));
if (comment)
fprintf(fp, "\t\t! &%s", p->left->lexeme);
putc('\n', fp);
}
break;
case IF: {
char lt[6], lf[6];
code(p->left);
fprintf(fp, "\ttst\t%s\n", print_reg(p->left->where));
fprintf(fp, "\tbe\t%s\n\tnop\n", newlabel(lf, 'L'));
free_reg(p->left);
if (p->right->node_type != ELSE) {
code(p->right);
fprintf(fp, "%s:\n", lf);
}
else {
code(p->right->left);
flush_regs();
fprintf(fp, "\tba\t%s\n\tnop\n", newlabel(lt, 'L'));
fprintf(fp, "%s:\n", lf);
code(p->right->right);
fprintf(fp, "%s:\n", lt);
}
{
break;
case AND: {
char 1[6]; /* label */
code(p->left);
fprintf(fp, "\ttst\t%s\n", print_reg(p->left->where));
fprintf(fp, "\tbe\t%s\n", newlabel (1, 'L'));
fprintf(fp, "\tclr\t%s\n", print_reg(p->left->where));
free_reg(p->left);
code(p->right);
fprintf(fp, "\ttst\t%s\n", print_reg(p->right->where));
fprintf(fp, "\tbe\t%s\n", 1);
fprintf(fp, "\tclr\t%s\n", print_reg(p->right->where));
free_reg(p->right);
fprintf(fp, "\tmov\t1, %s\n%s:\n", print_reg(get_reg(p)), 1);
}
break;
case OR: {
char 1[6];	/* label */
code(p->left);
fprintf(fp, "\ttst\t%s\n", print_reg(p->left->where));
fprintf(fp, "\tbne\t%s\n", newlabel (1, 'L'));
fprintf(fp, "\tmov\t1, %s\n", print_reg (p->left->where));
free_reg (p->left);
code(p->right);
fprintf(fp, "\ttst\t%s\n", print_reg(p->right->where));
fprintf(fp, "\tbne\t%s\n", 1);
fprintf(fp, "\tmov\t1, %s\n", print_reg(p->right->where));
free_reg(p->right);
fprintf(fp, "\tclr\t%s\n%s:\n", print_reg(get_reg(p)), 1);
}
break;
case EQUAL:
case NOT_EQUAL:
case GT:
case GE:
case LT:
case LE: {
char 1[6];
code(p->left);
code(p->right);
check_operands(p);
fprintf(fp, "\tcmp\t%s, %s\n", print_reg(p->left->where),
	print_reg(p->right->where));
free_reg(p->left);
free_reg(p->right);
fprintf(fp, "\t%s\t%s\n", inv_relop(p->node_type), newlabel(1, 'L'));
fprintf(fp, "\tclr\t%s\n", print_reg(get_reg(p)));
fprintf(fp, "\tmov\t1, %s\n%s:\n", print_reg(p->where), 1);
}
break;
case '=': {
code(p->right);		  /* evaluate what has to be stored */
if (p-left-node_type == DEF) {       /* pointer expression? */
code (p->left->left);	  /* eval the expression */
if (!p->right->where]	  /* if it got flushed */
load_reg(p->right);	  /* load it */
if (p-left->left->left->type.var.m_type == m_extern) /* extern array */
fprintf(fp, "\tst\t%s, [%s]\n",
	print_reg(p->right->where),
	print_reg(p->left->left->where));
else
fprintf(fp, "\tst\t%s, [%%fp+%s]\n",
	print_reg(p->right->where),
	print_reg(p->left->left->where));
free_reg(p->right);
get_reg)p);
free_reg(p->left->left);  /* don't need LVAL but keep RVAL */
break;

else {			/* must be a variable name */
if (p-left-type.var.m_type == m_extern) { /* an external? */
fprintf(fp, "\tset\t%s, %s\n", p->left->laxeme,
	print_reg(get_reg(p->left)));
fprintf(fp, "\tst\t%s, [%s]\n",
	print_reg(p->right->where),
	print reg(p-left->where});
free regip->right);	/* I ADDED THIS. IS IT REQUIRED? */
get_reg(p);
free_regip->left);
}
else if (p-left->where( {		/* in a register */
fprintf(fp, "\tmov\t%s\n", print_reg(p->right->where),
	print_reg(p-left->where));
free_reg(p->right);  /* I ADDED THIS. IS IT REQUIRED? */
get_reg(p);
}
else {			/* no store it on the stack */
fprintf(fp, "\tst\t%s, [%%fp%d]\n",
	print_reg(p->right->where),
	p->left->type.var.offset); /* this was changed */
free_reg(p->right);  /* I ADDED THIS. IS IT REQUIRED? */
get_reg(p);
}
return;
}
if (!p-left->where)
load_reg(p->right);		/* load right if necessary */
fprintf(fp, "\tst\t%s, [%s]\n", print_reg(p->right->where),
	print_reg(p-left->where));
free_reg(p->right);
get_reg(p);
free reg(p->left);
}
break;
case '+':
case '-':
if (!p->right) { /* UNARY */
code (p->left);
fprintf(fp, "\tsub\t%%g0, %s, ", print_reg(p->left->where));
free_reg(p->left);
get_reg(p);
fprintf(fp, "%s\n", print_reg(p->where));
}
else {
code(p->left);
code(p->right);
check_operands(p);  /* check if both operands are in registers */
fprintf(fp, "\t%s\t%s, %s", p->node_type == '+' ?
	"add" : "sub", print_reg(p->left->where),
	print_reg (p->right->where));
free_reg (p->left);
free_reg (p->right);
get_reg (p);
fprintf(fp, ", %s\n", print_reg(p->where));
}
break;
case '*':
case '/':
case '%':
flush_one_reg (8);	/* flush %o0 register */
flush_one_reg (9);	/* flush %ol register */
flag_load = 1;		/* load REGISTER variables if encountered */
code(p->left);		/* goes into %o0 */
code(p->right);		/* goes into %o1 */
if ((p->right->where == 8) &&
((p->node_type == '/') || (p->node_type == '%'))) {
/* p->right is in %o0 (i.e. p->left got flushed) and function is '/' */
/* or '%'; must put p->right in %o1 and load p->left in %o0	     */
fprintf(fp, "\tmov\t%%o0, %s\n", print_reg(get_reg(p->right)));
reg_tbl[8].free = 1; 	/* free %00 for p->left */
load_reg (p->left); 	/* loads p->left in %o0 if '/' */
}
else if ((p->right->where == 8) && (p->node_type == '*'))
load_reg (p->left); 	/* loads p->left in %o1 if '*' */
flag_load= 0;	      /* reset load REGISTER to false */
if (p->node_type == '%')
fprintf(fp, "\tcall\t.rem\n");
else
fprintf(fp, "\tcall\t.%s\n", p->node_type == '*' ? "mul" : "div");
fprintf(fp, "\tnop\n");
free_reg(p->left);	/* frees %o0 */
free_reg(p->right);	/* frees %o1 */
get_reg (p);		/* assign result to %o0 */
break;
case LEAF:
load_reg(p);
break;
default:
}
}
void free_reg(struct entry *p)
{
reg_tbl[p->where].free = 1;
if (p->e_type == e_var) { .
if (p->type.var.m_type == m_none)
p->where = 0;
else if (p->type.var.m_type == m_register)
p->where = p->type.var.reg;
}
}

int get_local(struct entry *p)
{
int i;

for (i=16; i <= 23; i++)
if (reg_tbl[i].free) {
reg_tbl[i].free = 0;	/* no longer available */
reg_tbl[i].node = p;	/* being used by p     */
return i;
}
return 0;
}
int get_in(struct entry *p)
{
int i;

for (i=24; i <= 29; i++)
if (reg_tbl[i].free) {
reg_tbl[i].free = 0;	/* no longer available */
reg_tbl[i].node = p;	/* being used by p     */
return i;
}
printf("!!! Function has more than 6 parameters\n");
exit(1);
/* return 0; */
}

int get_reg(struct entry *p)
{
int i;

for (i=8; i <= 13; i++)
if (reg_tbl[i].free) {
reg_tbl[i].free = 0;	/* no longer available */
reg_tbl[i].node = p;	/* being used by p */
p->where = i;		/* indicate in symbol entry */
return 1;
}
flush_regs();		/* no more out registers; flush it */
return get_reg (p);	/* return a fresh out register */
}

char * print_reg (int reg)
{
switch (reg) {
case g0: return("%g0");
case g1: return("%g1");
case g2: return("%g2");
case g3: return("%g3");
case g4: return("%g4");
case g5: return("%g5");
case g6: return("%g6"):
case g7: return("%g7"):
case o0: return("%o0"):
case o1: return("%o1"):
case o2: return("%o2"):
case o3: return("%o3"):
case o4: return("%o4"):
case o5: return("%o5"):
case o6: return("%o6");
case o7: return("%o7");
case l0: return("%l0");
case l1: return("%l1");
case l2: return("%l2");
case l3: return("%l3");
case l4: return("%l4");
case l5: return("%l5");
case l6: return("%l6");
case l7: return("%l7");
case i0: return("%i0");
case i1: return("%i1");
case i2: return("%i2");
case i3: return("%i3");
case i4: return("%i4");
case i5: return("%i5");
case i6: return("%i6");
case i7: return("%i7");
default: printf("\n!!! Unknown Register\n"); exit(1);
}
}
void check_operands(struct entry *p)
{
if (!p->left->where) {		/* operand in a register? */
if (!check_regs())		/* no; any free out register? */
flush_regs();			/* no; flush out registers */
load_reg(p->left);		/* load left operand */
}
if (!p->right->where) {		/* operand in a register? */
if (!check_regs())		/* no; any free out register? */
flush_regs ();			/* no; flush out registers */
load_reg(p->left);		/* load left since it got flushed */
load_reg(p->right);		/* load right operand */
}
}
int check_regs()
{
int i, flag = 0; /* flag = TRUE if there is an available out register */

for (i=8; i<=13; i++)
if (reg_tbl[i].free)
flag = 1;
return flag;
}

int load_reg(struct entry *p)
{
int r = 0; /* returns the register allocated if any */

if (p->node_type != LEAF) {
fprintf(fp, "\tld\t[%%fp%d], %s",
	p->type.var.offset,
	print_reg (r = get_reg(p)));
if (comment)
fprintf(fp, "\t\t! expression");
putc('\n', fp);
}
else if (p->e_type == e_const) {
if (p->token == SCON) {
fprintf(fp, "\tset\t%s, %s",
	p->type.con.label,
	print_reg(r = get_reg(p)));
if (comment)
    fprintf(fp, "\t\t! %s", p->lexeme);
    putc('\n', fp);
}
else if (p->token == CCON) {
int c;
if ((c = (int)*(p->lexeme+1)) == 92)
switch ((int)*(p->lexeme+2)) {
case 'a': c = 7; break;    /* bell */
case 'b': c = 8; break;    /* backspace */
case 'f': c = 12; break;   /* formfeed */
case 'n': c = 10; break;   /* newline */
case 'r': c = 13; break;   /* carriage return */
case 't': c = 9; break;    /* htab */
case 'v': c = 11; break;   /* vtab */
case 92	: c = 92; break;   /* backslash */
case '"': c = 63; break;   /* question mark */
case 96	: c = 96; break;   /* single quote */
case '"': c = 34; break;   /* double quote */
case 'x':
default:   /* HEX and OCTAL not implemented */
}
fprintf(fp, "\tmov\t%d, %s",
	c,
	print_reg (r = get_reg(p)));
if (comment)
fprintf(fp, "\t\t\t! %s", p->lexeme);
putc('\n', fp);
}
else if (p->token == ICON)
fprintf(fp, "\tmov\t%d, %s\n",
	atoi(p->lexeme),
	print_reg(r = get_reg (p)));
}
else if (p->e_type == e_var) {
if (p->type.var.m_type == m_none) {
fprintf(fp, "\tld\t [%%fp%d], %s",
	p->type.var.offset,
	print_reg(r = get_reg (p)));
if (comment)
fprintf(fp, "\t\t! %s", p->lexeme);
putc('\n', fp);
}
else if (p->type.var.m_type == m_register && flag_load) {
fprintf(fp, "\tmov\t%s, %s",
	print_reg(p->type.var.reg),
	print_reg(r = get_reg(p)));
if (comment)
fprintf(fp, "\t\t! %s", p->lexeme);
putc('\n', fp);
}
else if (p->type.var.m_type == m_extern) {
fprintf(fp, "\tset\t%s, %s\n", p->lexeme,
	print_reg (r = get_reg(p)));
free_reg(p);
fprintf(fp, "\tld\t[%s], %s\n",
	print_reg(r),
	print_reg(get_reg(p)));
r = p->where;
}
}
return r;
}

void flush_one_reg(int i)
{
if (!reg_tbl[i].free) {
if (reg_tbl[i].node->node_type == LEAF) {
if (reg_tbl[i].node->e_type == e_var) {
if (reg_tbl[i].node->type.var.m_type == m_none) {
fprintf(fp, "\tst\t%s, [%%fp%d]",
	print_reg(reg_tbl[i].node->where),
	reg_tbl[1].node->type.var.offset);
if (comment)
fprintf(fp, "\t\t! flushing %%o%d register (%s)",
	i-8, reg_tbl[i].node->lexeme);
putc('\n', fp);
reg_tbl[i].node->where = 0;  /* not in out register anymore */
}
else if (reg_tbl[i].node->type.var.m_type == m_register) {
fprintf(fp, "\tmov\t%s, %s",
	print_reg(reg_tbl[i].node->where),
	print_reg(reg_tbl[i].node->type.var.reg));
if (comment)
fprintf(fp, "\t\t! flushing %%o%d register (%s)",
	i-8, reg_tbl[i].node->lexeme);
putc('\n', fp);
reg_tbl[i].node->where = reg_tbl[i].node->type.var.reg;
}
else if (reg_tbl[i].node->type.var.m_type == m_extern) {
reg_tbl[i].node->where = 0;
}
}
if (reg_tbl[i].node->e_type == e_const)
reg_tbl[i].node->where = 0;     /* not in out register anymore */
}
if (reg_tbl[i].node->node_type != LEAF) {
/* non-LEAF nodes have no allocated space to flush into   */
/* therefore must create one in the stack of correct size */
fprintf(fp, "\tst\t%s", print_reg(reg_tbl[i].node->where));
if ((reg_tbl[i].node->t_type == t_int) ||
(reg_tbl[i].node->t_type == t_float))
fprintf(fp, ", [%%fp%d]",
reg_tbl[i].node->type.var.offset = align (4,4));
else if (reg_tbl[i].node->t_type == t_char)
fprintf(fp, ", [%%fp%d]",
reg_tbl[i].node->type.var.offset = align (1,1));
if (comment)
fprintf(fp, "\t\t! flushing %%o%d register (expression)", i-8);
putc('\n', fp);
reg_tbl[i].node->where = 0;	/* not in out register anymore */
}
reg_tbl[i].free = 1;		/* register is free now */
}
}
void flush_regs()
{
int i;

for (i=8; i<=13; i++)
flush_one_reg(i);
}
void free_outs()
{
int i;
for (i=8; i<=13; i++). {
if (!reg)tbl[i].free) {
reg_tbl[i].free = 1;
if (reg_tbl[i].node->e_type == e_var) {
if (reg_tbl[i].node->type.var.m_type == m_none)
reg_tbl[i].node->where = 0;
else if (reg_tbl[i].node->type.var.m_type == m_register)
reg_tbl[i].node->where = reg_tbl[i].node->type.var.reg;
}
}
}
}
char * newlabel(char* label, char head)
{
static unsigned tails [128];	/* one for each ASCII char, last tail */
register char * p = label;	/* save pointer to label to return */

*label++= head;			/* start with head char */
sprintf(label, "%04d", ++tails[head]); /* create new tail */
label [5] = '\0';		/* add null */
return p;			/* points to label */
}

char * inv_relop(int t)
{
switch (t) {
case GT: return("ble"); break;
case GE: return("bl"); break;
case LT: return("bge"); break;
case LE: return("bg"); break;
case EQUAL: return ("bne"); break;
case NOT_EQUAL: return("be"); break;
}
}

void fn_args()
{
struct entry *fn_parms;

fn_parms = fn_p->type.fn.parameters;
while (fn_parms) {
/* assign an IN register */
fn_parms->type.var.reg = get_in(fn_parms);
fn_parms->where = fn_parms->type.var.reg;
fn_parms->type.var.m_type = m_register;
fn_parms = fn_parms->fn_parms;
}
}