#include <iostream>
using namespace std;

int p[15][15];

void fill(int pos, int size, int sum)
{
	if (size == 0)
		return;

	if (size == 1)
	{
		p[pos][pos] = num;
		return;
	}

	int n = num;

	for (int i = pos; i < pos + size; i++)
		p[i][pos] = n++;

	for (int i = pos + 1; i < pos + size; i++)
		p[pos + size - 1][i] = n++;

	for (int i = pos + size - 2; i >= pos; i--)
		p[i][pos + size - 1] = n++;

	for (int i = pos + size - 2; i > pos; i--)
		p[pos][i] = n++;

	fill(pos + 1, size - 2, num + size * 4 - 4);
}


int main()
{
	int n;
	cin >> n;

	fill(0, n, 1);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << p[i][j];
		cout << endl;
	}

	return 0;
}