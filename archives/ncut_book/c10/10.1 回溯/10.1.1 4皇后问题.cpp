#define N 4
#include <iostream>
#include <cmath>
using namespace std;


int main()
{
	int n = N;			// n皇后
	int i = 1;			// 遍历值
	int x[N + 1];
	x[i] = 1;			// 初始化，取第一个可能的值<1>






	int s = 0;			// 统计解的个数
	while (1)
	{
		int fg = 1;		// 开始时，满足约束条件



		/*
		*	【检测约束】
		*
		*	约束条件为x[i] != x[k] && abs(x[i] - x[k]) != i - k
		*/
		for (int k = i - 1; k >= 1; k--)			// i=1时没有用到
			if (x[i] == x[k] || abs(x[i] - x[k]) == i - k)
				fg = 0;

		/*
		*	【输出一个解】
		*/
		if (fg == 1 && i == n)
		{
			s++;

			for (int j = 1; j <= n; j++)
				cout << x[j];

			cout << endl;
		}


		/*
		*	【扩充元素】
		*/
		if (fg == 1 && i < n)
		{
			i++;
			x[i] = 1;
			continue;
		}


		/*
		*	【回溯】
		*/
		while (i > 1 && x[i] == n)
			i--;


		/*
		*	【试探结束】
		*/
		if (i == 1 && x[i] == n)
			break;			
		else
			x[i]++;
	}

	cout << s << endl;

	return 0;
}


/*
*	检测约束->输出一个解->扩充元素->回溯->试探结束
*	i, j不可随意替换
*/