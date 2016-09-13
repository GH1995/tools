#include <iostream>
using namespace std;

int main()
{
    int n;
    int f[1000] = { 0 };            // 再次证明了f[1000]全是0，这种方法初始化一个数组是可行的

    cin >> n;
    f[1] = 1, f[2] = 2;

    for (int i = 3; i <= n; i++)
        f[i] = f[i - 1] + f[i - 2];

    cout << f[n] << endl;
    return 0;
}