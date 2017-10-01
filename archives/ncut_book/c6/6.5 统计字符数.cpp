#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    while (n--)
    {
        char str[81];
        cin >> str;

        int count[26] = { 0 };          // 26个字母的计数器


        /*
        *   重点！
        */
        int i = 0;
        while (str[i] != '\0')
        {
            count[str[i] - 'a']++;      // a->0, b->1
            i++;
        }

        /*
        *   查找出现次数最多的
        */
        int k = 0;
        for (int i = 1; i < 26; i++)
            if (count[i] > count[k])
                k = i;
        
        cout << char('a' + k) << ' ' << count[k] << endl;
    }

    return 0;
}