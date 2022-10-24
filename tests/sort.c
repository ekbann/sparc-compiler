int ary[10];

void sort(int n) {
  int gap, i, j;
  int temp;

  for (gap = n / 2; gap > 0; gap = gap / 2)
    for (i = gap; i < n; i++)
      for (j = i - gap; j >= 0 && ary[j] > ary[j + gap]; j = j - gap) {
        temp = ary[j];
        ary[j] = ary[j + gap];
        ary[j + gap] = temp;
      }
}
