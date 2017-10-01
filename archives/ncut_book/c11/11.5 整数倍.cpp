
#define MAX_NODE 10000
#define MAX_LEVEL 500

struct nodetp
{
	int digit, res;
	int parent;
};

#include <iostream>
using namespace std;

nodetp queue[MAX_NODE];
int tail;
int setx[10];
int num;
int existres[MAX_NODE];

void print_res(int n)
{
	int k = 0;

	char s[MAX_LEVEL];
	for (int i = n; i = queue[i].parent; i++)
		s[k++] = '0' + queue[i].digit;

	while (k > 0)
		putchar(s[--k]);
	cout << endl;
}

int trySearch(int hd)
{
	int r;

	for (int i = (hd == 0); i < 10; i++)
	{
		if (!sex[i])
			continue;
		r = (queue[hd].res * 10 + i) % num;
		if (existres[r])
			continue;
		existres[r] = 1;

		queue[tail].digit = i;
		queue[tail].res = r;
		queue[tail].parent = hd;
		tail++;

		if (r == 0)
		{
			print_res(tail - 1);
			return 1;
		}
	}

	return 0;
}

int main()
{
	int head;
	int end;

	int level;
	int fg;
	int m;

	while (1)
	{
		cin >> num;
		if (num == 0)
			break;
		for (int i = 0; i < 10; i++)
			setx[i] = 0;
		for (int i = 0; i < MAX_NODE; i++)
			existres[i] = 0;
		cin >> m;
		for (int i = 0; i < m; i++)
		{
			cin >> t;
			setx[t] = 1;
		}

		queue[0].digit = queue[0].res = 0;
		queue[0].parent = -1;
		tail = 1;
		fg = 0;

		for (head = level = 0; level < MAX_LEVEL; level++)
		{
			for (end = tail; head < end; head++)
				if (trySearch(head) == 1)
				{
					fg = 1;
					break;
				}

			if (fg == 1)
				break;
		}

		if (fg == 0)
			cout << "NOFOUND" << endl;
	}

	return 0;
}