int main() {
  int i, j, k;

  ;  /* null statement */
  3; /* expression statements */
  -3;
  i + 3;
  i + 3 * j - 4;
  (i + 3) / (j - 4);
  i > j;
  i <= j + 4;
  i<j && k> 4;
  i<j && k> 4 || i == 3;
  i = j + 3;
  i = j = k - 2;
  do
    i++;
  while (j >= 3);
  while (i != 4) {
    j--;
    ++k;
  }
  for (i = 3; i < 20; i--)
    i = j % 3;
  if (!i)
    i = 3 * 4;
  if (j)
    i++;
  else
    i--;
  return k - 3 * 4;
}
