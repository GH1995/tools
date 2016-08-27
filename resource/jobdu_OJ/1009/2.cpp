/*
题目描述：
判断两序列是否为同一二叉搜索树序列
输入：
开始一个数n，(1<=n<=20) 表示有n个需要判断，n= 0 的时候输入结束。
接下去一行是一个序列，序列长度小于10，包含(0~9)的数字，没有重复数字，根据这个序列可以构造出一颗二叉搜索树。
接下去的n行有n个序列，每个序列格式跟第一个序列一样，请判断这两个序列是否能组成同一颗二叉搜索树。
输出：
如果序列相同则输出YES，否则输出NO
样例输入：
2
567432
543267
576342
0
样例输出：
YES
NO
来源：
2010年浙江大学计算机及软件工程研究生机试真题
*/
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int len_s = 0;

typedef struct BiTNode
{
	int data;         //数据

	struct BiTNode *lchild; // 左孩子指针
	struct BiTNode *rchild; // 右孩子指针

}BiTNode, *BiTree;


BiTree SearchBST(BiTree b, int key)
{
	BiTree q = b;

	while (q)
	{
		if (q->data == key)        // 查找成功
			return q;
		if (key < q->data)
			q = q->lchild;      // 左子树中查找
		else
			q = q->rchild;      // 右子树中查找
	}

	return NULL;                // 查找失败
}

void InsertBST(BiTree &b, int key)
{
	BiTree s;

	if (b == NULL)           // 递归结束条件
	{
		s = (BiTNode *)malloc(sizeof(BiTNode));
		s->data = key;
		s->lchild = NULL;
		s->rchild = NULL;
		b = s;
	}
	else if (key < b->data)
		InsertBST(b->lchild, key);      // 将s插入左子树
	else if (key > b->data)
		InsertBST(b->rchild, key);      // 将s插入右子树
}

bool isequal(BiTree a, BiTree b)
{
	if (a == NULL && b == NULL)
		return true;
	else if (a->data == b->data)
		return isequal(a->lchild, b->lchild) || isequal(a->rchild, b->rchild);
	else
		return false;
}


int main()
{
	int n;
	while (cin >> n)
	{
		if (n == 0)
			break;

		char source[11];
		cin >> source;
		int len_s = strlen(source);

		int s[11];
		for (int i = 0; i < len_s; i++)
			s[i] = source[i] - '0';

		BiTree so = NULL;
		for (int i = 0; i < len_s; i++)
			InsertBST(so, s[i]);

		char str[100][11];
		for (int i = 0; i < n; i++)
		{
			cin >> str[i];
			for (int j = 0; j < len_s; j++)
				s[j] = str[i][j] - '0';

			BiTree t = NULL;
			for (int i = 0; i < len_s; i++)
				InsertBST(t, s[i]);

			if (isequal(so, t))
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
	}

	return 0;
}
