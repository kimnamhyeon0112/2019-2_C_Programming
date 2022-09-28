#include <stdio.h>

int main()
{
	int i, j, n, k;
	scanf("%d", &n);

	for (i = 2; i <= 9; i += n)
	{
		for (k = 1; k <= 9; k++)
		{
			for (j = 0; j < n; j++)
			{
				if (i + j > 9) break;
				printf("%d x %d = %2d ", i + j, k, (i + j)*k);
			}
			printf("\n");
		}
		printf("\n");
	}
}