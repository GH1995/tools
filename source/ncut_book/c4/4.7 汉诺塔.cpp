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

        if (n == 1)
        {
            cout << 1 << endl;
            continue;
        }

        int f1 = 2;
        int f2;

        for (int i = 2; i <= n; i++)
        {
            f2 = 3 * f1 + 2;
            f1 = f2;
        }
        cout << f2 << endl;
    }

    return 0;
}