#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int f1 = 1;
    int f2 = 2;
    int f3;

    if (n == 1)
    {
        cout << n << endl;
        return 0;
    }

    if(n==2)
    {
        cout << n << endl;
        return 0;
    }

    for (int i = 3; i <= n; i++)
    {
        f3 = f2 + f1;
        f1 = f2;
        f2 = f3;
    }
    cout << f3 << endl;

    return 0;
}