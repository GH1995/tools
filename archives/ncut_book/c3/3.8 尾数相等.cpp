#include <iostream>
using namespace std;

int main()
{
    int d;                              // d组数据
    cin >> d;

    while (d-- > 0)
    {
        int a[1000] = { 0 };
        for (int i = 0; i < 1000; i++)  // 初始化数组
            a[i] = 0;

        int k;
        cin >> k;
        int flag = 0;                   // 标记数组是否大于1000
        if (k >= 1000)                  // (M*N)%R = (M*R * N%R)%R，所以下面成立，避免溢出
        {
            flag = 1;
            k = k % 1000;
        }

        int mi = 0;                     // 幂
        int Product = 1;                // 记录逐次相乘的积
        while (true)
        {
            mi++;
            Product *= k;

            // 现在开始动手整理数组
            if (flag == 1 || Product >= 1000)
            {
                flag = 1;
                Product = Product % 1000;
                if (a[Product] == 0)
                    a[Product] = mi;
                else
                    break;
            }
        }
        cout << a[Product] << ' ' << mi << endl;
    }
    return 0;
}