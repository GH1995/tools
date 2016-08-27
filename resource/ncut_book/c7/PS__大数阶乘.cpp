#include <iostream>
#include <cstring>
using namespace std;

int b[10000];

void prenext(int a[], int k)
{
	int m = a[0];
	for (int i = 1; i <= m; i++)
		b[i] = a[i];
	for (int j = 1; j < k; j++)
	{
		int carry = 0;
		for (int i = 1; i <= m; i++)
		{
			int r = (i <= a[0] ? a[i] + b[i] : a[i]) + carry;
			a[i] = r % 10;
			carry = r / 10;
		}
		if (carry)
			a[++m] = carry;
	}
	a[0] = m;
}

int main()
{
	int a[10000];
	int n;
	while (cin >> n)
	{
		a[0] = 1[a] = 1;
		for (int k = 2; k <= n; k++)
			prenext(a, k);

		for (int i = a[0]; i > 0; i--)
			cout << a[i];
		cout << endl;
	}
	return 0;
}