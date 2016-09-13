#include <iostream>
using namespace std;

int dsum(int n);

int main()
{
    int m;                  // 代表输入的数
    int count = 0;          // 计数
    int a[1000] = { 0 };    // 存储空间

    while (1)
    {
        cin >> m;
        a[count] = m;

        if (m == 0)
            return 0;

        int flag = 1;       // 1表示没有找到
        while (flag)
        {
            m = dsum(m);
            count++;
            a[count] = m;

            for (int i = 0; i < count; i++)
                if (a[i] == m)
                {
                    flag = 0;
                    break;
                }
        }

        for (int i = 0; i <= count; i++)
            cout << a[i] << ' ';
        cout << endl;
    }

    return 0;
}

int dsum(int n)
{
    int k = 0;
    int sum = 0;

    while (n > 0)
    {
        k = n % 10;
        sum += k*k;
        n /= 10;
    }

    return sum;
}