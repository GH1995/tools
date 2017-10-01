/*
*	n只猴子，编号1~n，从1号开始报数，一直报到m的猴子退出圈外，接下来的猴子再从1开始报数
*/\r/\r/g

#include <iostream>
using namespace std;

//i用来找到下一只猴子

int main()
{
	int m;
	int n;
	cin >> n >> m;		// n 只猴子，报数等于m 





	/*
	*	猴子编号存入数组，w[0]存1，为什么呢？
	*/
	int w[100] = { 0 };
	for (int i = 0; i < n; i++)
		w[i] = i + 1;




	
	int i = 0;
	/*
	*	重要：
	*		i用来找到下一只猴子！！！
	*/


	int k = 1;			// 报数的数，从1开始报数





	int p = 0;			// 出圈个数
	while (!(p == n - 1))// 一共要出圈n-1个
	{


		/*
		*	该猴子已经退出
		*	不管它了，用i找到下一只猴子
		*/
		if (w[i] == -1)	// 已退出，报下一个
		{
			i = (i + 1) % n;
			continue;
		}





		/*
		*	遇到一只不幸的猴子
		*
		*/
		if (k == m)		// 报到 m
		{
			w[i] = -1;	// 标记出圈
			p++;		// 出圈个数加1
			k = 0;		// 置0，使k从下一个元素开始报1
		}

		k++;			// 猴子报数的数加1








		/*
		*	理解这里很重要
		*	下一只猴子就在旁边，i并没有什么作用
		*	
		*	ADD:
		*	最后一种情况：该猴子在圈中且没有报到数
		*/
		i = (i + 1) % n;// 下一个猴子
	}
	

	for (int i = 0; i < n; i++)
		if (w[i] != -1)
		{
			cout << w[i] << endl;
			break;
		}

	return 0;
}
