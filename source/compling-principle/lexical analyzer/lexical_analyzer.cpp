/*
pretreatment()		预处理函数
scanner()			扫描函数，识别单词
contact()			拼接字符
reserve()			查基本字表函数
main()				主函数

main调用pretreatment进行预处理，然后不断调用扫描函数scanner，获得单词的二元式码，并将其写入 二元式.txt，直到源程序结束

符号表		标识符，基本字，运算符，界符，常数

	code		val
	i（标识符）	**
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

struct code_val							// 内部码的定义
{
	char code;							// 单词种别
	char val[WordLen + 1];				// 单词值
};

void pretreament(char filename[], char Buf[])	
{

	/*
			任务：
				1.删除注释
				2.删除续行符，包括后续的换行符
				3.将换行符和Tab统一替换为空格
				4.将经预处理的程序存入扫描缓冲区，供扫描器识别单词
	*/


	ifstream cinf(filename, ios::in);			// 定义输入流对象ifstream
	char c0 = '$', c1;							// c0为前一个字，c1为当前字符
	bool in_comment = false;					// 状态标志，false表示当前字符为处于注释中

	cout << "<源程序>" << endl;

	int i = 0;									// 置Buf[0]

	while (cinf.read(&c1, sizeof(char)))
	{
		cout << c1;

		switch (in_comment)
		{
		case false:								// 上一字符还未处于注释中
			if (c0 == '/' && c1 == '*')			// 如果进入注释，去除已存入扫描缓冲区的字符'/'
				in_comment = true, i--;
			else
			{
				if (c0 == '\\' && c1 == '\n')	// 去除已存入扫描缓冲区的续行符'\'
					i--;
				else
				{
					if (c1 == '\t' || c1 == '\n' || c1 == '\r')	// 新增'\r'和对空格的处理
						c1 = ' ';
					if (c0 == ' ' && c1 == ' ')
						i--;
					Buf[i++] = c1;
				}
			}
			break;

		case true:								// 当前字符处于注释中，丢弃该字符
			if (c0 == '*' && c1 == '/')			// 离开注释
				in_comment = false;
		}											// end switch

		c0 = c1;								// 当前字符成为下一个字符， c0 <---c1
	}											// end while

	Buf[i] = '#';
}

void concat(char token[], char c)		// 拼接字符函数
{
	int i;
	for (i = 0; token[i]; i++);		// 空语句，找单词尾

	token[i] = c, token[++i] = '\0';
}

char reserve(char token[])
{
	const char *table[] = { "IF", "THEN", "ELSE", "GOTO" };		// 基本字表
	const char code[] = "ABCD";

	for (unsigned i = 0; i < strlen(code); i++)
		if (strcmp(token, table[i]) == 0)
			return code[i];

	return 'i';													// 标识符的单词种别为'i'
}

struct code_val scanner(char Buf[], int &i)		// 扫描函数，识别单词
{
	struct code_val t = { '\0', "NUL" };		// token用于拼接单词
	char token[WordLen + 1] = "";

	if (Buf[i] >= 'a' && Buf[i] <= 'z' || Buf[i] >= 'A' && Buf[i] <= 'Z')			// 识别标识符或基本字
	{
		while (Buf[i] >= 'a' && Buf[i] <= 'z' || Buf[i] >= 'A' && Buf[i] <= 'Z' || Buf[i] >= '0' && Buf[i] <= '9')
			concat(token, Buf[i++]);
		t.code = reserve(token);		// 查基本字表

		if (t.code == 'i')
			strcpy_s(t.val, token);

		return t;
	}

	if (Buf[i] >= '0' && Buf[i] <= '9')			// 识别整数
	{
		while (Buf[i] >= '0' && Buf[i] <= '9')
			concat(token, Buf[i++]);
		
		t.code = 'x';
		strcpy_s(t.val, token);

		return t;
	}

	switch (Buf[i])								// 界符与运算符
	{
	case '(':									// 界符
		t.code = '(';
		break;

	case ')':
		t.code = ')';
		break;
		
	case ':':
		t.code = ':';
		break;


	case '+':									// 运算符
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

	ofstream coutf("C:\\Users\\hxs\\Documents\\Visual Studio 2013\\Projects\\BNG\\BNG\\预处理文件.txt", ios::out);	// 定义了coutf输入 预处理文件
	ofstream coutn("C:\\Users\\hxs\\Documents\\Visual Studio 2013\\Projects\\BNG\\BNG\\二元式文件.txt", ios::out);		// 定义了coutn输入二元式文件

	pretreament("C:\\Users\\hxs\\Documents\\Visual Studio 2013\\Projects\\BNG\\BNG\\source.txt", Buf);

	int i = 0;
	for (i = 0; Buf[i] != '#'; i++)		// 写入预处理文件
		coutf << Buf[i];
	Buf[i] = '#';

	cout << '\n' << "<单词二元式>" << endl;

	i = 0;
	do
	{
		while (Buf[i] == ' ')	// 去除前导空格
			i++;

		t = scanner(Buf, i);	// 调用一次扫描式获得一个单词二元式

		coutn << t.code << '\t' << t.val << endl;		// 将单词二元式写入二元式文件

		cout << '(' << t.code << ',' << t.val << ')' << endl;	// 屏幕输出单词二元式
	} while (t.code != '#');

	cout << endl;
	return 0;
}