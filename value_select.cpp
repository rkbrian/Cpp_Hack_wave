#include "waves.h"

int max(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}

int min(int a, int b)
{
	if (a > b)
		return b;
	else
		return a;
}

double max(double a, double b)
{
	if (a > b)
		return a;
	else
		return b;
}

double min(double a, double b)
{
	if (a > b)
		return b;
	else
		return a;
}

int max(vector<int> arr)
{
	int i = 1, localMax = arr[0];

	while (i < sizeof(arr))
	{
		if (data[i] > localMax)
			localMax = arr[i];
		i++;
	}
}

int mix(vector<int> arr)
{
	int i = 1, localMin = arr[0];

	while (i < sizeof(arr))
	{
		if (data[i] < localMin)
			localMin = arr[i];
		i++;
	}
}

double diffeq(double x, double dxmin, double dymin, double dxmax, double dymax)
{
	double dx = dxmax - dxmin, dy = dymax - dymin;

	return (x - dxmin) * dy / dx + dymin;
}
