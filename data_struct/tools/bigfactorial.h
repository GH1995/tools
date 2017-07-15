void prenext(int a[], int k) {
  int d = 0;
  int i;
  for (i = 1; i <= a[0]; i++) {
    a[i] = a[i] * k + d;
    d = a[i] / 10;
    a[i] %= 10;
  }

  while (d > 0) {
    a[i++] = d % 10;
    d /= 10;
    a[0] = i - 1;
  }
}

string bigfactorial(int n) {
  int a[100000];
  a[0] = a[1] = 1;

  for (int i = 2; i <= n; i++)
    prenext(a, i);

  string s;
  for (int i = a[0]; i > 0; i--)
    s += a[i] + '0';

  return s;
}
