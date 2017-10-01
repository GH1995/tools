#include <iostream>
#include <string>
using namespace std;

char a[100][100];
int b[100][100];
int m;
int n;
int x[] = { 0,-1,-1,-1,0,1,1,1 };
int y[] = { 1,1,0,-1,-1,-1,0,1 };

void dfs(int i, int j)
{
    b[i][j] = 0;

    int tx;
    int ty;

    for (int k = 0; k < 8; k++)
    {
        tx = i + x[k];
        ty = j + y[k];
        if (tx >= 0 && tx < n && ty >= 0 && ty < m && b[tx][ty] && a[tx][ty] == '@')
            dfs(tx, ty);
    }
}



int main()
{
    int num;

    while (1)
    {
        cin >> n >> m;
        if (n == 0 && m == 0)
            break;
        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                b[i][j] = 1;

        num = 0;
        for (int i = 0; i < n; i++)
            cin >> a[i];

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m;j++)
                if (b[i][j] && a[i][j] == '@')
                {
                    num++;
                    dfs(i, j);
                }
                
        cout << num << endl;
    }

    return 0;
}

int queue[10000][2];
void bfs(int i, int j)
{
    int head = 0;
    int tail = 0;

    queue[tail][0] = i;
    queue[tail][1] = j;

    tail++;
    b[i][j] = 0;

    int cx;
    int cy;

    while (head <tail)
    {
        cx = queue[head][0];
        cy = queue[tail][1];
        head++;

        for (int k = 0; k < 8; k++)
        {
            tx = cx + x[k];
            ty = cy + y[k];

            if (tx >= 0 && tx < n && ty >= 0 && ty < m && b[tx][ty] && a[tx][ty] == '@')
            {
                queue[tail][0] = tx;
                queue[tail][1] = ty;
                tail++;
                b[tx][ty] = 0;
            }
        }
    }
}