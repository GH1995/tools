#include <iostream>
using namespace std;

int main()
{
    long n;

    while (true)
    {
        cin >> n;

        if (n < 0)
            return 0;

        if ((n + 2) % 4 == 0)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }

    return 0;
}