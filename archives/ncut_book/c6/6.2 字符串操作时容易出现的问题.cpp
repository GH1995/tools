#include <stdio.h>

int main()
{
    char str1[100], str2[100];
    int i, j;
    scanf("%s", str1);
    i = 0;
    j = 0;
    while (str1[i]!='\0')
    {
        if (str1[i] >= '0'&&str1[i] <= '9')
            str2[j++]=str1[i];
        i++;
    }
    printf("%s\n", str2);

    return 0;
}

// 忘了加'\0'
/*
*   编译器说你是对的
*/