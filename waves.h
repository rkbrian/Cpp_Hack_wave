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

class wavesGraph // class method to store all parameters 
{
	private: // private parameters
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
    public: // public variables and functions
        void waGraph(string title, int width, int height);
        void addGiraffe(vector<double> xarr, vector<double> yarr, string myaxisName, char mylineType);
        void printwave();
        void xaxias(string axis);
        void yaxias(string axis);
        void legendary();
};

vector<double> newWave(vector<double> yarr, int newLen);
int maxi(int a, int b); // max value of 2 integers
int mini(int a, int b); // min value of 2 integers
double max(double a, double b); // max value of 2 doubles
double min(double a, double b); // min value of 2 doubles
double maxv(vector<double> arr); // max value in an array (vector)
double minv(vector<double> arr);// min value in an array (vector)
double diffeq(double x, double dxmin, double dymin, double dxmax, double dymax);

/* wave functions! */
void threewaves(wavesGraph waverunner, int aa, int bb);
void basewaves(wavesGraph waverunner, int aa, int bb);
void interferwave(wavesGraph waverunner, int aa, int bb, int cc, int dd);
void asciiArtTitle();

#endif // WAVES_H
