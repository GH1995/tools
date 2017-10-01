#include <iostream>
using namespace std;

int commpath(int x, int y);

int main()
{
	int a, b;
	cin >> a >> b;

	int c = commpath(a, b);
	cout << c << endl;

	return 0;
}

int commpath(int x, int y)
{
	if (x == y)
		return x;

	if (x > y)
		return commpath(x / 2, y);
	else
		return commpath(x, y / 2);
}