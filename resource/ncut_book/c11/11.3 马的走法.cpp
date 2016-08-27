#define M 4
#define N 5
#include <iostream>
using namespace std;

int move[8][2] =
{
	{-1, -2},
	{-1, 2},
	{-2, 1},
	{-2, -1},
	{2, 1},
	{2, -1},
	{1, 2},
	{1, -2}
};

int mark[M][N] =
{
	0, 0, 0, 0, 0,
	0, 0, 0, 0, 0,
	0, 0, 0, 0, 0,
	0, 0, 0, 0, 0
};

int SeekPath(int x, int y);
int sx, sy, num;

int main()
{
	cin >> sx >> sy;
	sx--, sy--;
	num = 0;
	mark[sx][sy] = 1;
	SeekPath(sx, sy);
	cout << num << endl;

	return 0;
}


int SeekPath(int x, int y)
{
	int dx, dy;

	for (int i = 0; i < 8; i++)
	{
		dx = x + move[i][0];
		dy = y + move[i][1];

		if (dx >= 0 && dy >= 0 && dx < M && dy < N && mark[dx][dy] == 0)
		{
			mark[dx][dy] = 1;
			SeekPath(dx, dy);
			mark[dx][dy] = 0;
		}

		if (dx == sx && dy == sy)
			num++;
	}

	return 0;
}