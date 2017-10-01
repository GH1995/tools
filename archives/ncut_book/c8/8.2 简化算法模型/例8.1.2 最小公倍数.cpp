#include <iostream>
using namespace std;

int main()
{
    long a, b, t;
    cin >> a >> b;
    if (a < b)
        t = a, a = b, b = t;

    for (int k = a; k <= a*b; k += a)       // k = k + a
        if (k%a == 0 && k%b == 0)
        {
            cout << k << endl;
            break;
        }

    return 0;
}