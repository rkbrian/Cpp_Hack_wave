#include <math.h>
#include <iostream> // input stream and buffer
#include <vector>   // list or array, size is dynamic
#include <atomic>   // data races preventing
#include <climits>
#include <stdio.h>
#include <string>
#include "waves.h"

using namespace std;
 /*
	wavegraph: setup for default values when inputs are incomplete
 */
sineWaves::waveGraph(string title, int width, int height)
{
	if (!title)
		graphTitle = "";
	else
		graphTitle = title;
	if (!width)
		pwidth = 100;
	else
		pwidth = width;
	if (!height)
		pheight = 50;
	else
		pheight = height;
	pcurves = 0;
}

vector<double> newWave(vector<double> yarr, int newLen)
{
	int oldLen = yarr.size(), oldi, newi = 0;
	vector<double> newArr(newLen);
	double xconverter = 1.0; // graph scale converter on x axis
	double x, y, dxa, dya, dxb, dyb;

	if (newLen = oldLen)
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
			y = map(x, dxa, dya, dxb, dyb);
			newArr[min(max(0, newi), newLen - 1)] = y;
			newi++;
		}
		newArr[0] = yarr[0];
		newArr[newLen - 1] = yarr[oldLen - 1]; // first and last fixed values
	}
	return newArr;
}

int main()
{
	int exitCmd = 0;
	char inputs[20];
	bool firstin = false;

	cout << "Graph type:" << endl;
	cin >> inputs;
	while (strcmp(inputs, "sine") != 0)
	{
		cout << "Sorry we don't have this option" << endl;
		cin.getline(inputs, 20);
	}
	cout << "Type your parameters in order: " << endl;
	cin.getline(inputs, 20);
	cout << "let me see: " << inputs << endl;
	return 0;
}
