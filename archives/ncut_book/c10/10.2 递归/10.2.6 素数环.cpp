#include <iostream>
#include <cmath>
using namespace std;

int tryput(int);
int isprime(int);
int sumisprime(int, int);
int a[20 + 1], used[20 + 1];


int main()
{
	int k, m;

	while (1)
	{
		for (int k = 1; k <= 20; k++)
		{
			a[k] = 0;
			used[k] = 0;
		}

		cin >> m;
		if (m == 0)
			break;

		a[1] = m;
		used[m] = 1;

		tryput(2);

		for (int k = 1; k <= 20; k++)
			cout << a[k];
	}

	return 0;
}

int isprime(int x)
{
	int m = (int)(sqrt(x));

	for (int k = 2; k <= m; k++)
		if (x % k == 0)
			break;

	if (k > m)
		return 1;
	else
		return 0;
}

int sumisprime(int n, int i)
{
	if (i == 1)
		return 1;

	int rtn = isprime(n + a[i - 1]);

	if (rtn == 0)
		return 0;

	if (i < 20)
		return 1;
	
	rtn = isprime(n + a[1]);

	return rtn;
}

int tryput(int i)
{
	for (int j = 1; j <= 20; j++)
	{
		if (used[j])
			continue;

		if (sumisprime(j, i))
		{
			a[i] = j;
			used[j] = 1;

			if (i == 20)
				return 1;

			if (tryput(i + 1) != 1)
			{
				a[i] = 0;
				used[j] = 0;
			}
			else
				return 1;
		}
	}

	return 0;
}