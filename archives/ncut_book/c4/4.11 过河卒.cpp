#define N 17
#define M 17

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int dx[8] = { 2,1,-1,-2,-2,-1,1,2 };        // 设置初始偏移量
    int dy[8] = { 1,2,2,1,-1,-2,-2,-1 };            

    int m, n, x, y;                             // 读入坐标
    cin >> n >> m >> x >> y;

    int f[N][M];                                // 初始化
    int g[N][M];
    for (int i = 0; i <= n; i++)                
        for (int j = 0; j <= m; j++)
        {
            f[i][j] = 0;                        // 初始化，到达该点的方案数为0
            g[i][j] = 1;                        // g表示可达
        }


    g[x][y] = 0;                                // 马位置为控制点

    int tx;                                     // 在有效范围内，设置控制点
    int ty;
    for (int i = 0; i < 8; i++)
    {
        tx = x + dx[i];
        ty = y + dy[i];

        if (tx >= 0 && ty >= 0 && tx <= n && ty <= m)
            g[tx][ty] = 0;
    }

    if (g[0][0] == 1)                           // (0, 0)可达
        f[0][0] = 1;

    /*
    *   思维陷阱：
    *       如果该点不可达，卒要直走，那么之后的点要如何到达？
    */

    f[0][0] = 1;
    for (int i = 1; i <= n; i++)
        if (g[i][0] == 1)
            f[i][0] = f[i - 1][0];              // 计算最左边各点的方案数

    for (int j = 1; j <= m; j++)
        if (g[0][j] == 1)
            f[0][j] = f[0][j - 1];              // 计算最上边各点的方案数
    
    // 递推过程
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (g[i][j] == 1)
                f[i][j] = f[i - 1][j] + f[i][j - 1];

    cout << f[n][m] << endl;

    return 0;
}
