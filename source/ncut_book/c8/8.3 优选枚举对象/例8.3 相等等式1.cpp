/*
*   我第一次写的程序
*   根本不切合实际！！！！！！
*   CPU利用率峰值达到47%
*/
#include <iostream>
using namespace std;

int main()
{
    int x, y, z;
    int n = 0;

    for (int a = 1; a <= 9; a++)
        for (int b = 1; a <= 9; b++)
            for (int c = 0; c <= 9; c++)
                for (int d = 1; d <= 9; d++)
                    for (int e = 0; e <= 9; e++)
                    {
                        x = a * 100 + b * 10 + c;
                        y = d * 10 + a;
                        z = b * 1000 + c * 100 + d * 10 + e;

                        if (x*y == z)
                        {
                            n++;
                            cout << "n: " << x << "*" << y << "=" << z << endl;
                        }
                    }

    return 0;
}