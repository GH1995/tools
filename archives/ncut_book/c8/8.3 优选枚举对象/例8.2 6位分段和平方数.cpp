#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    long m = (int)sqrt(100000);
    long n = (int)sqrt(999999);

    long k, x, y;

    for (int i = m; i <= n; i++)
    {
        k = i*i;
        x = k / 1000;
        y = k % 1000;

        if (i == x + y)
            cout << k << ' ';
    }
    cout << endl;
    return 0;
}