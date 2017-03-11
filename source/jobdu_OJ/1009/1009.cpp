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
*/\r/\r/g
#include <iostream>
#include <cstring>
using namespace std;

char pre_s[111], in_s[111];
char pre_t[111], in_t[111];
static int m = 0;
static int l = 0;

typedef struct BiTNode
{
	int data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

void InsertBST(BiTree &b, int key)
{
	if (b == NULL)
	{
		BiTree s = new BiTNode;
		s->data = key;
		s->lchild = s->rchild = NULL;
		b = s;
	}
	else if (key < b->data)
		InsertBST(b->lchild, key);
	else if (key > b->data)
		InsertBST(b->rchild, key);
}

/*
	not using
*/
BiTree SearchBST(BiTree b, int key)
{
	if (!b)
		return NULL;
	else if (key == b->data)
		return b;
	else if (key < b->data)
		SearchBST(b->lchild, key);
	else if (key > b->data)
		SearchBST(b->rchild, key);
}

void PreOrder(BiTree b)
{
	if (b)
	{
		pre_s[m++] = b->data + '0';
		PreOrder(b->lchild);
		PreOrder(b->rchild);
	}
}

void InOrder(BiTree b)
{
	if (b)
	{
		InOrder(b->lchild);
		in_s[l++] = b->data + '0';
		InOrder(b->rchild);
	}
}

void PostOrder(BiTree b)
{
	if (b)
	{
		PostOrder(b->lchild);
		PostOrder(b->rchild);
		cout << b->data << ' ';
	}
}


BiTree convert(char as[], int n)
{
	int ns[11];
	for (int i = 0; i < n; i++)
		ns[i] = as[i] - '0';

	BiTree b = NULL;
	for (int i = 0; i < n; i++)
		InsertBST(b, ns[i]);

	return b;
}

int main()
{
	int n;
	while (cin >> n && n != 0)
	{
		char as[111];
		cin >> as;
		BiTree a = convert(as, strlen(as));
		PreOrder(a);
		InOrder(a);
		pre_s[m] = in_s[l] = '\0';
		strcpy(pre_t, pre_s);
		strcpy(in_t, in_s);

		for (int i = 0; i < n; i++)
		{
			char bs[111];
			cin >> bs;
			BiTree b = convert(bs, strlen(bs));
			m = 0;
			l = 0;
			PreOrder(b);
			InOrder(b);
			pre_s[m] = in_s[l] = '\0';

			if (strcmp(pre_s, pre_t) == 0 && strcmp(in_s, in_t) == 0)
				cout << "YSE" << endl;
			else
				cout << "NO" << endl;
		}
	}

	return 0;
}
