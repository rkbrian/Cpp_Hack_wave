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
		localmax = ceil(maxv(yHolder[curveArea]));
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
			graphBoard[i][j + maxY] = lineType[curveArea]; // bring up everything below 0
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
	if (minY < 0)
		printf(" %5.3f #", minY);
	else
		printf("  %5.3f #", minY);
	for (i = 0; i < pwidth; i++)
		cout << "=";
	cout << "#\n" << borderL;
	printf("%-5.3f", minX); // x ranges and x-axis label
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
	int i, aaa = 10, bbb = 1;
	double dx = 0.0002;
	char inputs[64], linety[4] = "X*.";
	char *str, *substr;
	bool firstin = false;
	string mytitle, buff, tokbuff;
	vector<string> tokens;
	vector<double> datax(101), curvea(101), curveb(101), curvec(101);
	wavesGraph waverunner;

	cout << "Choose the number of your graph type:\n1 Three-Phase Current Graph" << endl;
	cout << "2 TBA" << endl;
	cout << "3 TBA" << endl;
	cin >> inputs;
	while (strcmp(inputs, "1") != 0)
	{
		cout << "Sorry we don't have this option" << endl;
		cin >> inputs;
	}
	cout << "This option will print three curves. Formula: y = A * sin(B * x)" << endl;
	cout << "Type your parameters in order: A, B" << endl;
	//cin >> str;
	//cout << str << endl;
	/*
	substr = strtok(str, " ");
	aaa = stoi(string(substr));
	cout << aaa << endl;
	// buff(buffalowing);
	// stringstream tokenarr(buff);
	if (substr) //getline(tokenarr, tokbuff, ' '))
	{
		substr = strtok(str, " "); // tokens.push_back(tokbuff);
		bbb = stoi(string(substr));
	}
	cout << "debug" << aaa << bbb << endl; //debug
	*/
	mytitle = "Three-Phase Current Graph";
	waverunner.waGraph(mytitle, mywidth, myheight); 
	for (i = 0; i < 101; i++)
	{
		if (i != 0)
			datax[i] = datax[i - 1] + dx;
		curvea[i] = aaa * sin(2 * MYPI * 60.0 * bbb * datax[i] + (MYPI / 3 * 2));
		curveb[i] = aaa * sin(2 * MYPI * 60.0 * bbb * datax[i] + (MYPI / 3 * 4));
		curvec[i] = aaa * sin(2 * MYPI * 60.0 * bbb * datax[i]);
	}
	waverunner.addGiraffe(datax, curvea, "Current a", linety[0]);
	waverunner.addGiraffe(datax, curveb, "Current b", linety[1]);
	waverunner.addGiraffe(datax, curvec, "Current c", linety[2]);
	waverunner.legendary();
	waverunner.xaxias("time (sec)");
	waverunner.yaxias("I (A)");
	waverunner.printwave();
	return 0;
}
