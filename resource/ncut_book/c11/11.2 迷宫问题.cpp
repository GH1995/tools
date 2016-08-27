#include <iostream>
using namespace std;

int mark[12][12];
int maze[12][12];
int move[4][2] =
{
	{0,1},
	{1,0},
	{0,-1},
	{-1,0}
};

int m;
int n;

struct
{
	int x[100], y[100];
	int top;
}path;

int SeekPath(int x, int y);

int main()
{
	cin >> m >> n;
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			cin >> maze[i][j];

	for (int i = 0; i <= m + 1; i++)
	{
		maze[i][0] = 1;
		maze[i][n + 1] = 1;
	}

	for (int j = 1; j <= n; j++)
	{
		maze[0][j] = 1;
		maze[m + 1][j] = 1;
	}

	for (int i = 0; i <= m + 1; i++)
		for (int j = 0; j <= n + 1; j++)
			mark[i][j] = 0;

	path.top = 0;
	if (SeekPath(1, 1))
	{
		path.x[path.top] = 1;
		path.y[path.top] = 1;
		path.top++;
	}

	int j = 1;
	for (int i = path.top - 1; i >= 0; i--)
	{
		cout << '(' << path.x[i] << ', ' << path.y[i] << ')';
		if ((j++) % 5 == 0)
			cout << endl;
	}
}

int SeekPath(int x, int y)
{
	mark[x][y] = 1;

	if (x == m && y == n)
		return 1;

	int g, h;
	for (int i = 0; i < 4; i++)
	{
		g = x + move[i][0];
		h = y + move[i][1];

		if (maze[g][h] == 0 && mark[g][h] == 0)
		{
			mark[g][h] = 1;

			if (SeekPath(g, h))
			{
				path.x[path.top] = g;
				path.y[path.top] = h;
				path.top++;

				return 1;
			}
		}
	}

	return 0;
}