int printf(char *fmt, int a, int b);
int ary[10];

void main() {
  int i;

  for (i = 0; i < 10; i++)
    ary[i] = i + 1;
  for (i = 0; i < 10; i++)
    printf("ary[%d] = %d\n", i, ary[i]);
}
