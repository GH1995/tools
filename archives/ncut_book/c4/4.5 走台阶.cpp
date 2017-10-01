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

        int f1 = 1;
        int f2 = 2;
        int f3;

        if (n == 1)
        {
            cout << 1 << endl;
            continue;
        }

        if (n == 2)
        {
            cout << 2 << endl;
            continue;
        }

        for (int i = 3; i <= n; i++)
        {
            f3 = f2 + f1;
            f1 = f2;
            f2 = f3;
        }

        cout << f3 << endl;
    }

    return 0;
}