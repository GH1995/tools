/*
题目描述：
第一行输入一个数，为n，第二行输入n个数，这n个数中，如果偶数比奇数多，输出NO，否则输出YES。
输入：
输入有多组数据。
每组输入n，然后输入n个整数（1<=n<=1000）。
输出：
如果偶数比奇数多，输出NO，否则输出YES。
样例输入：
5
1 5 2 4 3
样例输出：
YES
来源：
2010年北京邮电大学计算机研究生机试真题
*/
#include <iostream>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		int p = 0;
		int q = 0;
		int a[1000];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];

			if (a[i] % 2 == 0)
				p++;
			else
				q++;
		}

		if (p > q)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	}

	return 0;
}