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
char dangqianfuhao;					// ��ǰ�ַ�
char shengyushuruchuan[20];			// ʣ�������ַ���
FILE *fp;
char temp[100];						// Ҫ����ı��ʽ
char aftertemp[100];				// ����֮��ı��ʽ

void panduanshengyuzifuchuan(int a);
void process(char *temp);
void shuchu(int t, int m);


int main()
{
	char ch, str;
	aftertemp[0] = '\0';

	if ((fp = fopen("Ԥ����.txt", "r")) == NULL)
		printf("Դ�ļ��޷��򿪣�");
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
				printf("�﷨����������\n");
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
			printf("Ҫ����ı��ʽΪ%s\n", temp);

			int t = 0;
			int y = 0;

			while (temp[t] != '\0')		// ���ڿ�ʼ����ô���ֱ����������
			{
				int flag = 0;			// ���������ƶϣ����ս��

				while (isdigit(temp[t]) != 0)
				{
					t++;
					flag = 1;			// �������ս��
				}

				if (flag == 1)
				{
					aftertemp[y] = 'i';		// tempaΪ�ս��������£�����ȡ����
					y++;
				}

				if (flag == 0)
				{
					aftertemp[y] = temp[t];	// ��ȡ����
					y++;
					t++;
				}
			}

			aftertemp[y] = '#';				// �չ�
			aftertemp[y + 1] = '\0';		// ��������

			printf("���ʽת��Ϊ���봮Ϊ%s\n", aftertemp);
			printf(" ����� ����ջ ���ȹ�ϵ ��ǰ������ ʣ�����봮 ����\n");

			for (int w = 1; w < 10; w++)	// ��ʼ��ջ
				stack[w] = '\0';

			process(aftertemp);
		}
	}

	fclose(fp);
	printf("END��\n");

	getchar();
	return 0;
}

void shuchu(int t, int m)			// t�����ƽ����߹�Լ, m��������ķ���><=
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
		printf("          �ƽ�\n");
	if (t == 1)
		printf("          ��Լ\n");

	step++;
}

void panduanshengyuzifuchuan(int a)		// �ж�ʣ�µ��ַ���
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
	// ���Ƕ�#�ŵĴ���
	//-1����<   0����=   1����>

	char Q;
	int i = 0;

	do
	{
		dangqianfuhao = temp[i];	// ȡ����
		int flag = 0;				// ���ս���ŵ��������

		for (w = 0; w < 8; w++)		// �����������˭��stack[k]ƥ��
		{
			if (stack[k] == word[w])
				flag = 1;
		}

		if (flag == 1)
			j = k;					// jָ���ռ�����
		else
			j = k - 1;				// jָ��stack�����һ�����ս��
	
		for (w = 0; w < 8; w++)		// �ҳ�s[j]�͵�ǰ�ַ������ȱ����λ��
		{
			if (stack[j] == word[w])
				l = w;				// l��¼�˵�ǰ�ַ����ս������

			if (dangqianfuhao == word[w])
				m = w;				// �ս���Ĵ���
		}

		while (M[l][m] == '>')
		{
			do
			{
				Q = stack[j];

				int flag = 0;		// �ٴ�������������ս��

				for (w = 0; w < 8; w++)
				{
					if (stack[j - 1] == word[w])
						flag = 1;
				}

				if (flag == 1)
					j = j - 1;
				else
					j = j - 2;

				for (w = 0; w < 8; w++)		// �ҳ�s[j]��Q��Ӧ���ȱ����λ�ã��Ծ�
				{
					if (stack[j] == word[w])
						p = w;				// p��¼Ա��������
					if (Q == word[w])
						q = w;				// q��¼Ա��������
				}

			} while (M[p][q] != '<');		// ��Ȼ����ǰ���ǣ����е�����£�����Ϊ������������жϣ�ʹ����do-while

			stack[j + 1] = 'N';				// N�ĵ��������ս������

			for (w = j + 2; w <= k; w++)	// ����ջ��ջ����ǰ��һ�����ҵ���һ�����ս��
				stack[w] = '\0';			// �Ծ��󻼣���'\0'

			k = j + 1;

			shuchu(1,1);					// ��Լ֮
	
			break;
		}

		if(M[l][m]=='<')					// ʣ�µ�������Ǹ���M�жϣ���Լ֮
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
				printf("�Ƿ�������!\n");
				i++;
			
			}
			else if(M[l][m]=='2')
			{
				printf("ȱ�������!\n");
				i++;
			}
			else if(M[l][m]=='3')
			{
				printf("�Ƿ�������!\n");
				i++;
			}
		}

	}while(temp[i]!='\0');
}