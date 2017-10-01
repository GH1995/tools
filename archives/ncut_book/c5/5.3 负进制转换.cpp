#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t;i++)
    {
        int n;
        int r;

        cin >> n >> r;

        char digit[] = { "0123456789ABCDEFGHIJ" };  // 表示20以内进制所用数码
        char result[100] = { '\0' };    // 转换后的结果
        int m = 99;                     // m为存放结果的开始位置
        int s = n;                      // 暂为保存 n 的值

        while (n != 0)
        {
            int k;                      // 余数

            if (n >= (n / r)*r)
            {
                k = n - (n / r)*r;      // 商
                n = n/r;                // n为除数，r为被除数
            }
            else
            {
                k = n - (n / r + 1)*r;  // 保证余数是正数
                n = n / r + 1;          // 商
            }

            result[--m] = digit[k];
            /*
            *   对于字符串的处理还存在很大的问题
            */
        }

        cout << s << result[m] << "BASE" << r << endl;
    }

    return 0;
}