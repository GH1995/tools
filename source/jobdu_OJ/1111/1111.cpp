/*
题目描述：
输入一个字符串，以回车结束（字符串长度<=100）。该字符串由若干个单词组成，单词之间用一个空格隔开，所有单词区分大小写。现需要将其中的某个单词替换成另一个单词，并输出替换之后的字符串。
输入：
多组数据。每组数据输入包括3行，
第1行是包含多个单词的字符串 s，
第2行是待替换的单词a，(长度<=100)
第3行是a将被替换的单词b。(长度<=100)
s, a, b 最前面和最后面都没有空格.
输出：
每个测试数据输出只有 1 行，
将s中所有单词a替换成b之后的字符串。
样例输入：
You want someone to help you
You
I
样例输出：
I want someone to help you
来源：
2007年北京大学计算机研究生机试真题
答疑：
解题遇到问题?分享解题心得?讨论本题请访问：http://t.jobdu.com/thread-7834-1-1.html
*/\r/\r/g

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void ReplaceAll(string &str, string &from, string &to)
{
	for (string::size_type pos = 0; pos != string::npos; pos+=to.length())
	{
		if ((pos = str.find(from, pos)) != string::npos)
			str.replace(pos, from.length(), to);
		else
			break;
	}
}

int main()
{
	string s, a, b;
	while (getline(cin, s) && cin >> a >> b)
	{
		ReplaceAll(s, a, b);
		cout << s << endl;
	}

	return 0;
}
