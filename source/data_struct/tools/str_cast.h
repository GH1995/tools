int str_cast(char *s, char *d/\r/\r/g
{
	int sign;

	if (*s == '-')
	{
		sign = -1;
		s++;
	}
	else
		sign = 1;

	for (; *s != '\0'; s++)
	{
		if (*s == ',')
			s++;
		*(d++) = *s;
	}
	*s = '\0';
	*d = '\0';

	return sign;
}
