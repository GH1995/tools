#include <iostream>
using namespace std;

int main()
{
	int p, q;		// 尾数q和倍数p
	cin >> q >> p;

	int w[100];
	w[1] = q;

	/*
	*	初始量赋值
	*/
	int m = 0;
	int a = p*q;
	int k = 1;

	while (a != q)
	{
		a = w[k] * p + m;		// 计算乘积
		k++;;					// 位数计数
		w[k] = a % 10;			// 得到乘积个位
		m = a / 10;				// 进位数
	}

	for (int j = k - 1; j >= 1; j--)	// 去掉w[k]中的q
		cout << w[j];
	cout << endl;

	return 0;
}