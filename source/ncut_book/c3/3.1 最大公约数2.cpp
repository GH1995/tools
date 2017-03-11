/*
*   求n个整数的最大公约数
*/\r/\r/g

#include <stdio.h>
int main()
{
    int a, b, r, n;

    scanf("%d", &n);
    scanf("%d", &a);

    for (int i = 0; i < n-1; i++)       // 这里是n-1，因为a已经占去了一个位置
    {
        scanf("%d", &b);
        r = a%b;
        while (r != 0)
        {
            a = b;
            b = r;
            r = a%b;
        }
    }
    printf("%d\n", b);

    return 0;
}
