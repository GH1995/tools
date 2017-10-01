/*
*	判断依据比赛结束的条件是：双方有一方达到11分或21分，且双方分数之差大于1，或者是比赛结束。
*	正在进行比赛的比分需要输出，并且0：0也要输出。
*
*/\r/\r/g
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int rslt[400][2] = { 0 };	// 存放21分制比分,这里书上有错误
	
	/*
	*	11分制比分
	*/
	int a1 = 0;		// 1方
	int a2 = 0;		// 2方


	/*
	*	21分制比分
	*/
	int b1 = 0;		// 1方
	int b2 = 0;		// 2方


	int k = 0;

	while (1)
	{
		char ch;
		ch = getchar();		// 读入一个字符

		if (ch == 'W')
			a1++, b1++;		// 1方比分+1

		if (ch == 'L')		
			a2++, b2++;		// 2方比分+1

		/*
		*	11分制一局结束，<输出>比分
		*/
		if ((a1 >= 11 || a2 >= 11) && (abs(a1 - a2) > 1) || ch == 'E')
		{
			cout << a1 << ':' << a2 << endl;
			a1 = 0;
			a2 = 0;
		}

		/*
		*	21分制一局结束,<保存>比分
		*/
		if ((a1 >= 21 || b2 >= 21) && (abs(b1 - b2) > 1) || ch == 'E')
		{
			rslt[k][0] = b1;
			rslt[k][1] = b2;
			k++;
			b1 = b2 = 0;
		}

		if (ch == 'E')
			break;
	}



	cout << endl;		// 空行

	for (int i = 0; i < k; i++)
		cout << rslt[i][0] << ":" << rslt[i][1] << endl;

	return 0;
}
