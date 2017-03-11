/*
样例输入：
3
10 110
2
1 1
30 50
10 110
2
1 1
50 30
1 6
2
10 3
20 4
样例输出：
The minimum amount of money in the piggy-bank is 60.
The minimum amount of money in the piggy-bank is 100.
This is impossible.
*/\r/\r/g
#define INF 99999
#include <iostream>
#include <algorithm>
using namespace std;

struct MyStruct
{
	int w;
	int v;
};

int main()
{

	int t;
	cin >> t;
	while (t--)
	{
		int dp[10001];
		MyStruct list[501];

		int tmp;
		int s;
		cin >> tmp >> s;
		s -= tmp;

		int n;
		cin >> n;

		for (int i = 1; i <= n; i++)
			cin >> list[i].v >> list[i].w;

		for (int i = 0; i <= s; i++)
			dp[i] = INF;
		dp[0] = 0;

		for (int i = 1; i <= n; i++)
			for (int j = list[i].w; j <= s; j++)
				if (dp[j - list[i].w] != INF)
					dp[j] = min(dp[j], dp[j - list[i].w] + list[i].v);
		if (dp[s] != INF)
			cout << "The minimum amount of money in the piggy-bank is " << dp[s] << '.' << endl;
		else
			cout << "This is impossible." << endl;
	}

	return 0;
}
