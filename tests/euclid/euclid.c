int printf(char *fmt, int a, int b, int c);
int scanf(char *fmt, int *a, int *b);
int gcd(int u, int v);

main() {
  int x, y, EOF;

  EOF = -1;
  x = 200;
  y = 300;

  while (scanf("%d %d", &x, &y) != EOF)
    if (x > 0 && y > 0)
      printf("Greatest common divisor of %d and %d is %d.\n", x, y, gcd(x, y));
  /* debug(symtab_dump) */
}
/* debug(statement_dump) */
