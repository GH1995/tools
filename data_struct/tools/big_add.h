char *bigadd(char a[], char b[]) {
  int ia[200] = {0};
  int ib[200] = {0};

  int len_a = strlen(a);
  int i = len_a - 1;

  int k = 0;
  while (i >= 0)
    ia[k++] = a[i--] - '0';

  int len_b = strlen(b);
  i = len_b - 1;

  k = 0;
  while (i >= 0)
    ib[k++] = b[i--] - '0';
  /*----------------------------------*/

  int d = 0;
  k = len_a > len_b ? len_a : len_b;
  i = 0;
  while (i < k) {
    ib[i] += ia[i] + d;
    d = ib[i] / 10;
    ib[i] %= 10;
    i++;
  }

  if (d > 0)
    ib[k] += d;
  else
    k--;

  for (int i = k; i >= 0; i--)
    b[k - i] = ib[i] + '0';
  b[k + 1] = '\0';

  return b;
}
