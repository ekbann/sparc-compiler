int printf(char *fmt, int a);

void main() {
  int i;
  int a[5];

  i = 2;
  a[2 * i] = i + 4 * i - i;
  printf("i = %d\n", i);
  printf("a[2*i] = i+4*i-i = %d\n", a[2 * i]);
}
