/*
*	a / p = b ・・・ c
*
*	原始数据：个位数不是5的奇数p
*	初始量：c = 0, n = 0
*	循环条件： c != 0
*	构造量：m = 1
*
*/\r/\r/g

#include <iostream>
using namespace std;

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int p;
		cin >> p;

		int c = 0;				// 初始量赋值，有意味的赋值
		int n = 0;

		int a, b;
		int flag = 1;			// 标志量，标志第一次进入
		while (c != 0 || flag != 0)
		{
			a = c * 10 + 1;		// 构造量为1，构造被除数
			b = a / p;
			c = a%p;
			n++;

			if (flag == 1 && b == 0)	// 若最高位为0，则不输出
				continue;

			cout << b;
			flag = 0;
		}

		cout << ' ' << n << endl;
	}

	return 0;
}
