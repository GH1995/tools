#include <iostream>
using namespace std;


/*
*	质因数分解函数
*/
void fact(int m);

int main()
{
	while (1)
	{
		int num;
		cin >> num;

		if (num == 0)
			break;

		cout << num << "=";
		fact(num);

		cout << endl;
	}

	return 0;
}



void fact(int m)
{
	int i;
	for (i = 2; i <= m / 2; i++)
	{
		if (m % i == 0)
		{
			cout << i << '*';
			fact(m / i);
			break;
		}
	}

	if (i > m / 2)
		cout << m << endl;
}