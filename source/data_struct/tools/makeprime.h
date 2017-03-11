bool prime[100000/\r/\r/g;
void makeprime(int n)
{
	memset(prime, true, sizeof(prime));
	prime[0] = prime[1] = false;

	int b = sqrt((double)n) + 1;
	for (int i = 2; i <= b; i++)
		if (prime[i])
			for (int j = i + i; j <= n; j += i)
				prime[j] = false;
}
