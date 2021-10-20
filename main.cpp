#include "waves.h"

using namespace std;
/*
	wavegraph: setup for default values when inputs are incomplete
*/
wavesGraph::waveGraph(string title = "", int width, int height)
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
	int xSize = xHolder.size, margins, buffalo;
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
		graphBoard[i].resize(pheight);
		for (j = 0; j < pheight; j++)
			graphBoard[i][j] = ' ';
	}
	for (curveArea = 0; curveArea < pcurves; curveArea++) // max & min y values adjusting
	{
		localmax = maxv(yHolder[curveArea]);
		if (localmax > maxY)
			maxY = localmax;
		localmin = minv(yHolder[curveArea]);
		if (localmin < minY)
			minY = localmin;
	}
	for (curveArea = 0; curveArea < pcurves; curveArea++) // graphing
	{
		newWaveData = newWave(yHolder[curveArea], pwidth);
		for (i = 0; i < pwidth; i++) // reuse the board iterations
		{
			j = (int)diffeq(newWaveData[i], minX, 0.0, maxY, (double)pheight);
			graphBoard[i][min(max(0, j), pheight - 1)] = lineType[curveArea];
		}
	}
	cout << endl; // print the graph title in center
	for (i = 0; i < borderL.length() - 1 + (pwidth - graphTitle.length()) / 2; i++)
		cout << " ";
	cout << graphTitle << endl << endl;
	printf(" %5.3g #", maxY); // print graphs
	for (i = 0; i < pwidth; i++)
		cout << "=";
	cout << "#" << endl;
	for (j = pheight - 1; j >= 0; j--) // print from the highest value to the lowest
	{
		if (j == pheight / 2)
		{
			margins = borderL.length() - yAxis.length();
			if (margins >= 0)
			{
				for (i = 0; i < margins - 1; i++)
					cout << " ";
				cout << yAxis;
				for (i = margins - 2; i < borderL.length(); i++)
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
	printf(" %5.3g #", minY);
	for (i = 0; i < pwidth; i++)
		cout << "=";
	cout << "#" << endl;
	printf("%-5.3g", minX); // x ranges and x-axis label
	buffalo = (pwidth - xAxis.length()) / 2 - 6; // range buffer
	for (i = 0; i < buffalo; i++)
		cout << " ";
	cout << xAxis;
	for (i = 0; i < buffalo - 1; i++)
		cout << " ";
	printf("%5.3g\n\n", maxX);
	if (lege) // legend below the graph
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
	xaxis: x axis label
*/
void xaxis(string axis)
{
	xAxis = axis;
}

/*
	yaxis: y axis label
*/
void yaxis(string axis)
{
	yAxis = axis;
}

/*
	legendary: boolean to decide the needs to print legends
*/
void legendary()
{
	lege = true;
}

int main()
{
	int exitCmd = 0, mywidth = 120, myheight = 20;
	int i, aaa = 10, bbb = 1;
	double dx;
	char inputs[64], linety[4] = "X*.";
	bool firstin = false;
	string mytitle, buffalowing, tokbuff;
	vector<string> tokens;
	vector<double> datax(101), curvea(101), curveb(101), curvec(101);

	cout << "Choose the number of your graph type:\n1 Three-Phase Current Graph" << endl;
	cout << "2 TBA" << endl;
	cout << "3 TBA" << endl;
	cin >> inputs;
	while (strcmp(inputs, "1") != 0)
	{
		cout << "Sorry we don't have this option" << endl;
		cin >> inputs;
		mytitle = "Three-Phase Current Graph";
	}
	cout << "This option will print three curves. Formula: y = A * sin(B * x)" << endl;
	cout << "Type your parameters in order: A, B" << endl;
	cin >> buffalowing;
	stringstream tokenarr(buffalowing);
	while (getline(tokenarr, tokbuff, ' '))
		tokens.push_back(tokbuff);
	aaa = stoi(tokens[0], nullptr, 0);
	bbb = stoi(tokens[1], nullptr, 0);
	wavesGraph waverunner(mytitle, mywidth, myheight); 
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
	waverunner.xaxis("time (sec)");
	waverunner.yaxis("I (A)");
	waverunner.printwave();
	return 0;
}
