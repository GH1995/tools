#include <stdio.h>

int main()
{
    int a, b, r;

    scanf("%d%d", &a, &b);
    r = a%b;                    // r作为余数，假设a较大
    while (r!=0)                // 此时r=b了
    {
        a = b;                  // 将b放在大数的位置
        b = r;                  // 将余数r放在余数的位置
        r = a%b;                // 大数%小数再次生成余数
    }
    printf("%d\n", b);

    return 0;
}