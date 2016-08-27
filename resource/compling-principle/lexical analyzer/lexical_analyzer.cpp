/*
pretreatment()		Ԥ������
scanner()			ɨ�躯����ʶ�𵥴�
contact()			ƴ���ַ�
reserve()			������ֱ���
main()				������

main����pretreatment����Ԥ����Ȼ�󲻶ϵ���ɨ�躯��scanner����õ��ʵĶ�Ԫʽ�룬������д�� ��Ԫʽ.txt��ֱ��Դ�������

���ű�		��ʶ���������֣�����������������

	code		val
	i����ʶ����	**
	i			a
	i			b

	IF			A
	THEN		B
	ELSE		C
	GOTO		D

	+			NUL
	-			NUL
	*			NUL
	/			NUL
	=			NUL
	++($)		NUL
	--(@)		NUL
	>			NUL
	>=(%)		NUL
	<			NUL
	<=(^)		NULL

	(			NUL
	)			NUL
	:			NUL

	x			**
	x			2
	x			3
	x			5
	x			10
	x			100
	x			101

*/
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>
using namespace std;

const int WordLen = 20;

struct code_val							// �ڲ���Ķ���
{
	char code;							// �����ֱ�
	char val[WordLen + 1];				// ����ֵ
};

void pretreament(char filename[], char Buf[])	
{

	/*
			����
				1.ɾ��ע��
				2.ɾ�����з������������Ļ��з�
				3.�����з���Tabͳһ�滻Ϊ�ո�
				4.����Ԥ����ĳ������ɨ�軺��������ɨ����ʶ�𵥴�
	*/


	ifstream cinf(filename, ios::in);			// ��������������ifstream
	char c0 = '$', c1;							// c0Ϊǰһ���֣�c1Ϊ��ǰ�ַ�
	bool in_comment = false;					// ״̬��־��false��ʾ��ǰ�ַ�Ϊ����ע����

	cout << "<Դ����>" << endl;

	int i = 0;									// ��Buf[0]

	while (cinf.read(&c1, sizeof(char)))
	{
		cout << c1;

		switch (in_comment)
		{
		case false:								// ��һ�ַ���δ����ע����
			if (c0 == '/' && c1 == '*')			// �������ע�ͣ�ȥ���Ѵ���ɨ�軺�������ַ�'/'
				in_comment = true, i--;
			else
			{
				if (c0 == '\\' && c1 == '\n')	// ȥ���Ѵ���ɨ�軺���������з�'\'
					i--;
				else
				{
					if (c1 == '\t' || c1 == '\n' || c1 == '\r')	// ����'\r'�ͶԿո�Ĵ���
						c1 = ' ';
					if (c0 == ' ' && c1 == ' ')
						i--;
					Buf[i++] = c1;
				}
			}
			break;

		case true:								// ��ǰ�ַ�����ע���У��������ַ�
			if (c0 == '*' && c1 == '/')			// �뿪ע��
				in_comment = false;
		}											// end switch

		c0 = c1;								// ��ǰ�ַ���Ϊ��һ���ַ��� c0 <---c1
	}											// end while

	Buf[i] = '#';
}

void concat(char token[], char c)		// ƴ���ַ�����
{
	int i;
	for (i = 0; token[i]; i++);		// ����䣬�ҵ���β

	token[i] = c, token[++i] = '\0';
}

char reserve(char token[])
{
	const char *table[] = { "IF", "THEN", "ELSE", "GOTO" };		// �����ֱ�
	const char code[] = "ABCD";

	for (unsigned i = 0; i < strlen(code); i++)
		if (strcmp(token, table[i]) == 0)
			return code[i];

	return 'i';													// ��ʶ���ĵ����ֱ�Ϊ'i'
}

struct code_val scanner(char Buf[], int &i)		// ɨ�躯����ʶ�𵥴�
{
	struct code_val t = { '\0', "NUL" };		// token����ƴ�ӵ���
	char token[WordLen + 1] = "";

	if (Buf[i] >= 'a' && Buf[i] <= 'z' || Buf[i] >= 'A' && Buf[i] <= 'Z')			// ʶ���ʶ���������
	{
		while (Buf[i] >= 'a' && Buf[i] <= 'z' || Buf[i] >= 'A' && Buf[i] <= 'Z' || Buf[i] >= '0' && Buf[i] <= '9')
			concat(token, Buf[i++]);
		t.code = reserve(token);		// ������ֱ�

		if (t.code == 'i')
			strcpy_s(t.val, token);

		return t;
	}

	if (Buf[i] >= '0' && Buf[i] <= '9')			// ʶ������
	{
		while (Buf[i] >= '0' && Buf[i] <= '9')
			concat(token, Buf[i++]);
		
		t.code = 'x';
		strcpy_s(t.val, token);

		return t;
	}

	switch (Buf[i])								// ����������
	{
	case '(':									// ���
		t.code = '(';
		break;

	case ')':
		t.code = ')';
		break;
		
	case ':':
		t.code = ':';
		break;


	case '+':									// �����
		if (Buf[++i] == '+')
			t.code = '$';
		else
			t.code = '+', i--;
		break;

	case '-':
		if (Buf[++i] == '-')
			t.code = '@';
		else
			t.code = '-', i--;
		break;

	case '*':
		t.code = '*';
		break;

	case '/':
		t.code = '/';
		break;

	case '=':
		t.code = '=';
		break;

	case '>':
		if (Buf[++i] == '=')
			t.code = '%';
		else
			t.code = '>';
		break;

	case '<':
		if (Buf[++i] == '=')
			t.code = '^';
		else
			t.code = '<';
		break;

	case  '#':
		t.code = '#';
		break;

	default:
		cout << "Error char->" << Buf[i] << endl;
		exit(0);
		break;
	}

	i++;
	return t;
};

int main()
{
	char Buf[10000] = { '\0' };
	code_val t;

	ofstream coutf("C:\\Users\\hxs\\Documents\\Visual Studio 2013\\Projects\\BNG\\BNG\\Ԥ�����ļ�.txt", ios::out);	// ������coutf���� Ԥ�����ļ�
	ofstream coutn("C:\\Users\\hxs\\Documents\\Visual Studio 2013\\Projects\\BNG\\BNG\\��Ԫʽ�ļ�.txt", ios::out);		// ������coutn�����Ԫʽ�ļ�

	pretreament("C:\\Users\\hxs\\Documents\\Visual Studio 2013\\Projects\\BNG\\BNG\\source.txt", Buf);

	int i = 0;
	for (i = 0; Buf[i] != '#'; i++)		// д��Ԥ�����ļ�
		coutf << Buf[i];
	Buf[i] = '#';

	cout << '\n' << "<���ʶ�Ԫʽ>" << endl;

	i = 0;
	do
	{
		while (Buf[i] == ' ')	// ȥ��ǰ���ո�
			i++;

		t = scanner(Buf, i);	// ����һ��ɨ��ʽ���һ�����ʶ�Ԫʽ

		coutn << t.code << '\t' << t.val << endl;		// �����ʶ�Ԫʽд���Ԫʽ�ļ�

		cout << '(' << t.code << ',' << t.val << ')' << endl;	// ��Ļ������ʶ�Ԫʽ
	} while (t.code != '#');

	cout << endl;
	return 0;
}