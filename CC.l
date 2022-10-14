%{

#include "globals.h"
#include "CC.tab.h"		/* to define tokens */
YYSTYPE yylval;			/* to define yylval */

/* C code to be inserted before the lex code */

%}

%x	COMMENT

ws		[ \t]+
cr		[\n]
letter		[A-Za-z]
digit		[0-9]
num		{digit}+
snum		[+-]?(num)
fnum1		(({num}\.{num}?)|({num}?\.{num}))([eE]{snum})?
fnum2		({num}[eE]{snum})
float		({fnum1}|{fnum2})[1LfF]?
id		{letter}({letter}|{digit}|_)*
oct		[0-7]
hex		({digit}|[A-Fa-f])
dec		[1-9]{digit}*
int		({dec}|0{oct}*|0[xX]{hex}+)[uU]?[lL]?
escseq		\\(.|{oct}{1,3}|x{hex}{1,2})
char		\'({escseq}|[^\\\'\n])+\'
string1		\"({escseq}|[^\\\"\n])*\"
string2		\"(({escseq}|[^\\\"\n]}*\\[\t ]*\n)+({escseq}|[^\\\"\n])*\"
string		({string1}|{string2})
spchar		[\;\,\:\&\=\+\-\*\/\!\[\]\.\{\(\}\)]
tokenliston	"debug(token_listing_on)"
tokenlistoff	"debug(token_listing_off)"
nodedumpon	"debug(node_dump_on)"
nodedumpoff	"debug(node_dump_off)"
symtabdump	"debug(symtab_dump)"
symtabstats	"debug(symtab_stats)"
statementdump	"debug(statement_dump)"
commenton	"debug(comment_on)"
commentoff	"debug(comment_off)"
halt		"debug(halt)"

%%

{ws}		{/* ignore white space not including <CR> */}
{cr}		{linenum++;}
"/*"		{BEGIN COMMENT;}
<COMMENT>{tokenliston}		{token_listing = TRUE;}
<COMMENT>{tokenlistoff}		{token_listing = FALSE;}
<COMMENT>{nodedumpon}		{node_dump = TRUE;}
<COMMENT>{nodedumpoff}		{node_dump = FALSE;}
<COMMENT>{statementdump}	{statement_dump = TRUE;}
<COMMENT>{symtabdump}		{symtab_dump();}
<COMMENT>{symtabstats}		{symtab_stats();}
<COMMENT>{commenton}		{comment = TRUE;}
<COMMENT>{commentoff}		{comment = FALSE;}
<COMMENT>{halt}			{printf("\n*** COMPILER HALTED\n\n"); exit(o);}
<COMMENT>.			{/* ignore comment */}
<COMMENT>\n			{linenum++;}
<COMMENT>"*/"			{BEGIN INITIAL;}
^#.*\n		{/* ignore all lines starting with a # directive */}
"&&"		{debug(yytext); return(AND);}
"||"		{debug(yytext); return(OR);}
"++"		{debug(yytext); return(INC);}
"--"		{debug(yytext); return(DEC);}
"->"		{debug(yytext); return(STRCTPTR);}
">>"		{debug(yytext); return(SHIFTR);}
"<<"		{debug(yytext); return(SHIFTL);}
"=="		{debug(yytext); return(EQUAL);}
"!="		{debug(yytext); return(NOT_EQUAL);}
"<="		{debug(yytext); return(LE);}
">="		{debug(yytext); return(GE);}
"<"		{debug(yytext); return(LT);}
">"		{debug(yytext); return(GT);}
char		{debug(yytext); return(CHAR);}
do		{debug(yytext); return(DO);}
float		{debug(yytext); return(FLOAT);}
else		{debug(yytext); return(ELSE);}
extern		{debug(yytext); return(EXTERN);}
for		{debug(yytext); return(FOR);}
if		{debug(yytext); return(IF);}
int		{debug(yytext); return(INT);}
return		{debug(yytext); return(RETURN);}
void		{debug(yytext); return(VOID);}
while		{debug(yytext); return(WHILE);}
register	{debug(yytext); return(REGISTER);}
struct		{debug(yytext); return(STRUCT);}
double		{debug(yytext); return(DOUBLE);}
sizeof		{debug(yytext); return(SIZEOF);}
static		{debug(yytext); return(STATIC);}

{spchar}	{debug(yytext); yylval.token = yytext[0]; return(*yytext);}

{id}		{
		 if (yylval.symp lookup (yytext)) { /* if string exists */
		   yylval. symp->references--;	/* false count */
		   yylval. lexeme yylval.symp->lexeme; /* use it; save mem */
		 }
		 else {	/* if not, allocate mem for new lexeme */
		   yylval. lexeme = (char *)malloc(yyleng+2);
		   strcpy (yylval. lexeme, yytext);
		 }
		 if (token_listing)
		   debug_entry (ID, yytext);
		 return (ID);
		}

{int}		{
		 if (yylval.symp = lookup(yytext)) {	/* if string exists */
		   yylval.symp->references--;		/* false count	    */
		   yylval.lexeme = yylval.symp->lexeme; /* use it; save mem */
		 }
		 else {		/* if not, allocate mem for new lexeme */
		   yylval. lexeme = (char *) malloc(yyleng+1);
		   strcpy(yylval.lexeme, yytext);
		 }
		 if (token_listing)
		   debug_entry(ICON, yytext);
		 return(ICON);
		}

{float}		{
		 if (yylval.symp = lookup(yytext)) {	/* if string exists */
		   yylval.symp->references--;		/* false count	    */
		   yylval.lexeme = yylval.symp->lexeme; /* use it; save mem */
		 }
		 else {		/* if not, allocate mem for new lexeme */
		   yylval.lexeme = (char *) malloc(yyleng+3);
		   strcpy(yylval.lexeme, yytext);
		 }
		 if (token_listing)
		   debug_entry(FCON, yytext);
		 return(FCON);
		}

{char}		{
		 if (yylval.symp = lookup(yytext)) {	/* if string exists */
		   yylval.symp->references--;		/* false count	    */
		   yylval.lexeme = yylval.symp->lexeme; /* use it; save mem */
		 }
		 else {		/* if not, allocate mem for new lexeme */
		   yylval.lexeme = (char *) malloc(yyleng+1);
		   strcpy(yylval.lexeme, yytext);
		 }
		 if (token_listing)
		   debug_entry(CCON, yytext);
		 return(CCON);
		}

{string}	{
		 if (yylval.symp = lookup(yytext)) {	/* if string exists */
		   yylval.symp->references--;		/* false count	    */
		   yylval.lexeme = yylval.symp->lexeme; /* use it; save mem */
		 }
		 else {		/* if not, allocate mem for new lexeme */
		   yylval.lexeme = (char *) malloc(yyleng+1);
		   strcpy(yylval.lexeme, yytext);
		 }
		 if (token_listing)
		   debug_entry(SCON, yytext);
		 return(SCON);
		}
		{if (token_listing) {
		      num_illegal++;
		      printf("%d: <illegal, %s>\n", linenum, yytext);
		   }
		   return(ILLEGAL);
		}

%%

/* define a more informative YYERROR() function */

void yyerror(const char *msg)
{
  static errors = 10;

  printf("%d: %s at '%s'\n", linenum, msg, yytext);
  if (! --errors)
    exit(1);
}  