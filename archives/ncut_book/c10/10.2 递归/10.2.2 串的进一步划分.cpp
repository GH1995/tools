#define N 7
#include <iostream>
#include <string>
using namespace std;


/*
*	与前面定义相同
*/
void inittb1();
void chkstr(char *str, int *w);




struct {
	char str[100];
	int wt;
}tb[100];






int lev;					// 已得到的子串的个数
char rsltstr[100][100];		// 保存中间结果的空间





/*
*	设计字符串的拆分函数
*/
void split(char *str, int sum)
{
	int i, weight;
	char substr[100];		// 存储子串



	/*
	*	输出一组解
	*/
	int len = strlen(str);
	if (len == 0)			
	{
		for (int i = 0; i < lev; i++)
			cout << rsltstr[i] << ' ';
		cout << sum << endl;
		return;
	}


	/*
	*	对长度为1~len的子串进行逐个试探
	*/
	for (int i = 1; i <= len; i++)
	{
		strncpy(substr, str, i);
		substr[i] = '\0';
		if (chkstr(substr, &weight) == 1)
		{
			strcpy(rsltstr[lev++], substr);
			sum += weight;
			split(&str[i], sum);
			lev--;
			sum = sum - weight;
		}
	}
}





int main()
{
	int s = 0;
	char str[] = { "aaabc" };
	inittb1();
	lev = 0;
	split(str, s);

	return 0;
}