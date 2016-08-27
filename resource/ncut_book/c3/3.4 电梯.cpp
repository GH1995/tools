//#include <stdio.h>
//int main()
//{
//  int i, n, tm, from, to;
//
//  while (1)
//  {
//      scanf("%d", &n);
//      if (n == 0)
//          return 0;
//
//      tm = 0;
//      from = 0;
//
//      for (i = 0; i < n; i++)
//      {
//          scanf("%d", &to);
//          if (from < to)
//              tm += (to - from) * 6 + 5;
//          else
//              tm += (from - to) * 4 + 5;
//
//          from = to;
//      }
//
//      printf("%d\n", tm);
//  }
//
//  return 0;
//}

#include <iostream>
using namespace std;

int main()
{
    while (1)
    {
        int n;
        cin >> n;

        if (n == 0)
            return 0;

        int from = 0;
        int to = 0;
        int sum = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> to;
            if (from > to)
                sum += (from - to) * 4 + 5;
            else
                sum += (to - from) * 6 + 5;

            from = to;
        }

        cout << sum << endl;
    }

    return 0;
}