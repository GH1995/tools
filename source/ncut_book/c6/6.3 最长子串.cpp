#include <iostream>
#include <string>
using namespace std;

int main()
{
    unsigned int t;             // 测试数据组数
    cin >> t;

    while (t--)                 // 处理一组数据
    {
        unsigned int n;         // 组内几组字符串
        cin >> n;


        unsigned int m;                     // 记录最短串的编号
        unsigned int minlen = 101;          // 保存最短串的长度，目前设为最大值
        char str[100][101];

        for (unsigned int i = 0; i < n; i++)    // 读入所有字符串
        {
            cin >> str[i];

            if (strlen(str[i]) < minlen)
            {
                minlen = strlen(str[i]);
                m = i;
            }
        }


        /*
        *   char minStr, int minlen, int m 失效
        *   int subtrlen = minlen 生效
        *
        */

        char minStr[101];                       // 最短的串
        strcpy(minStr, str[m]);
        unsigned int substrlen = minlen;        // 子串长度，由大到小取



        /*
        *   至此第一阶段已经结束
        */








        /*
        *   处理最短串
        *   由大到小在最短串中查找子串
        */

        unsigned int found = 1;                 // 标志位，1为找到了，0为没有找到
        while (substrlen > 0)                   
        {
            /*
            *   在substrlen长度确定的情况下while循环
            */



            /*
            *   子串！
            */
            char subStr[101];                   // 存放正向串
            char revSubStr[101];                // 存放逆向串





            for (unsigned int i = 0; i <= minlen - substrlen; i++)      // 可以取出长度为substrlen的子串个数，由大到小取
            {
                /*
                *   查找的子串长度不断变化
                */

                strncpy(subStr, minStr + i, substrlen);                 // 取正向子串
                subStr[substrlen] = '\0';

                strncpy(revSubStr, minStr + i, substrlen);              // 取逆向子串
                revSubStr[substrlen] = '\0';
                strrev(revSubStr);



                /*
                *   在所有串中查找是否包含正或逆向子串
                */

                found = 1;                  // 设置标志！！重要一步！刚刚忘记了
                for (unsigned int j = 0; j < n; j++)
                {
                    if (strstr(str[j], subStr) == NULL && strstr(str[j], revSubStr) == NULL)
                    {
                        found = 0;          // 在str[j]中不存在子串，摘帽子
                        break;
                    }
                }


                /*
                *   大部分情况下found = 0，这里用不到
                */
                if (found == 1)             // 找到子串，打断查找子串的循环
                    break;
            }

            if (found == 1)                 // 打断while循环结束本次任务
                break;                      // 找到子串，结束
            
            substrlen--;                    // 没找到，子串长度减1，再试！
        }

        cout << substrlen << endl;
    }

    return 0;
}