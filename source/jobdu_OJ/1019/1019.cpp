/*
题目描述：
读入一个只包含 +, -, *, / 的非负整数计算表达式，计算该表达式的值。
输入：
测试输入包含若干测试用例，每个测试用例占一行，每行不超过200个字符，整数和运算符之间用一个空格分隔。没有非法表达式。当一行中只有0时输入结束，相应的结果不要输出。
输出：
对每个测试用例输出1行，即该表达式的值，精确到小数点后2位。
样例输入：
1 + 2
4 + 2 * 5 - 7 / 11
0
样例输出：
3.00
13.36
来源：
2006年浙江大学计算机及软件工程研究生机试真题
*/\r/\r/g
#include <iostream>
#include <string>
#include <stack>
#include <iomanip>
using namespace std;


int mat[5][5] = {
	//			   [1] +	[2] -	[3] *	[4] /	[5] #
	/* [1] + */		1,		0,		0,		0,		0,
	/* [2] - */		1,		0,		0,		0,		0,
	/* [3] * */		1,		0,		0,		0,		0,
	/* [4] / */		1,		1,		1,		0,		0,
	/* [5] # */		1,		1,		1,		0,		0
};

stack <int> op;		// 运算符栈
stack <double> in;	//数字栈

char str[220];

/*
	reto = false;	number	-> retn
	reto = true;	op		-> retn
*/
void getop(bool& reto, int& retn, int &i);

int main()
{
	while (cin.getline(str, 220))
	{
		while (!op.empty())
			op.pop();
		while (!in.empty())
			in.pop();

		bool retop;
		int retnum;
		int idx = 0;	// 下标

		while (true)
		{
			getop(retop, retnum, idx);
			if (!retop)		// 数字栈
				in.push((double)retnum);
			else			// 符号栈
			{
				double tmp;
				if (op.empty() || mat[retnum][op.top()] == 1)	// 符号栈为空或当前运算符有限级大于栈顶运算符压栈
					op.push(retnum);
				else
				{
					while (mat[retnum][op.top()] == 0)
					{
						int ret = op.top();
						op.pop();

						double b = in.top();
						in.pop();
						double a = in.top();
						in.pop();

						switch (ret)
						{
						case 1:
							tmp = a + b;
							break;

						case 2:
							tmp = a - b;
							break;

						case 3:
							tmp = a*b;
							break;

						case 4:
							tmp = a / b;
							break;
						default:
							break;
						}

						in.push(tmp);
					}

					op.push(retnum);		// 当前运算符压栈
				}
			}

			if (op.size() == 2 && op.top() == '#')
				break;
		}
		cout << setiosflags(ios::fixed) << setprecision(2) << in.top() << endl;
	}

	return 0;
}


void getop(bool& reto, int& retn, int &i)
{
	if (i == 0 && op.empty())
	{
		reto = true;
		retn = '#';
		return;
	}

	if (str[i] == '\0')
	{
		reto = true;
		retn = '#';
		return;
	}

	if (str[i] >= '0' && str[i] <= '9')
		reto = false;
	else
	{
		reto = true;
		switch (str[i])
		{
		case '+':
			retn = 1;
			break;
		case '-':
			retn = 2;
			break;
		case '*':
			retn = 3;
			break;
		case '/':
			retn = 4;
			break;
		default:
			break;
		}

		i += 2;
		return;
	}

	retn = 0;
	for (; str[i] != ' ' &&; i++)
	{
		retn *= 10;
		retn += str[i] - '0';
	}

	if (str[i] == ' ')
		i++;

	return;
}
