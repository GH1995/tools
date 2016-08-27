#include<stdio.h>
#include<string.h>
#include<ctype.h>

char word[8]={'+','-','*','/','(',')','i','#'};
char *xingshi[6]={"N+N","N-N","N*N","N/N",")N(","i"};

char M[8][8] = {
	{'>','>','<','<','<','>','<','>'},
	{'>','>','<','<','<','>','<','>'},
	{'>','>','>','>','<','>','<','>'},
	{'>','>','>','>','<','>','<','>'},
	{'<','<','<','<','<','=','<','1'},
	{'>','>','>','>','2','>','2','>'},
	{'>','>','>','>','2','>','2','>'},
	{'<','<','<','<','<','3','<','='}
};

char stack[10];
int step, k, j;
char dangqianfuhao;					// 当前字符
char shengyushuruchuan[20];			// 剩余输入字符串
FILE *fp;
char temp[100];						// 要处理的表达式
char aftertemp[100];				// 处理之后的表达式

void panduanshengyuzifuchuan(int a);
void process(char *temp);
void shuchu(int t, int m);


int main()
{
	char ch, str;
	aftertemp[0] = '\0';

	if ((fp = fopen("预处理.txt", "r")) == NULL)
		printf("源文件无法打开！");
	else
	{
		ch = fgetc(fp);
		while (ch != '#')
		{
			while (ch != '='&&ch != '#')
			{
				str = ch;
				ch = fgetc(fp);
				if ((str == '>' || str == '<' || str == '!' || str == '=') && ch == '=')
					ch = fgetc(fp);
			}

			int k = 0;

			if (ch == '#')
			{
				printf("语法分析结束！\n");
				fclose(fp);

				return 0;
			}

			ch = fgetc(fp);
			while (ch != ' ' && ch != '#')
			{
				temp[k++] = ch;
				ch = fgetc(fp);
			}

			temp[k] = '\0';
			printf("要处理的表达式为%s\n", temp);

			int t = 0;
			int y = 0;

			while (temp[t] != '\0')		// 现在开始处理该串，直至生命结束
			{
				int flag = 0;			// 做出善意推断，非终结符

				while (isdigit(temp[t]) != 0)
				{
					t++;
					flag = 1;			// 数字是终结符
				}

				if (flag == 1)
				{
					aftertemp[y] = 'i';		// tempa为终结符料理后事，既提取类型
					y++;
				}

				if (flag == 0)
				{
					aftertemp[y] = temp[t];	// 提取类型
					y++;
					t++;
				}
			}

			aftertemp[y] = '#';				// 收官
			aftertemp[y + 1] = '\0';		// 结束本串

			printf("表达式转化为输入串为%s\n", aftertemp);
			printf(" 步骤号 符号栈 优先关系 当前分析符 剩余输入串 动作\n");

			for (int w = 1; w < 10; w++)	// 初始化栈
				stack[w] = '\0';

			process(aftertemp);
		}
	}

	fclose(fp);
	printf("END！\n");

	getchar();
	return 0;
}

void shuchu(int t, int m)			// t代表移近或者规约, m代表输出的符号><=
{
	printf("%-10d", step);
	printf("%-10s", stack);

	if (m == -1)
		printf("<");
	if (m == 0)
		printf("=");
	if (m == 1)
		printf(">");

	printf("%10c", dangqianfuhao);
	printf("%10s", shengyushuruchuan);

	if (t == 0)
		printf("          移进\n");
	if (t == 1)
		printf("          规约\n");

	step++;
}

void panduanshengyuzifuchuan(int a)		// 判断剩下的字符串
{
	int t,v;

	for (t = 0; t < strlen(aftertemp); t++)
		shengyushuruchuan[t] = '\0';

	for (t = 0, v = a; v < strlen(aftertemp); t++, v++)
		shengyushuruchuan[t] = aftertemp[v];
}

void process(char *temp)
{
	int  k = 1, j, w, l, m, t = 0, p, q, v, yu = 0;

	stack[0] = ' ';
	stack[k] = '#';
	dangqianfuhao = ' ';
	panduanshengyuzifuchuan(yu);
	step = 0;

	shuchu(0, -1);		
	// 这是对#号的处理
	//-1代表<   0代表=   1代表>

	char Q;
	int i = 0;

	do
	{
		dangqianfuhao = temp[i];	// 取符号
		int flag = 0;				// 对终结符号的善意假设

		for (w = 0; w < 8; w++)		// 查找运算符表，谁与stack[k]匹配
		{
			if (stack[k] == word[w])
				flag = 1;
		}

		if (flag == 1)
			j = k;					// j指向终极符了
		else
			j = k - 1;				// j指向stack中最后一个非终结符
	
		for (w = 0; w < 8; w++)		// 找出s[j]和当前字符在优先表里的位置
		{
			if (stack[j] == word[w])
				l = w;				// l记录了当前字符的终结符类型

			if (dangqianfuhao == word[w])
				m = w;				// 终结符的处理
		}

		while (M[l][m] == '>')
		{
			do
			{
				Q = stack[j];

				int flag = 0;		// 再次做出善意假设终结符

				for (w = 0; w < 8; w++)
				{
					if (stack[j - 1] == word[w])
						flag = 1;
				}

				if (flag == 1)
					j = j - 1;
				else
					j = j - 2;

				for (w = 0; w < 8; w++)		// 找出s[j]和Q对应优先表里的位置，对决
				{
					if (stack[j] == word[w])
						p = w;				// p记录员，代理人
					if (Q == word[w])
						q = w;				// q记录员，代理人
				}

			} while (M[p][q] != '<');		// 当然所有前提是，可行的情况下，但是为了做出最初的判断，使用了do-while

			stack[j + 1] = 'N';				// N的诞生，非终结符代替

			for (w = j + 2; w <= k; w++)	// 符号栈出栈，向前走一步，找到另一个非终结符
				stack[w] = '\0';			// 以绝后患，置'\0'

			k = j + 1;

			shuchu(1,1);					// 规约之
	
			break;
		}

		if(M[l][m]=='<')					// 剩下的事情就是根据M判断，规约之
		{
			k = k + 1;
			stack[k] = dangqianfuhao;

			yu++;

			panduanshengyuzifuchuan(yu);
			shuchu(0, -1);

			i++;
		}
		else if(M[l][m]=='=')
		{
			k=k+1;
			stack[k]=dangqianfuhao;
			yu++;

			panduanshengyuzifuchuan(yu);
			shuchu(0, 0);
			i++;
		}
		else
		{
			if(M[l][m]=='1')
			{
				printf("非法左括号!\n");
				i++;
			
			}
			else if(M[l][m]=='2')
			{
				printf("缺少运算符!\n");
				i++;
			}
			else if(M[l][m]=='3')
			{
				printf("非法右括号!\n");
				i++;
			}
		}

	}while(temp[i]!='\0');
}