#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int c[10000] = { 0 };
    int d[10000] = { 0 };

    c[1] = 1, d[1] = 2;
    c[2] = 3, d[2] = 5;


    for (int i = 3; i <= n; i++)                // 求第i项的分子c[i]
    {
        int m = c[i - 1] + 1;                   // 查找c[i]值，从c[i-1]+1开始，从小往大跑

        while (true)                            // 重复试探m是否出现过
        {
            int flag = 0;                       // flag=0表示没出现过
            for (int j = i - 1; j > 0; j--)     // 从第i-1项分母向前找，从大往小跑
            {
                if (m == d[j])
                {
                    flag = 1;                   // 出现过，本次再找的必要
                    break;
                }

                if(d[j]<m)                      // m大的过界了
                    break;
            }

            if (flag == 0)                      // 没找到
            {
                c[i] = m;                       // m为当前分子的值
                break;
            }


            m++;                                // 取下一个数试探
        }

        d[i] = c[i] + i;                        // 分母
    }


    cout << c[n] << '/' << d[n] << endl;

    return 0;
}