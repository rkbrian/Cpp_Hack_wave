#include "waves.h"
#include <math.h>
#include <cmath>
#include <iostream> // input stream and buffer
#include <vector>   // list or array, size is dynamic
#include <atomic>   // data races preventing
#include <climits>
#include <stdio.h>
#include <string>
#include <string.h>
#include <sstream>

using namespace std;
/*
	wagraph: setup for default values when inputs are incomplete
*/
void wavesGraph::waGraph(string title, int width, int height)
{
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

/*
	addGiraffe: setup x and y scale arrays, axis name (label), and curve line type
*/
void wavesGraph::addGiraffe(vector<double> xarr, vector<double> yarr, string myaxisName = "", char mylineType = ' ')
{
	xHolder = xarr;
	axisName[pcurves] = myaxisName;
	lineType[pcurves] = mylineType;
	yHolder[pcurves++] = yarr;
}

/*
	printwave: print everything
*/
void wavesGraph::printwave()
{
	int margins, buffalo;
	int i, j, curveArea; // iterations
	double minX = xHolder[0], maxX = xHolder[xHolder.size() - 1];
	double minY = 1.0e15, maxY = 1.0e-15; // starting values to be adjusted later
	double localmax, localmin;
	vector<double> newWaveData;
	vector<vector<char>> graphBoard;
	string borderL = "         ";

	graphBoard.resize(pwidth); // make a blank whiteboard
	for (i = 0; i < pwidth; i++)
	{
		graphBoard[i].resize(pheight);
		for (j = 0; j < pheight; j++)
			graphBoard[i][j] = ' ';
	}
	for (curveArea = 0; curveArea < pcurves; curveArea++) // max & min y values adjusting
	{
		localmax = ceil(maxv(yHolder[curveArea])) + 1;
		if (localmax > maxY)
			maxY = localmax;
		localmin = floor(minv(yHolder[curveArea])) - 1;
		if (localmin < minY)
			minY = localmin;
	}
	for (curveArea = 0; curveArea < pcurves; curveArea++) // graphing
	{
		newWaveData = newWave(yHolder[curveArea], pwidth);
		for (i = 0; i < pwidth; i++) // reuse the board iterations
		{
			j = newWaveData[i];
			graphBoard[i][(j + maxY) * 10 / maxY] = lineType[curveArea]; // bring up everything below 0
		}
	}
	cout << endl; // print the graph title in center
	for (i = 0; i < borderL.length() - 1 + (pwidth - graphTitle.length()) / 2; i++)
		cout << " ";
	cout << graphTitle << endl << endl;
	if (maxY >= 0) // print graphs
		printf("  %5.3f #", maxY);
	else
		printf(" %5.3f #", maxY);
	for (i = 0; i < pwidth; i++)
		cout << "=";
	cout << "#" << endl;
	for (j = pheight - 1; j >= 0; j--) // print from the highest value to the lowest
	{
		if (j == pheight / 2)
		{
			margins = borderL.length() - yAxe.length();
			if (margins >= 0)
			{
				for (i = 0; i < margins - 1; i++)
					cout << " ";
				cout << yAxe;
				for (i = margins - 2 + yAxe.length(); i < borderL.length() - 1; i++)
					cout << " ";
				cout << "|";
			}
		}
		else
			cout << borderL << "|";
		for (i = 0; i < pwidth; i++)
			cout << graphBoard[i][j];
		cout << "|" << endl;
	}
	printf(" %5.3f #", (-1) * maxY);
	for (i = 0; i < pwidth; i++)
		cout << "=";
	cout << "#\n" << borderL;
	printf("  %-5.3f", minX); // x ranges and x-axis label
	buffalo = (pwidth - xAxe.length()) / 2 - 6; // range buffer
	for (i = 0; i < buffalo; i++)
		cout << " ";
	cout << xAxe;
	for (i = 0; i < buffalo - 1; i++)
		cout << " ";
	printf("%5.3f\n\n", maxX);
	if (_lego == 1) // legend below the graph
	{
		cout << borderL << "+";
		for (i = 0; i < pwidth; i++)
			cout << "-";
		cout << "+" << endl;
		for (curveArea = 0; curveArea < pcurves; curveArea++)
		{
			cout << borderL << "|    " << lineType[curveArea] << " " << axisName[curveArea];
			for (i = 0; i < (pwidth - 6 - axisName[curveArea].length()); i++)
				cout << " ";
			cout << "|" << endl;
		}
		cout << borderL << "+";
		for (i = 0; i < pwidth; i++)
			cout << "-";
		cout << "+" << endl;
	}
}

/*
	xaxias: x axis label
*/
void wavesGraph::xaxias(string axis)
{
	xAxe = axis;
}

/*
	yaxias: y axis label
*/
void wavesGraph::yaxias(string axis)
{
	yAxe = axis;
}

/*
	legendary: boolean to decide the needs to print legends
*/
void wavesGraph::legendary()
{
	_lego = 1;
}

int main()
{
	int exitCmd = 0, mywidth = 120, myheight = 20;
	int i, aaa = 10, bbb = 1, ccc = 7, ddd = 1;
	char inputs[10], inputsSec[20];
	wavesGraph waverunner;

	asciiArtTitle();
	cout << "<<<< Let's print some sine wave graphs! >>>>\n" << endl;
	cout << "Choose the number of your graph type:\n1 Basic Sine Wave" << endl;
	cout << "2 Wave interference" << endl;
	cout << "3 Three-Phase Current" << endl;
	cin >> inputs;
	while (strcmp(inputs, "1") != 0 && strcmp(inputs, "2") != 0 && strcmp(inputs, "3") != 0)
	{
		cout << "Sorry, we don't have this option" << endl;
		cin >> inputs;
	}
	if (strcmp(inputs, "1") == 0) // 1 wave!
	{
		cout << "Formula: y = A * sin(B * x + C)" << endl;
		cout << "Type your integer parameters in order: A, B\nA: ";
		cin >> inputsSec;
		if (inputsSec != "")
		{
			string ininputs(inputsSec);
			stringstream ss(ininputs);
			ss >> aaa;
		}
		cout << "B: ";
		cin >> inputsSec;
		if (inputsSec != "")
		{
			string ininputs(inputsSec);
			stringstream ss(ininputs);
			ss >> bbb;
		}
		basewaves(waverunner, aaa, bbb);
	}
	if (strcmp(inputs, "2") == 0) // 2 waves!
	{
		cout << "Formula 1: y1 = A * sin(B * x)\nFormula 2: y2 = C * sin(D * x)" << endl;
		cout << "Type your integer parameters in order: A, B, C, D\nA: ";
		cin >> inputsSec;
		if (inputsSec != "")
		{
			string ininputs(inputsSec);
			stringstream ss(ininputs);
			ss >> aaa;
		}
		cout << "B: ";
		cin >> inputsSec;
		if (inputsSec != "")
		{
			string ininputs(inputsSec);
			stringstream ss(ininputs);
			ss >> bbb;
		}
		cout << "C: ";
		cin >> inputsSec;
		if (inputsSec != "")
		{
			string ininputs(inputsSec);
			stringstream ss(ininputs);
			ss >> ccc;
		}
		cout << "D: ";
		cin >> inputsSec;
		if (inputsSec != "")
		{
			string ininputs(inputsSec);
			stringstream ss(ininputs);
			ss >> ddd;
		}
		interferwave(waverunner, aaa, bbb, ccc, ddd);
	}
	if (strcmp(inputs, "3") == 0) // 3 waves!
	{
		cout << "This option will print three curves. Formula: y = A * sin(B * x)" << endl;
		cout << "Type your integer parameters in order: A, B\nA: ";
		cin >> inputsSec;
		if (inputsSec != "")
		{
			string ininputs(inputsSec);
			stringstream ss(ininputs);
			ss >> aaa;
		}
		cout << "B: ";
		cin >> inputsSec;
		if (inputsSec != "")
		{
			string ininputs(inputsSec);
			stringstream ss(ininputs);
			ss >> bbb;
		}
		threewaves(waverunner, aaa, bbb);
	}
	return 0;
}
