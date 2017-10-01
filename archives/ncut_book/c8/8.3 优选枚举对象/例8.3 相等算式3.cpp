// abc*da=bcde

#include <iostream>
using namespace std;

int main()
{
    int a;
    int b;
    int c;
    int d;
    int e;

    int s, j;
    int n = 0;

    for (int i = 123; i <= 987; i++)
    {
        a = i / 100;
        b = i / 10 % 10;
        c = i % 10;

        if (b == 0)
            continue;

        if (a == b || a == c || b == c)
            continue;

        for (d = 1; d <= 9; d++)
        {
            if (d == a || d == b || d == c)     // 枚举2位整数的十位
                continue;

            j = d * 10 + a;     // 二位整数
            s = i*j;            // 计算乘积

            if (s < 1000 || s > 9999)
                continue;
            if (s / 1000 != b)
                continue;
            if (s / 100 % 10 != c)
                continue;
            if (s / 10 % 10 != d)
                continue;

            e = s % 10;
            if (e == a || e == b || e == c || e == d)
                continue;

            cout << ++n << ": " << a << b << c << '*' << d << a << '=' << s << endl;
            return 0;
        }
    }
}