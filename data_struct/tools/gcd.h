int gcd(int a, int b/\r/\r/g
{
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}
