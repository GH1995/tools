#include <iostream>
using namespace std;

int main()
{
    int m = 0;
    int n = 100;
    int c = 0;

    for (int p1 = 0; p1 <= n; p1++)
        for (int p2 = 0; p2 <= n / 2; p2++)
            for (int p5 = 0; p5 <= n / 5; p5++)
                for (int p10 = 0; p10 <= n / 10; p10++)
                    for (int p20 = 0; p20 <= n / 20; p20++)
                        for (int p50 = 0; p50 <= n / 50; p50++)
                        {
                            c++;
                            if (p1 + 2 * p2 + 5 * p5 + 10 * p10 + 20 * p20 + 50 * p50 == n)
                                m++;
                        }
    cout << m << endl;
    cout << c << "次" << endl;

    return 0;
}