#include <iostream>
#include <string>
using namespace std;

int main()
{
    char sa[201];       // 201,因为多了一个'\0'
    char sb[202];
    int ia[200] = { 0 };
    int ib[201] = { 0 };

    cin >> sa >> sb;

    int aLen = strlen(sa);      // 测出sa的长短
    int i = aLen - 1;           // i比aLen小1，必有深意——>代表数组下标的最大值




    
    int k = 0;                  // 将sa中的数字填入ia中，此时ib长i
    while (i >= 0)
    {
        ia[k] = sa[i] - '0';
        k++;
        i--;
    }
                                // k会多出来一位
    int bLen = strlen(sb);      // 测出sb的长短
    i = bLen - 1;               // 代表数组下标的最大值

    k = 0;                      // 将sb中的数字填入ib中，此时ib长i
    while (i>=0)
    {
        ib[k] = sb[i] - '0';
        k++;
        i--;
    }





    /*
    *   重要
    */
    int d = 0;                      // 进位初值为0
    k = aLen > bLen ? aLen : bLen;  // 结果位长设为aLen和bLen中较长的

    i = 0;
    while (i < k)
    {
        ib[i] += ia[i] + d;     // 各对应位相加

        d = ib[i] / 10;         // 得到进位
        ib[i] %= 10;            // 得到对应位相加的结果

        i++;
    }






    if (d > 0)          // 下一位上要不要填入数字
        ib[k] += d;     // 最高位有进位
    else
        k--;            // k的值回到数组下标处


    for (int i = k; i >= 0; i--)    // 挨个转换为字符从ib转存入sb中
        sb[k - i] = ib[i] + '0';
    sb[k + 1] = '\0';

    cout << sb << endl;

    return 0;
}