/*
题目描述：
给定n，a求最大的k，使n！可以被a^k整除但不能被a^(k+1)整除。
输入：
两个整数n(2<=n<=1000)，a(2<=a<=1000)
输出：
一个整数.
样例输入：
6 10
样例输出：
1
来源：
2011年上海交通大学计算机研究生机试真题
*/

#include <iostream>
#include <cstring>
using namespace std;

int prime_make(int prime[], int n)
{
	bool mark[10000];
	memset(prime, true, sizeof(mark));

	int count = 0;
	for (int i = 2; i < n; i++)
	{
		if (mark[i] == false)
			continue;

		prime[count++] = i;
		for (int j = i*i; j < n; j += i)
			mark[j] = false;
	}

	return count;
}

int main()
{
	int prime[10001];
	int size = prime_make(prime, 10000);	// 求10000之内的质数

	int n, a;
	while (cin >> n >> a)
	{
		int cnt_1[10001] = { 0 };
		int cnt_2[10001] = { 0 };

		for (int i = 2; i <= n; i++)
		{
			int t = i;
			for (int j = 0; j < size && prime[j] <= t; j++)
				while (t%prime[j] == 0)
				{
					cnt_1[j]++;
					t /= prime[j];
				}
		}

		for (int i = 0; i < size && prime[i] <= a; i++)
			while (a%prime[i] == 0)
			{
				cnt_2[i]++;
				a /= prime[i];
			}

		double k = 999999999;
		for (int i = 0; i < 10001; i++)
		{
			if (cnt_1[i] == 0 && cnt_2[i] != 0)
			{
				k = 0;
				break;
			}

			if (cnt_1[i] != 0 && cnt_2[i] != 0 && k > 1.0*cnt_1[i] / cnt_2[i])
				k = 1.0*cnt_1[i] / cnt_2[i];
		}
		cout << (int)k << endl;
	}

	return 0;
}