#include <iostream>
#include <cmath>
using namespace std;

int check18(int m);
int checkdia(int m);



int main()
{
    int n = 0;

    for (int i = 12345678; i <= 87654321; i += 9)       // 各位和为9的倍数，利用整除性质，步长设为9
    {
        if (check18(i) == 0)    // 检查数字1~8
            continue;

        if (checkdia(i) == 0)   // 检查对角线
            continue;

        cout << i << "   ";
        n++;

        if (n % 6 == 0)
            cout << endl;
    }

    cout << '\n' << "总方案数：" << n << endl;

    return 0;
}







/*
*   功能：
*   检查1~8是否各出现一次，若是，返回1，否则返回0
*
*/
int check18(int m)
{
    int f[10] = { 0 };  // 数字0~9，f[0]不用

    while (m != 0)      // 拆分m各位数字
    {
        f[m % 10]++;    // 对应的数组元素加1
        m /= 10;
    }

    int flag = 1;       // 一个脆弱的假设
    for (int i = 1; i <= 8; i++)
        if (f[i] != 1)
        {
            flag = 0;   // 一失足成千古恨
            break;
        }

    return flag;
}






/*
*   功能：
*   检查不在同一对角线上返回1，否则返回0
*
*/
int checkdia(int m)
{
    /*
    *   将数字按照正常顺序存入g数组,g[0]不用
    */
    int g[9] = { 0 };
    for (int i = 8; i >= 1; i--)
    {
        g[i] = m % 10;
        m /= 10;
    }


    /*
    *   检查约束条件
    */
    int flag = 1;
    for (int i = 1; i <= 7; i++)
        for (int j = i + 1; j <= 8; j++)
            if (abs(g[j] - g[i]) == j - i)
            {
                flag = 0;
                break;
            }

    return flag;
}