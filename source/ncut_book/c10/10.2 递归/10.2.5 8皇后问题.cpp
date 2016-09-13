#include <iostream>
#include <cmath>
using namespace std;

int board[8][8];
int count = 0;

void putQueen(int ithqueen)
{
	if (ithqueen == 8)
	{
		count++;
		return;
	}

	for (int i = 0; i < 8;i++)
		if (board[i][ithqueen] == -1)
		{
			board[i][ithqueen] == ithqueen;
			for (int k = 0; k < 8; k++)
				for (int r = 0; r < 8; r++)
					if (board[k][r] == -1 && (k == i || r == ithqueen || abs(k - i) == abs(r - ithqueen)))
						putQueen(ithqueen + 1);
			for (int k = 0; k < 8; k++)
				for (int r = 0; r < 8; r++)
					if (board[k][r] == ithqueen)
						board[k][r] = -1;
		}
}

int main()
{
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			board[i][j] = -1;
	putQueen(0);
	cout << count << endl;

	return 0;
}