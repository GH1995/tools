/*
题目描述：
求任意两个不同进制非负整数的转换（2进制～16进制），所给整数在long所能表达的范围之内。
不同进制的表示符号为（0，1，...，9，a，b，...，f）或者（0，1，...，9，A，B，...，F）。
输入：
输入只有一行，包含三个整数a，n，b。a表示其后的n 是a进制整数，b表示欲将a进制整数n转换成b进制整数。a，b是十进制整数，2 =< a，b <= 16。
数据可能存在包含前导零的情况。
输出：
可能有多组测试数据，对于每组数据，输出包含一行，该行有一个整数为转换后的b进制数。输出时字母符号全部用大写表示，即（0，1，...，9，A，B，...，F）。
样例输入：
15 Aab3 7
样例输出：
210306
提示：
可以用字符串表示不同进制的整数。
来源：
2008年北京大学图形实验室计算机研究生机试真题
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

int main()
{
	int a, b;
	string s;
	while (cin >> a >> s >> b)
	{
		transform(s.begin(), s.end(), s.begin(), ::tolower);
		reverse(s.begin(), s.end());

		long long sum = 0;
		int k = 1;
		string::iterator i = s.begin();
		for (; i != s.end(); i++)
		{
			int x;
			if (*i >= '0' && *i <= '9')
				x = *i - '0';
			else
				x = *i - 'a' + 10;
			sum += x*k;
			k *= a;
		}

		k = 0;
		char d[100] = { '\0' };
		do
		{
			int x = sum%b;
			if (x >= 0 && x <= 9)
				d[k++] = x + '0';
			else
				d[k++] = x - 10 + 'A';
			sum /= b;
		} while (sum != 0);
		reverse(d, d + k);
		cout << d << endl;
	}

	return 0;
}