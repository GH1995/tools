#include <iostream>
using namespace std;

int convert(int m, int k);              // 将k进制数m转换成10进制数返回
int maxdigit(int m);                    // 找出m中各位数字的最大值返回


int main()
{
    int n;
    cin >> n;

    int p, q, r;
    for (int i = 0; i < n; i++)
    {
        cin >> p >> q >> r;

        int dp;
        int dq;
        int dr;
        int d;
        int e;

        int a = maxdigit(p);
        int b = maxdigit(q);
        int c = maxdigit(r);

        if (a > b)
            d = a;
        else
            d = b;
        if (d > c)
            e = d;
        else
            e = c;


        int j = ++e;                        // 假设j为进制
        for (; j <= 16; j++)
        {
            dp = convert(p, j);
            dq = convert(q, j);
            dr = convert(r, j);

            if (dp*dq == dr)
            {
                cout << j << endl;
                break;
            }
        }

        if (j > 16)
        {
            cout << 0 << endl;
            break;
        }
    }

    return 0;
}


int convert(int m, int k)               // 将k进制数m转换成10进制数返回
{
    int p = 1;                          // p为k的次方数
    int s = 0;

    while (m != 0)
    {
        s += (m % 10) * p;
        m /= 10;
        p = p*k;
    }

    return s;
}

int maxdigit(int m)                     // 找出m中各位数字的最大值返回
{
    int maxd = 0;
    int k;

    while (m != 0)
    {
        k = m % 10;
        if (k > maxd)
            maxd = k;
        m /= 10;
    }

    return maxd;
}