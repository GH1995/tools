#include <iostream>
using namespace std;

int main()
{
	char ch;
	int k1;
	int k2;
	cin >> ch >> k1 >> k2;		// 输入字符和范围


	int p = ch - 'A' + 1;		// 读入字母转换成数字下标

	int a[10];
	int i = 1;
	a[i] = 1;

	int s = 0;		// 统计
	while (1)
	{
		/*
		*	检测约束条件
		*/
		int fg = 1;
		for (int k = i - 1; k >= 1; k--)
			if (!(a[i] != a[k]))
				fg = 0;

		if ((i == p) && (a[p] < k1 || a[p] > k2))
			fg = 0;





		/*
		*	输出一个解
		*/
		if (i == 9 && fg == 1)
		{
			long x = a[2] * 10 + a[3];
			long y = a[5] * 10 + a[6];
			long z = a[8] * 10 + a[9];

			if (a[4] * a[7] * x + a[1] * a[7] * y == a[1] * a[4] * z)
			{
				s++;
				cout << '(' << s << ')' << x << '/' << a[1] << '+' << y << '/' << a[4] << '=' << z << '/' << a[7] << endl;
			}
		}




		/*
		*	扩充元素
		*/
		if (i < 9 && fg == 1)
		{
			i++;
			a[i] = 1;
			continue;
		}





		/*
		*	回溯
		*/
		while (a[i] == 9 && i > 1)
			i--;




		/*
		*	试探结束
		*/
		if (i == 1 && a[i] == 9)
			break;
		else
			a[i]++;
	}
	cout << s << endl;

	return 0;
}



/*
*		若等号左边两个分数交换位置，则只算一种方案对于满足条件的等式中，
*	我们可以事先约定前面分数的分母小于后面分数的分母，这样就可以过滤掉两
*	分数交换的情况。
*/