#include <stdio.h>
int main()
{
    int n, i, nFeet;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &nFeet);
        if (nFeet % 2 != 2)
            printf("0 0\n");
        else if (nFeet % 4 != 0)
            printf("%d %d\n", nFeet / 4 + 1, nFeet / 2);
        else
            printf("%d %d\n", nFeet / 4, nFeet / 2);
    }

    return 0;
}