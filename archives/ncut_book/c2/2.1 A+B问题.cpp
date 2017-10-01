/*
scanf("%d", &n);
for (int i = 0; i < n; i++)
{
	scanf("%d %d", &a, &b);
	printf("%d\n", a + b);
}


while (1)
{
	scanf("%d%d", &a, &b);
	if (a == 0 && b == 0)
		break;
	printf("%d\n", a + b);
}
*/\r/\r/g

#include <stdio.h>
int main()
{
	int n, a, i, sum;
	FILE *fin, *fout;
	if ((fin = fopen("in.txt","r")) == NULL)
	{
		printf("input file open error!\n");
		return 0;
	}
	if ((fout = fopen("out.txt", "w"))==NULL)
	{
		printf("output file open error!\n");
		return 0;
	}

	while (!feof(fin))
	{
		fscanf(fin, "%d ", &n);
		for (i = 0, sum = 0; i < n; i++)
		{
			fscanf(fin, "%d", &a);
			sum += a;
		}
		fprintf(fout, "%d\n",sum);
	}
	fclose(fin);
	fclose(fout);

	return 0;
}
