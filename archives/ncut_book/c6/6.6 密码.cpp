/*
*	存在问题
*/\r/\r/g
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int prepare_key(char *key);
void encrypt(char *data, char const *key);
void decrypt(char *data, char const *key);


int main()
{
	char keyword[27];		// 密钥,不含空格
	char str[200];			// 文本，含有空格

	while (true)
	{
		int k;
		cin >> k;			//读入处理标志

		if (k == 0)			// 结束处理
			break;

		gets_s(keyword);	// 处理第2行，密钥
		gets_s(str);		// 处理第3行，加密或解密

		prepare_key(keyword);

		if (k == 1)
			encrypt(str, keyword);	// 加密
		if (k == 2)
			decrypt(str, keyword);	// 解密

		cout << str << endl;
	}
}

int prepare_key(char *key)
{
	int len = strlen(key);

	/*
	*	统计k中各字母出现的次数
	*	key存传入的字符串
	*	f[]存字母的个数
	*
	*/
	int f[26] = { 0 };
	for (int i = 0; i < len; i++)
		f[key[i] - 'A']++;				// 'A'--->f[0],'Z'--->f[25]


	/*
	*	去掉重复字母
	*	重要！！
	*/
	int k = 0;
	for (int i = 0; i < len; i++)
	{
		if (f[key[i] - 'A'] > 0)	// key中存入的字符出现次数大于0
		{
			key[k++] = key[i];
			f[key[i] - 'A'] = -1;	// -1标志已经出现过
		}
	}

	/*
	*	使用没出现过的字符补齐
	*	重要！！
	*/
	int i = 0;
	while (k < 26)
	{
		if (f[i] == -1)
		{
			i++;
			continue;
		}
		key[k] = i + 'A';
		k++, i++;
	}
	key[26] = '\0';

	return 1;
}



/*
*	加密函数
*/
void encrypt(char *data, char const *key)
{
	int len = strlen(data);
	for (int i = 0; i < len; i++)
	{
		if (isalpha(data[i]))
		{
			if (isupper(data[i]))
				data[i] = key[data[i] - 'A'];
			else
				data[i] = key[data[i] - 'a'] + 'a' - 'A';
		}
	}
}


/*
*	解密函数
*/
void decrypt(char *data, char const *key)
{
	int p[26];
	for (int i = 0; i < 26; i++)
		p[key[i] - 'A'] = i;

	int len = strlen(data);
	for (int i = 0; i < len; i++)
	{
		if (isalpha(data[i]))
		{
			if (isalpha(data[i]))
				data[i] = p[data[i] - 'A'] + 'A';
			else
				data[i] = p[data[i] - 'a'] + 'a';
		}
	}
}
