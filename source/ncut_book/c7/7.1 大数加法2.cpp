#include <iostream>
#include <string>
using namespace std;

int main()
{
    /*
    *   读入两个大数求和
    */
    int maxlen = 0;
    int sum[201] = { 0 };   // 计算和的结果
    char s[202];            // 存入大数

    for (int i = 0; i < 2; i++)
    {
        cin >> s;

        int len = strlen(s);

        if (len > maxlen)
            maxlen = len;

        /*
        *   颠倒并求和，原来的写法
        *   重要！
        */
        /*for (int j = len - 1; j >= 0; j--)
            sum[len - 1 - j] += s[j] - '0'; */

        /*
        *   我的实现，复杂的写法本身就是不负责任
        */
        int k = 0;
        for (int j = len - 1; j >= 0; j--)
        {
            sum[k] += s[j] - '0';
            k++;
        }
    }



    /*
    *   处理结果中的进位，从低位开始
    */
    int d = 0;      // 进位
    for (int i = 0; i < maxlen; i++)
    {
        sum[i] += d;
        d = sum[i] / 10;
        sum[i] %= 10;
    }

    /*
    *   向最高位进位
    */
    if (d > 0)
        sum[maxlen++] += d;

    /*
    *   以字符串形式保存
    */
    /*for (int i = maxlen - 1; i >= 0; i--)
        s[maxlen - 1 - i] = sum[i] + '0';*/

    /*
    *   我的实现
    */
    int k = 0;
    for (int i = maxlen - 1; i >= 0; i--)
    {
        s[k] = sum[i] + '0';
        k++;
    }

    s[maxlen] = '\0';

    cout << s << endl;

    return 0;
}