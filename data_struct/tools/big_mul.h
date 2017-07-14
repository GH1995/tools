char *bigmul(char *sa, char *sb, char *sc) {
  int a[200] = {0};
  int b[200] = {0};

  int len_a = strlen(sa);
  int i = len_a - 1;

  int k = 0;
  while (i >= 0)
    a[k++] = sa[i--] - '0';

  int len_b = strlen(sb);
  i = len_b - 1;
  k = 0;
  while (i >= 0)
    b[k++] = sb[i--] - '0';

  int c[400] = {0};
  for (int i = 0; i < len_a; i++)
    for (int j = 0; j < len_b; j++)
      c[i + j] += a[i] * b[j];

  k = 399;
  while (k >= 0 && c[k] == 0)
    k--;

  i = 0;
  int d = 0;
  while (i <= k) {
    c[i] += d;
    d = c[i] / 10;
    c[i] %= 10;
    i++;
  }

  while (d > 0) {
    c[i] = d % 10;
    d /= 10;
    i++;
  }

  k = i;
  for (int i = k - 1; i >= 0; i--)
    sc[k - 1 - i] = c[i] + '0';
  sc[k] = '\0';

  return sc;
}
