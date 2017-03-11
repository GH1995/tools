/*
题目描述：
求正整数N(N>1)的质因数的个数。
相同的质因数需要重复计算。如120=2*2*2*3*5，共有5个质因数。
输入：
可能有多组测试数据，每组测试数据的输入是一个正整数N，(1<N<10^9)。
输出：
对于每组数据，输出N的质因数的个数。
样例输入：
120
样例输出：
5
提示：
注意：1不是N的质因数；若N为质数，N是N的质因数。
*/\r/\r/g

#include <iostream>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		int count = 0;
		for (int i = 2; i*i <= n; i++)
			while (n%i == 0)
			{
				count++;
				n /= i;
			}

		if (n > 1)
			count++;
		cout << count << endl;
	}

	return 0;
}
