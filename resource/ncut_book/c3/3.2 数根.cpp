#include <stdio.h>

int main()
{
    long s, m;

    while (1)
    {
        scanf("%ld", &m);
        if (m == 0)
            break;
        do
        {
            s = 0;                  // 累加数位
            while (m > 0)
            {
                s += m % 10;        // 累加数位
                m /= 10;
            }
            m = s;
        } while (m >= 10);
        printf("%ld\n", s);
    }

    return 0;
}