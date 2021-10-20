#include "waves.h"

using namespace std;
/* all the helper functions here */
int max(int a, int b) // max and min values of integers and floats
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

int maxv(vector<int> arr) // max and min values in an array (vector)
{
	int i = 1, localMax = arr[0];

	while (i < sizeof(arr))
	{
		if (arr[i] > localMax)
			localMax = arr[i];
		i++;
	}
}

int mixv(vector<int> arr)
{
	int i = 1, localMin = arr[0];

	while (i < sizeof(arr))
	{
		if (arr[i] < localMin)
			localMin = arr[i];
		i++;
	}
}

double diffeq(double x, double dxmin, double dymin, double dxmax, double dymax) // differential calculation
{
	double dx = dxmax - dxmin, dy = dymax - dymin;

	return (x - dxmin) * dy / dx + dymin;
}

vector<double> newWave(vector<double> yarr, int newLen) // function to setup new curves
{
	int oldLen = yarr.size(), oldi, newi = 0;
	vector<double> newArr(newLen);
	double xconverter = 1.0; // graph scale converter on x axis
	double x, y, dxa, dya, dxb, dyb;

	if (newLen == oldLen)
		return yarr;
	else
	{
		xconverter = (double)oldLen / (double)newLen;
		while (newi < newLen)
		{
			x = (double)newi * xconverter;
			dxa = floor(x); // the largest possible integer value which is less than or equal to original value
			dxb = dxa + 1.0;
			dya = yarr[min(max(0, (int)dxa), oldLen - 1)];
			dyb = yarr[min(max(0, (int)dxb), oldLen - 1)];
			y = diffeq(x, dxa, dya, dxb, dyb);
			newArr[min(max(0, newi), newLen - 1)] = y;
			newi++;
		}
		newArr[0] = yarr[0], newArr[newLen - 1] = yarr[oldLen - 1]; // first and last fixed values
	}
	return newArr;
}
