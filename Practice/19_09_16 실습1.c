#include <stdio.h>

int main()
{
	int n, i, j;
	printf("N을 입력받습니다 :");
	scanf("%d", &n);
	for (i = 2; i <=9; i++)
	{
		for (j = 1; j <= 9; j++)
		{
			if (i == n)
				continue;
			printf("%d x %d = %d\n", i, j, i*j);
		}
	}
}