/*
题目描述：
输入：
两个字符串，其长度n均小于等于26。
第一行为前序遍历，第二行为中序遍历。
二叉树中的结点名称以大写字母表示：A，B，C....最多26个结点。
输出：
输入样例可能有多组，对于每组测试样例，
输出一行，为后序遍历的字符串。
样例输入：
ABC
BAC
FDXEAG
XDEFAG
样例输出：
BCA
XEDGAF
来源：
2006年清华大学计算机研究生机试真题
*/\r/\r/g
#include <iostream>
#include <cstring>
using namespace std;

char str1[200];
char str2[200];

typedef struct BiTNode
{
	char data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

void PostOrder(BiTree &b)
{
	if (b != NULL)
	{
		PostOrder(b->lchild);
		PostOrder(b->rchild);
		cout << b->data;
	}
}

void rebuild(BiTree &b, int start_1, int end_1, int start_2, int end_2)
{
	b = new BiTNode;
	b->data = str1[start_1];
	b->lchild = b->rchild = NULL;

	int root = 0;
	for (int i = start_2; i <= end_2; i++)
		if (str2[i] == str1[start_1])
		{
			root = i;
			break;
		}

	if (root != start_2)
		rebuild(b->lchild, start_1 + 1, start_1 + root - start_2, start_2, root - 1);
	if (root != end_2)
		rebuild(b->rchild, start_1 + root - start_2 + 1, end_1, root + 1, end_2);
}

int main()
{
	while (cin >> str1 >> str2)
	{
		BiTree b;
		rebuild(b, 0, strlen(str1) - 1, 0, strlen(str2) - 1);
		PostOrder(b);
		cout << endl;
	}

	return 0;
}
