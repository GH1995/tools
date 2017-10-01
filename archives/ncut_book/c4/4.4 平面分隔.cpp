#include <iostream>
using namespace std;

int main()
{
    while (true)
    {
        int n;
        cin >> n;

        if (n == 0)
            return 0;

        int f1 = 2, f2;
        for (int i = 1; i <= n; i++)
        {
            f2 = f1 + 2 * (i - 1);          // 转身
            f1 = f2;
        }
        cout << f2 << endl;
    }

    return 0;
}