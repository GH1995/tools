#include <iostream>
#include <string>
using namespace std;

int main()
{
    char sa[51];
    char sb[51];
    char sc[101];

    cin >> sa >> sb;    // 读入两个大数

    int a[50] = { 0 };  // 存储大数的整数类型数组
    int b[50] = { 0 };




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









    int c[100] = { 0 };     // 结果数组

    /*
    *   重要！！！！！！！！！
    *   乘法运算
    */
    for (int i = 0; i < aLen; i++)
        for (int j = 0; j < bLen; j++)
            c[i + j] += a[i] * b[j];        // i位和j位相乘，结果为i+j位










    /*
    *   找到最高位，用k存储
    */
    k = 99;
    while (k >= 0 && c[k] == 0)
        k--;


    /*
    *   处理进位
    */
    i = 0;              // 数组下标
    int d = 0;          // 进位
    while (i <= k)
    {
        c[i] += d;

        d = c[i] / 10;  // 得到进位
        c[i] %= 10;     // 进位结果

        i++;
    }


    /*
    *   处理最高位进位，可能数字特别大
    */
    while (d > 0)
    {
        c[i] = d % 10;
        d /= 10;
        i++;
    }



    k = i;              // 得到乘积的最高位，未填满

    /*
    *   逆置矩阵，老把戏
    */

    for (int i = k - 1; i >= 0; i--)
        sc[k - 1 - i] = c[i] + '0';

    sc[k] = '\0';

    cout << sc << endl;

    return 0;
}