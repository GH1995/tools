/*
题目描述：
一个N*M的矩阵，找出这个矩阵中所有元素的和不小于K的面积最小的子矩阵（矩阵中元素个数为矩阵面积）
输入：
每个案例第一行三个正整数N,M<=100，表示矩阵大小，和一个整数K
接下来N行，每行M个数，表示矩阵每个元素的值
输出：
输出最小面积的值。如果出现任意矩阵的和都小于K，直接输出-1。
样例输入：
4 4 10
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
样例输出：
1
来源：
2010年上海交通大学计算机研究生机试真题
*/\r/\r/g

#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int n, m, k;
	while (cin >> n >> m >> k)
	{
		int a[101][101] = { 0 };
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				scanf("%d", &a[i][j]);

		int flag = 1;		// 假设每个都大于1，所以无解
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (a[i][j] <= k)
				{
					flag = 0;
					break;
				}
		if (flag == 1)
		{
			printf("-1\n");
			return 0;
		}
		
		int sum = 0;
		flag = 1;
		int rs = 999999;
		for (int i = 0; i < n; i++)
			for (int j = i; j < n; j++)
				for (int p = 0; p < m; p++)
					for (int q = p; q < m; q++)
					{
						sum = 0;
						for (int v = i; v <= j; v++)
							for (int b = p; b <= q; b++)
								sum += a[v][b];

						if (sum >= k)
						{
							int sq = (j - i + 1)*(q - p + 1);
							if (sq < rs)
								rs = sq;
						}
					}
		if (rs != 999999)
			cout << rs << endl;
		else
			cout << -1 << endl;
	}

	return 0;
}
