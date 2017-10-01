#include <iostream>
using namespace std;

int main()
{
    int f[5] = { 0 };   // 存储鱼的数量
    int flag = 1;       // 未发现合适值，需要进行下一次验证
    int n = 1;          // 从f[0]=1开始推测

    while (flag)
    {
        f[0] = 5 * n + 1;
        flag = 0;
        for (int i = 1; i < 5; i++)
        {
            if (f[i - 1] % 4 != 0)
            {
                flag = 1;
                break;
            }
            f[i] = 5 * f[i - 1] / 4 + 1;
        }
        n++;
    }
    cout << f[4] << endl;

    return 0;
}