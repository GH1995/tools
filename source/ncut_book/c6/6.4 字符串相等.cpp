#include <iostream>
#include <string>
using namespace std;

int main()
{
    char s1[81];
    char s2[81];
    char str[81];


    unsigned int t;
    cin >> t;
    gets_s(s1);				// 处理数字之后的回车键

    while (t--)				// 处理单组字符串，3条
    {
        gets_s(s1);
        gets_s(s2);
        gets_s(str);

        strupr(s1);
        strupr(s2);

        unsigned int i = 0;
        unsigned int j = 0;
        unsigned int flag = 1;


        // 处理字符串
        while (s1[i] || s2[j])                  // 这里书上写错了
        {
        	/*
        	* 这里的处理方式非常好
        	*/

            while (s1[i] && s1[i]<'A' || s1[i]>'Z')
                i++;
            while (s2[j] && s2[j]<'A' || s2[j]>'Z')
                j++;

            if (s1[i] != s2[j])
            {
                flag = 0;
                break;
            }

            if (s1[i] == '\0' || s2[j] == '\0')
                break;

            i++, j++;
        }

        if (flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}