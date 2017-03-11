/*
*   将P（P>=2）进制数转换成R(R<=16)进制数
*/\r/\r/g

#include <iostream>
#include <string>
using namespace std;

int main()
{
	while (true)
	{
		int p;				// p进制数
		int r;				// r进制数
		char d[31];			// 输入的p进制数字，存在d[31]
		cin >> p >> r >> d;

		if (p == 0)
			return 0;

		/*
		*	第一步：将p进制数转换为10进制数
		*/
		long m = 0;            	// 保存10进制数
		int k = 1;              // 记录p的次方
		for (int i = strlen(d) - 1; i >= 0; i--)   		// 由后到前！
		{
			if (d[i] <= '9')
				m += (d[i] - '0')*k;
			else
				m += (d[i] - 'A' + 10)*k;

			k = k*p;            // 记录p的i次方
		}

		for (int i = 0; i < 30; i++)         			// 保存转换结果，再次利用d[]
			d[i] = '\0';

		/*
		*	第二步：将10进制数转换为r进制数
		*/
		k = 0;
		while (m != 0L)    			// 将m中的10进制数转换成R进制存放在d[]中
		{
			int n;					// 存储余数，每次产生一位
			n = m%r;            	// 取低位

			if (n >= 10)
				d[k++] = n - 10 + 'A';
			else
				d[k++] = n + '0';

			m = m / r;
		}

		strrev(d);
		cout << d << endl;
	}

	return 0;
}
