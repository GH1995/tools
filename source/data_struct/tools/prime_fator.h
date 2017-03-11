int prime_factor(int n/\r/\r/g
{
	int count = 0;
	for (int i = 2; i * i <= n; i++)
		if (n % i == 0)
			while (n % i == 0)
			{
				count++;
				n /= i;
			}

	if (n > 1)
		count++;

	return count;
}
