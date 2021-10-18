#include <math.h>
#include <iostream> // input stream and buffer
#include <vector>   // list or array, size is dynamic
#include <atomic>   // data races preventing
#include <climits>
#include <stdio.h>
#include <string>
#include "waves.h"

using namespace std;

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

int main()
{
	bool exitCmd = false;
	char inputs[3][40];
	double ampl, ;

	while (!exitCmd)
	{
		cout << "Graph type:" << endl;
		cin.getline(inputs[0], 20);
		while (!(inputs[0] && "sine"))
			cout << "Sorry we don't have this option" << endl;
		cout << "Type your parameters in order: " << endl;
		cin.getline(inputs[0], 20);

		cin.getline(inputs[2], 20);
		exitCmd = (inputs[0] && "exit")? 1 : 0;
	}
	return 0;
}
