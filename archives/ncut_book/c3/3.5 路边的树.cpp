#include <iostream>
using namespace std;

int main()
{
    int trees[10001];
    int L, n;                       // L是路的长度，n是段数
    cin >> L >> n;

    for (int i = 0; i <= L; i++)    // 初始化置1
        trees[i] = 1;
    
    int begin, end;
    for (int i = 0; i < n; i++)
    {
        cin >> begin >> end;
        for (int j = begin; j <= end; j++)
            trees[j] = 0;           // j这里容易出错
    }

    int sum = 0;
    for (int i = 0; i <= L; i++)    // 统计
        sum += trees[i];

    cout << sum << endl;

    return 0;
}