#include <iostream>
using namespace std;

int main()
{
    long a, b, t;
    cin >> a >> b;

    if (a < b)
        t = a, a = b, b = t;

    for (int k = b; k >= 1; k--)
        if (a%k == 0 && b%k == 0)
        {
            cout << k << endl;
            break;
        }

    return 0;
}