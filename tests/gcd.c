int printf(char *fmt, int a, int b);

int gcd(int u, int v) {
  int t;

  while (u > 0) {
    if (u < v) {
      t = u;
      u = v;
      v = t;
    }
    u = u - v;
  }
  return v;
}
