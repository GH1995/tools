#include <iostream>
using namespace std;

int main()
{
	int n;
	int p;
	cin >> n >> p;			// n! 中 p 出现几次

	int w[2000] = { 0 };	// w[]保存结果
	w[0] = 1;

	int k = 0;				// k用于记录结果最高位的下标
	int a = 0;

	for (int i = 1; i <= n; i++)	// 进行 n 次乘法运算
	{
		int m = 0;			// 进位赋初值
		for (int j = 0; j <= k; j++)	// 各位乘i
		{
			a = w[j] * i + m;			// 乘积结果
			w[j] = a % 10;				// 取个位
			m = a / 10;					// 进位数
		}

		while (m > 0)
		{
			k++;
			w[k] = m % 10;
			m /= 10;
		}
	}

	int s = 0;
	for (int i = k; i >= 0; i--)	// 输出结果
	{
		cout << w[i];					

		if (w[i] == p)
			s++;
	}
	cout << '\n' << s << endl;

	return 0;
}