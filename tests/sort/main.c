int printf(char *fmt, int a);
int putchar(int c);
void init();
void dump_array();
void sort(int n);
int ary[10];

int main() {
  int i, n;

  init();
  dump_array();
  sort(10);
  dump_array();
  return (0);
  /* debug(symtab_dump) */
}
/* debug(statement_dump) */
