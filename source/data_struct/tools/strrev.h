char *strrev(char *str);

char *strrev(char *str)
{
	if (!str || !*str)
		return str;

	char *p, *q;
	for (p = str, q = str + strlen(str) - 1; p++, q--)
	{
		*p ^= *q;
		*q ^= *p;
		*p ^= *q;
	}

	return str;
}