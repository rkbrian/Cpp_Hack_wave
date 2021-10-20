#ifndef WAVES_H
#define WAVES_H

#define MYPI 3.1416
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
#include <sstream>
#include <bits/stdc++.h>

using namespace std;

class wavesGraph
{
	private:
		static const char noGraph[10];
        int pwidth;
        int pheight;
        int pcurves;
        int _lego = 0;
        string graphTitle;
        string xAxe;
        string yAxe;
        vector<double> xHolder; // data holder for precise x values
        vector<double> yHolder[AMPLITUDE]; // data holder for precise y values
        string axisName[AMPLITUDE];
        char lineType[AMPLITUDE];
    public:
        void waGraph(string title, int width, int height);
        // void giraffe(const char *graphfile, const char *arrfile);
        void addGiraffe(vector<double> xarr, vector<double> yarr, string myaxisName, char mylineType);
        void printwave();
        void xaxias(string axis);
        void yaxias(string axis);
        void legendary();
};

vector<double> newWave(vector<double> yarr, int newLen);

int maxi(int a, int b);
int mini(int a, int b);
double max(double a, double b);
double min(double a, double b);
double maxv(vector<double> arr);
double minv(vector<double> arr);
double diffeq(double x, double dxmin, double dymin, double dxmax, double dymax);

#endif // WAVES_H
