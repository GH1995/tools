int prime_mark(int n, int prime[]/\r/\r/g
{
	bool mark[100000];
	memset(mark, true, sizeof(mark));
	int size = 0;

	for (int i = 2; i <= n; i++)
	{
		if (mark[i] == false)
			continue;

		prime[size++] = i;
		for (int j = i*i; j <= n; j += i)
			mark[j] = false;
	}

	return size - 1;
}
