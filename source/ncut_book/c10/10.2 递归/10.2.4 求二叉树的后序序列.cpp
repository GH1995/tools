#include <iostream>
#include <string>
using namespace std;

/*
*	s1,先序序列串
*	s2,中序序列串
*	s3,后序序列串
*	len序列长度
*	pos,结果序列当前位置
*
*/

void findpost(char *s1, char *s2, char *s3, int len, int *pos)
{
	int m;

	if (len == 1)				// 只有一个关键字是直接写入到结果序列的当前位置
		s3[(*pos)--] = s1[0];
	else
	{
		s3[(*pos)--] = s1[0];	// 先序序列中的第一个关键字为根
		m = 0;
		while (s2[m] != s1[0])	// 在中序序列中查找根结点关键字的位置
			m++;

		/*
		*	确定右子树的结点数
		*/
		if (len - m - 1 > 0)
			findpost(s1 + m + 1, s2 + m + 1, s3, len - m - 1, pos);

		/*
		*	确定左子树的结点数
		*/
		if (m > 0)
			findpost(s1 + 1, s2, s3, m, pos);
	}
}

int main()
{
	char prestr[20];		// 读先序序列
	char instr[20];			// 读中序序列
	cin >> prestr >> instr;



	int k = strlen(instr);	// 树的结点个数
	poststr[k] = '\0';		// 后序序列的字符串结果置'\0'



	k--;					// 指示结果序列的当前位置
	char poststr[20];
	findpost(prestr, instr, poststr, strlen(instr), &k);




	cout << poststr << endl;

	return 0;
}