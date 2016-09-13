#include <iostream>
using namespace std;

int main()
{
    int cube[101] = { 0 };

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
        cube[i] = i*i*i;

    for (int a = 6; a <= n; a++)
        for (int b = 2; b <= a - 3; b++)
            for (int c = b + 1; c <= a - 2; c++)
                for (int d = c + 1; d <= a - 1; d++)
                    if (cube[a] == cube[b] + cube[c] + cube[d])
                        cout << "Cube = " << a << ", " << "Triple = (" << b << ", " << c << ", " << d << ")" << endl;

    return 0;
}