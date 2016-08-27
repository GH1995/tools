/*
给定a和n，计算a+aa+aaa+a...a(n个a)的和。
输入：
测试数据有多组，输入a，n（1<=a<=9,1<=n<=100）。
输出：
对于每组输入,请输出结果。
样例输入：
1 10
样例输出：
1234567900
来源：
*/
#include <iostream>
#include <string.h>
using namespace std;

void bigadd(char sa[], char sb[])	// sa+sb=>sb
{
	int ia[200] = { 0 };
	int ib[200] = { 0 };

	int len_a = strlen(sa);
	int i = len_a - 1;

	int k = 0;
	while (i >= 0)
	{
		ia[k] = sa[i] - '0';
		i--;
		k++;
	}
	// k会多出来一位

	int len_b = strlen(sb);
	i = len_b - 1;

	k = 0;
	while (i >= 0)
	{
		ib[k] = sb[i] - '0';
		i--;
		k++;
	}

	int d = 0;
	k = len_a > len_b ? len_a : len_b;

	i = 0;
	while (i <= k - 1)
	{
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
		sb[k - i] = ib[i] + '0';
	sb[k + 1] = '\0';
}

int main()
{
	int a, n;
	while (cin >> a >> n)
	{
		char x[1000];
		for (int i = 0; i < 1000; i++)
		{
			x[i] = '\0';
		}
		char sum[1000] = { '0' };
		for (int i = 0; i < n; i++)
		{
			x[i] = a + '0';
			bigadd(x, sum);
		}
		if (sum[1] == '0')
		{
			// 注意结果如果为0时的情况，例输入 0 2 输出应为0 而不应是00
			cout << 0 << endl;
			continue;
		}
		cout << sum << endl;
	}

	return 0;
}