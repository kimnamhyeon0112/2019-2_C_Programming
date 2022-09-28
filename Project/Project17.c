#include<stdio.h>
#include<math.h>

double findavg(int[], int);
double stdDev(int[], int, double);

int main()
{
#define NUMELS 10
	int values[NUMELS] = { 98,82,67,54,78,83,95,76,68,63 };
	double average, stddev;

	average = findavg(values, NUMELS);
	stddev = stdDev(values, NUMELS, average);

	printf("The average of the numbers is %5.2f\n", average);
	printf("The standard deviation of the numbers is %5.2f\n", stddev);

	return 0;
}

double findAvg(int nums[], int numel)
{
	int i;
	double sumnums = 0.0;

	for (i = 0; i < numel; i++)
		sumnums = sumnums + nums[i];

	return (sumnums / numel);
}

double stdDev(int nums[], int numel, double av)
{
	int i;
	double sumdevs = 0.0;

	for (i = 0; i < numel; i++)
		sumdevs = sumdevs + pow((nums[i] - av), 2);

	return(sqrt(sumdevs / numel));
}