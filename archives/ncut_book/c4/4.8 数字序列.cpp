#include <iostream>
using namespace std;

int main()
{
    while (true)
    {
        int a, b, n;
        cin >> a >> b >> n;

        if (a == 0 && b == 0 && n == 0)
            return 0;

        int f1 = 1;
        int f2 = 1;
        int f3;
        for (int i = 3; i <= n; i++)
        {
            f3 = (a*f2 + b*f1) % 7;
            f1 = f2;
            f2 = f3;
        }
        cout << f3 << endl;
    }

    return 0;
}

// 在mod这里要注意！