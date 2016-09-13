#include <iostream>
using namespace std;

int main()
{
    int n;
    int r;
    cin >> n >> r;          // 从n中取r的组合

    int i = 1;
    int x[10];
    x[i] = 1;

    int s = 0;              // 统计
    while (1)
    {
        /*
        *   【检测条件】
        */
        int fg = 1;         // 默认满足条件
        for (int k = i - 1; k >= 1; k--)
            if (!(x[k] < x[i]))         // 要满足的条件
                fg = 0;

        /*
        *   【输出一个解】
        */
        if (fg == 1 && i == r)
        {
            s++;
            for (int j = 1; j <= r; j++)
                cout << x[j];
            cout << endl;
        }

        /*
        *   【扩充元素】
        */
        if (fg == 1 && i < n)
        {
            i++;
            x[i] = 1;
            continue;
        }

        /*
        *   【回溯】
        */
        while (x[i] == n && i > 1)
            i--;

        /*
        *   【试探结束】
        */
        if (i == 1 && x[i] == n)
            break;
        else
            x[i]++;
    }
    cout << s << endl;

    return 0;
}