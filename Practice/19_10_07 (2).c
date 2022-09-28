#include <stdio.h>
int main()
{
	int i = 0, j, num;
	scanf("%d", &num);
	for (i = 0; i <= num; i++)
	{
		for (j = 2; j < num -i- j; j++)
		{
			printf(" ");
		}
		for (j = 0; j <= i; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
