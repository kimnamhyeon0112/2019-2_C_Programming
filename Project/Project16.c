#include<stdio.h>
#define MAXELS 5

void findmax(int[MAXELS]);

int main()
{
	int nums[MAXELS] = { 2,18,1,27,16 };
	findmax(nums);
	return 0;
}

void findmax(int vals[MAXELS])
{
	int i, max = vals[0];
	for (i = 0; i < MAXELS; i++)
		if (max < vals[i])
			max = vals[i];

	printf("The maximum value is %d\n", max);
}