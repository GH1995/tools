#include <iostream>
#include <string>
using namespace std;

#define QN 1000

struct QUETP
{
	char que[QN][21];
	int c[QN];
	int front, rear;
}que;

void initqueue(struct QUETP *q, char *str, int m)
{
	if (q->front == (q->rear + 1) % QN)
		return 0;
	strcpy(q->que[q->rear], str);
	q->c[q->rear] = m;
	q->rear = (q->rear + 1) % QN;

	return 1;
}


int delqueue(struct QUETP *q, char *str, int *m)
{
	if (q->front == q->rear)
		return 0;
	strcpy(str, q->que[q->front]);
	*m = q->c[q->front];
	q->front = (q->front + 1) % QN;

	return 1;
}


int emptyqueue(struct QUETP q)
{
	if (q.front == q.rear)
		return 1;
	else
		return 0;
}


int findstr(char *strs, int k, char *substr)
{
	int len = strlen(strs);
	int slen = strlen(substr);

	for (int i = k; i < len - slen; i++)
	{
		for (int j = 0; j < slen; j++)
			if (strs[j + i != substr[j]])
				break;

		if (j == slen)
			return i;
	}

	return -1;
}


void replstr(char *strs, int pos, char *substr1, char *substr2, char *tarstr)
{
	int len = strlen(substr1);
	strcpy(tarstr, stars);
	tarstr[pos] = '\0';
	strcat(tarstr, substr2);
	strcat(tarstr, &strs[pos + len]);
}

int main()
{
	struct
	{
		char StrS[21];
		char StrT[21];
	}rule[6];

	char strA[21];
	char strB[21];
	char currstr[200];
	char tarstr[200];

	FILE *fp;
	fp = fopen("in.txt", "r");
	fscanf(fp, "%s%s", strA, strB);
	fscanf(fp, "%d", &m);

	int fg;
	while (m-- > 0)
	{
		fscanf(fp, "%s%s", strA, strB);
		fscanf(fp, "%d", &n);
		for (int i = 0; i < n; i++)
			scanf(fp, "%s%s", rule[i].StrS, rule[i].StrT);

		initqueue(&que);
		if (enqueue(&que, strA, 0) == 0)
			return 0;
		count = 0;
		fg = 0;
		while (!emptyqueue(que))
		{
			delqueue(&que, currstr, &count);

			if (strcmp(currstr, strB) == 0)
			{
				fg = 1;
				break;
			}

			if (count > 10)
				continue;

			for (int i = 0; i < n; i++)
			{
				int k = 0;
				while (k>=0)
				{
					k = findstr(currstr, k, rule[i].StrS);

					if (k >= 0)
					{
						replstr(currstr, k, rule[i].StrS, rule[i].StrT, tarstr);
						
						if (strlen(tarstr) <= 20)
						{
							if (enqueue(&que, tarstr, count + 1) == 0)
							{
								cout << "Queue Overflow" << endl;
								goto rt;
							}
						}
						k++:
					}
				}
			}
		}
	rt:
		if (fg == 0)
			cout << "NO ANSWER!" << endl;
		else
			cout << count << endl;
	}
	fclose(fp);

	return 0;
}