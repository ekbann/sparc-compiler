float bas(int a, float b);
int baa(float a, int b);
float foo() {
  int a, b, c;
  char l, m, n;
  float x, y, z;
  int *pi;
  char *pc;
  float *pf;

  pf = &x + 4;
  a = b + l + x;
  m = a * n * z;
  x = (a + b) * (b + c);
  a = *(pc + c);
  a = bas(x + 4, a + 3.5);
  x = baa(x + 4.0, a + 3.5);
  return l + m;
}
/* debug(statement_dump) */
