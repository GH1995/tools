#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int cube[101] = { 0 };
    for (int i = 0; i <= n; i++)
        cube[i] = i*i*i;

    for (int a = 6; a <= n; a++)
        for (int b = 2; b <= a - 3; b++)
        {
            if (cube[a] < cube[b] + cube[b + 1] + cube[b + 2])      // 遏制了过度循环
                break;

            for (int c = b + 1; c <= a - 2; c++)
            {
                if (cube[a] < cube[b] + cube[c] + cube[c + 1])      // 遏制了过度循环
                    break;

                for (int d = c + 1; d <= a - 1; d++)
                    if (cube[a] == cube[b] + cube[c] + cube[d])
                    {
                        cout << "Cube = " << a << ", " << "Triple = (" << b << ", " << c << ", " << d << ")" << endl;
                        break;          // 遏制了过度循环
                    }
            }
        }

    return 0;
}