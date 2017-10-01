/*
*   存在问题
*/\r/\r/g

#define N 100

#include <iostream>
#include <string>
using namespace std;

// 用p1(长度len1)减去p2(长度len2)，返回一个数值
int Subtract(int *p1, int *p2, int len1, int len2);

int main()
{
    int t;
    cin >> t;

    char sa[N + 1];
    char sb[N + 1];
    char sc[N + 1];

    int a[N] = { 0 };
    int b[N] = { 0 };
    int c[N] = { 0 };

    while (t-- > 0)
    {
        cin >> sa >> sb;







        /*
        *   将整数sa颠倒后保存到对应的整数数组a中
        */
        int aLen = strlen(sa);
        int i = aLen - 1;
        int k = 0;
        while (i >= 0)
            a[k++] = sa[i--] - '0';


        /*
        *   将整数sb颠倒后保存到对应的整数数组b中
        */
        int bLen = strlen(sb);
        i = bLen - 1;
        k = 0;
        while (i >= 0)
            b[k++] = sb[i--] - '0';




        /*
        *   没有必要了
        */
        if (aLen < bLen)
        {
            cout << 0 << endl;
            continue;
        }





        /*
        *   重要！！！
        *   将除数扩大10^n倍，使得除数和被除数位长相等
        */
        int nTime = aLen - bLen;    // 相差倍数
        for (int i = aLen - 1; i >= 0; i--)
        {
            if (i >= nTime)
                b[i] = b[i - nTime];
            else
                b[i] = 0;
        }



        bLen = aLen;
        for (int i = 0; i <= nTime; i++)
        {
            while ((k = Subtract(a, b + i, aLen, bLen - 1)) >= 0)
            {
                aLen = k;
                c[nTime - i]++;
            }
        }

        k = N - 1;
        while (k > 0 && c[k] == 0)
            k--;

        i = 0;
        int d = 0;

        while (i <= k)
        {
            c[i] += d;
            d = c[i] / 10;
            c[i] %= 10;
            i++;
        }

        while (d > 0)
        {
            c[i] = d % 10;
            d /= 10;
            i++;
        }

        k = i;
        for (int i = k - 1; i >= 0; i--)
            sc[k - 1 - i] = c[i] + '0';
        sc[k] = '\0';

        cout << sc << endl;
    }

    return 0;
}



/*
*   功能：
*       用p1(长度len1)减去p2(长度len2)，返回一个数值
*
*       结果放在p1中，返回值：
*       <1>     -1      不够减
*       <2>     0       正好减完
*       <3>     > 0     结果的长度
*
*       p1[0],p2[0]为大数的个位
*/

int Subtract(int *p1, int *p2, int len1, int len2)
{
    /*
    *   情况<1>，数位不等
    */
    if (len1 < len2)
        return -1;

    /*
    *   情况<2>
    */
    if (len1 == len2)
    {
        int count = 0;
        for (int i = 0; i < len1; i++)
        {
            if (p1[i] == p2[i])
                count++;
            else
                break;
        }

        if (count == len1)
            return 0;
    }

    /*
    *   其他
    */
    if (len1 == len2)
    {
        for (int i = len1 - 1; i >= 0; i--)
        {
            if (p1[i] > p2[i])              // p1 > p2, 做减法，转情况<3>
                break;
            if (p1[i] < p2[i])
                return -1;                  // p1 < p2, 同上，返回 -1，转情况<1>
        }
    }





    // 剩下的都是情况<3>了







    /*
    *   重要！！
    *   从低位开始做减法,情况<3>
    */
    for (int i = 0; i < len1; i++)
    {
        p1[i] = p1[i] - p2[i];
        if (p1[i] < 0)
        {
            p1[i + 1]--;    // 高位借1
            p1[i] += 10;    // 借1当10
        }
    }


    /*
    *   查找结果的最高位
    */
    for (int i = len1 - 1; i >= 0; i--)
        if (p1[i] != 0)
            return i + 1;   // 得到结果位数并返回
}
