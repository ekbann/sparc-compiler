int printf(char *fmt, int x, int y);

void main() {
  int a, b;
  a = 0;
  b = 0;
  {
    int b;
    b = 1;
    {
      int a;
      a = 2;
      printf("a=%d, b=%d\n", a, b);
    }
    {
      int b;
      b = 3;
      printf("a=%d, b=%d\n", a, b);
    }
    printf("a=%d, b=%d\n", a, b);
  }
  printf("a=%d, b=%d\n", a, b);
/* debug(symtab_dump) */
}
/* debug(statement_dump) */
