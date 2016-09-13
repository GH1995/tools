#include <iostream>
using namespace std;

int main()
{
	int a, f;
	cin >> a;

	for (int b = 1; b <= 6; b++)
	{
		if (b == a)
			continue;
		for (int c = 1; c <= 6; c++)
		{
			if (c == a || c == b)
				continue;
			for (int d = 1; d <= 6; d++)
			{
				if (d == a || d == b || d == c)
					continue;
				for (int e = 1; e <= 6; e++)
				{
					if (e == a || e == b || e == c || e == d)
						continue;

					f = 21 - (a + b + c + d + e);
					if ((a + b + c == c + d + e) && (a + b + c == e + f + a))
					{
						cout << "  " << a << "  " << endl;
						cout << " " << b << " " << f << " " << endl;
						cout << c << " " << d << " " << e << endl;
						cout << endl;
					}
				}
			}
		}
	}

	return 0;
}