#include <iostream>
using namespace std;

int main()
{
    int x, y, z;
    int n = 0;

    for (int a = 1; a <= 9; a++)
        for (int b = 1; b <= 9; b++)
        {
            if (b == a)
                continue;
            for (int c = 0; c <= 9; c++)
            {
                if (c == a || c == b)
                    continue;
                for (int d = 1; d <= 9; d++)
                {
                    if (d == a || d == b || d == c)
                        continue;
                    for (int e = 0; e <= 9; e++)
                    {
                        if (e == a || e == b || e == c || e == d)
                            continue;

                        x = a * 100 + b * 10 + c;
                        y = d * 10 + a;
                        z = b * 1000 + c * 100 + d * 10 + e;

                        if (x*y == z)
                        {
                            n++;
                            cout << n << ": " << x << "*" << y << "=" << z << endl;
                        }
                    }
                }
            }
        }
    // cout << n << endl;

    return 0;
}