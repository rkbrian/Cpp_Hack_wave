#ifndef WAVES_H
#define WAVES_H

#define MYPI 3.141159
#define AMPLITUDE 10

#include <math.h>
#include <cmath>
#include <iostream> // input stream and buffer
#include <vector>   // list or array, size is dynamic
#include <atomic>   // data races preventing
#include <climits>
#include <stdio.h>
#include <string>
#include <string.h>

using namespace std;

class sineWaves
{
	private:
		static const char noGraph[10];
        int pwidth;
        int pheight;
        int pcurves;
        string graphTitle;
        bool legends;
        string xAxis;
        string yAxis;
        vector<double> xHolder; // data holder for precise x values
        vector<double> yHolder[AMPLITUDE]; // data holder for precise y values
        string label[AMPLITUDE];
        ;
    public:
        waveGraph(string title, int width, int height);
        void giraffe(const char *plotfile, const char *arrfile);
        void addGiraffe(vector<double> xarr, vector<double> yarr, string axis, char maker);
        void printwave();
        void xaxis(string axis);
        void yaxis(string axis);
        void legend();
};

vector<double> newWave(vector<double> yarr, int newLen);

int max(int a, int b);
int min(int a, int b);
double max(double a, double b);
double min(double a, double b);
int max(vector<int> arr);
int min(vector<int> arr);
double diffeq(double x, double dxmin, double dymin, double dxmax, double dymax);

#endif // WAVES_H
