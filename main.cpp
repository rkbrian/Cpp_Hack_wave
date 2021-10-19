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
			y = map(x, dxa, dya, dxb, dyb);
			newArr[min(max(0, newi), newLen - 1)] = y;
			newi++;
		}
		newArr[0] = yarr[0], newArr[newLen - 1] = yarr[oldLen - 1]; // first and last fixed values
	}
	return newArr;
}

void sineWaves::addGiraffe(vector<double> xarr, vector<double> yarr, string myaxisName = "", char mylineType = ' ')
{
	xHolder = xarr;
	axisName[pcurves] = myaxisName;
	lineType[pcurves] = mylineType;
	yHolder[pcurves++] = yarr;
}

void sineWaves::printwave()
{
	int xSize = xHolder.size, margins;
	int i, j, curveArea; // iterations
	double minX = xHolder[0], maxX = xHolder[xSize - 1];
	double minY = 1.0e15, maxY = 1.0e-15; // starting values to be adjusted later
	double localmax, localmin;
	vector<double> newWaveData;
	vector<vector<char>> graphBoard;
	string borderL = "        ";

	graphBoard.resize(pwidth); // make a blank whiteboard
	for (i = 0; i < pwidth; i++)
	{
		graphBorad[i].resize(pheight);
		for (j = 0; j < pheight; j++)
			graphBoard[i][j] = ' ';
	}
	for (curveArea = 0; curveArea < pcurves; curveArea++) // max & min y values adjusting
	{
		localmax = max(yHolder[curveArea]);
		if (localmax > maxY)
			maxY = localmax;
		localmin = min(yHolder[curveArea]);
		if (localmin < minY)
			minY = localmin;
	}
	for (curveArea = 0; curveArea < pcurves; curveArea++) // graphing
	{
		newWaveData = newWave(yHolder[curveArea], pwidth);
		for (i = 0; i < pwidth; i++) // reuse the board iterations
		{
			j = (int)map(newWaveData[i], minX, 0.0, maxY, (double)pheight);
			graphBorad[i][min(max(0, j), pheight - 1)] = lineType[curveArea];
		}
	}
	cout << endl; // print the graph title in center
	for (i = 0; i < borderL.length() - 1 + (pwidth - graphTitle.length()) / 2; i++)
		cout << " ";
	cout << graphTitle << endl << endl;
	// next coming up: graph the curve!!!!!
}

int main()
{
	int exitCmd = 0;
	char inputs[20];
	bool firstin = false;

	cout << "Choose your graph type:" << endl;
	cin >> inputs;
	while (strcmp(inputs, "sine") != 0)
	{
		cout << "Sorry we don't have this option" << endl;
		cin >> inputs;
	}
	cout << "Type your parameters in order: " << endl;
	cin.getline(inputs, 20);
	cout << "let me see: " << inputs << endl;
	return 0;
}
