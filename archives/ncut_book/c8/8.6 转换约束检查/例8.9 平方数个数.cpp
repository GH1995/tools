#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int t;
	cin >> t;

	int x, y;
	int temp1 = 10000;
	int temp2 = (int)(sqrt(987654321) + 1);

	int k;				// 位置计数器
	int s[10];
	while (t--)
	{
		cin >> x;
		x = x > temp2 ? temp2 : x;

		int n = 0;		// 方案数
		for (int i = temp1; i <= x; i++)
		{
			for (int j = 0; j <= 9; j++)		// 一定要有
				s[j] = 0;

			y = i*i;	// 计算平方数
			k = 0;		// 位置计数器置0

			while (y != 0)
			{
				if (s[y % 10] == 1)
					break;
				s[y % 10] = 1;
				k++;
				y /= 10;
			}
			if (k == 9)		// 满足条件
				n++;
		}
		cout << n << endl;
	}

	return 0;
}