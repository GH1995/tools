#define N 7
#include <iostream>
#include <string>
using namespace std;

struct {
	char str[100];
	int wt;
}tb[100];

void inittb1()
{
	strcpy(tb[0].str, "a");
	tb[0].wt = 9;
	strcpy(tb[1].str, "aa");
	tb[1].wt = 21;
	strcpy(tb[2].str, "aab");
	tb[2].wt = 33;
	strcpy(tb[3].str, "bc");
	tb[3].wt = 22;
	strcpy(tb[4].str, "bbc");
	tb[4].wt = 30;
	strcpy(tb[5].str, "cd");
	tb[5].wt = 10;
	strcpy(tb[6].str, "acdd");
	tb[6].wt = 25;

}


int chkstr(char *str, int *w)
{
	for (int i = 0; i < N; i++)
	{
		if (strcmp(str, tb[i].str) == 0)
		{
			*w = tb[i].wt;
			return 1;
		}
	}

	return 0;
}


int main()
{
	char str[] = { "aaabc" };
	char substr[100];
	char rsltstr[100][100];
	int rsltwt[100];

	initta1();

	int sum = 0;
	int lev = 0;
	int i = 0;
	int j = 0;
	int weight;

	substr[j++] = str[i];
	substr[j] = '\0';
	int len = strlen(str);

	while (1)
	{
		int fg = 1;
		if (chkstr(substr, &weight) == 0)
			fg = 0;

		if (fg == 1 && chkstr(substr, &weight) == 1)
		{
			rsltwt[lev] = weight;
			strcpy(rsltstr[lev++], substr);
			j = 0;
		}

		if (i == len - 1 && j == 0)
		{
			sum = 0;
			for (int k = 0; k < lev; k++)
			{
				cout << rsltstr[k];
				sum += rsltwt[k];
			}
			cout << sum << endl;
		}

		if (i < len - 1)
		{
			i++;
			substr[j++] = str[i];
			substr[j] = '\0';
			continue;
		}

		int sublen = strlen(substr);
		if (sublen == len)
			break;
		lev--;

		if (i == len - 1 && j == 0)
			lev--;

		i = i - sublen + 1;
		strcpy(substr, rsltstr[lev]);
		j = strlen(sublen);
		substr[j++] = str[i];
		substr[j] = '\0';
	}

	return 0;
}