#include <iostream>
using namespace std;

int main()
{
    int x, y;
    int n = 0;

    for (x = 10; x <= 99; x++)
    {
        y = 208 * x + 1;
        if (y > 9999)
            break;
        cout << ++n << ": " << y << "/" << x << "= 208" << endl;
    }

    return 0;
}