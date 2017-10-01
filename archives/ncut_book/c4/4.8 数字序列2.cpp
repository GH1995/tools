#include <iostream>
using namespace std;

int main()
{
    while (true)
    {
        int f[50] = { 0 };
        f[1] = 1;
        f[2] = 2;

        int a, b;
        long n;
        cin >> a >> b >> n;

        if (a == 0 && b == 0 && n == 0)             // 以上容易明白
            return 0;

        int m = 0;      // m为第一个周期的开始位置
        int k;          // k为循环周期
        for (int i = 3; i <= 42; i++)
        {
            f[i] = (a*f[i - 1] + b*f[i - 2]) % 7;

            for (int j = 2; j < i;j++)
                if (f[j - 1] == f[i - 1] && f[j] == f[i])       // 判断是否出现循环
                {
                    m = j - 1;
                    k = i - j;
                    break;
                }

            if (m != 0)
                break;
        }

        if (n < m)
            cout << f[n] << endl;
        else
            cout << f[(n - (m - 1)) % k + m - 1] << endl;
    }

    return 0;
}