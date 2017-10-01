#include <iostream>
using namespace std;

int main()
{
    long n;                 // ?
    double sum = 1.0;       // ?

    cin >> n;
    for (int i = 1; i <= n; i++)
        sum += log10(i);

    cout << (long)sum << endl;

    return 0;
}