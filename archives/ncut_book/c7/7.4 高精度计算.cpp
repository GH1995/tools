/*
*   存在问题
*/\r/\r/g
#define N 160
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t-- > 0)
    {
        char sa[8];
        int n;
        cin >> sa >> n;
        int aLen = strlen(sa);
        int k = aLen - 1;
        while (k>=0 && sa[k]!='.')
            k--;
        int pot;
        if (k < 0)
            pot = 0;
        else
        {
            int j = aLen - 1;
            while (j > 0 && sa[j] == '0')
                j--;
            aLen = j + 1;
            sa[aLen] = '\0';
            pot = aLen - k - 1;
        }
        
        int i = aLen - 1;
        k = 0;
        while (i>=0)
        {
            if (sa[i] != '.')
                a[k++] = sa[i] - '0';
            i--;
        }
        int b[N] = { 0 };
        aLen = k;
        int bLen = k;
        for (int i = 0; i < N; i++)
            b[i] = a[i];
        for (int i = 0; i < aLen; i++)
            bLen =Mult(a, b, aLen, bLen);
        k = pot*n;
        int n = bLen > k ? bLen : k;

        int j = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (i == k - 1)
                sb[j++] = '.';
            sb[j++] = b[i] + '0';
        }
        sb[j] = '\0';
        cout << sb << endl;

        return 0;
    }
}



int Mult(int *p1, int *p2, int len1, int len2)
{
    int ts[N] = { 0 };

    for (int i = 0; i < len1; i++)
        for (int j = 0; j < len2; j++)
            ts[i + j] += p1[i] * p2[j];
    
    /*
    *   找到最高位，用k存储
    */
    int k = len1 + len2;
    while (k > 0 && ts[k] == 0)
        k--;



    int d = 0;
    for (int i = 0; i <= k; i++)
    {
        p2[i] = (ts[i] + d) % 10;   // 
        d = (ts[i] + d) / 10;       // 
    }

    if (d > 0)
    {
        p2[i] = d;
        k++;
    }

    return k;
}
