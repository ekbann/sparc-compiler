int printf(char *fmt, int a);
int putchar(int a);
int ary[10];

void dump_array() {
  int i;

  for (i = 0; i < 10; i++)
    printf("%4d", ary[i]);
  putchar('\n');
  /* debug(symtab_dump) */
}
/* debug(statement_dump) */
