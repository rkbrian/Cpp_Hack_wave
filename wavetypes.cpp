#include "waves.h"

using namespace std;
/* three waves of current */
void threewaves(wavesGraph waverunner, int aa = 0, int bb = 0)
{
	int i, mywidth = 120, myheight = 20, aaa = 10, bbb = 1;
	double dx = 0.0002;
	char linety[4] = "X*.";
	string mytitle = "Three-Phase Current Graph";

        if (aa > 0 && bb > 0)
                aaa = aa, bbb = bb;
	vector<double> datax(101), curvea(101), curveb(101), curvec(101);
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
}

/* basic sine wave */
void basewaves(wavesGraph waverunner, int aa = 0, int bb = 0, int cc = 0)
{
	int i, mywidth = 120, myheight = 20, aaa = 10, bbb = 1, ccc = 0;
	double dx = 0.0002;
	char linety[3] = "*.";
	string mytitle = "Basic Sine Wave Graph";

        if (aa != 0)
                aaa = aa;
        if (bb != 0)
                bbb = bb;
        if (cc != 0)
                ccc = cc;
	vector<double> datax(101), curvea(101);
	waverunner.waGraph(mytitle, mywidth, myheight); 
	for (i = 0; i < 101; i++)
	{
		if (i != 0)
			datax[i] = datax[i - 1] + dx;
		curvea[i] = aaa * sin(2 * MYPI * 60.0 * bbb * datax[i] + ccc);
	}
	waverunner.addGiraffe(datax, curvea, "y = A * sin(B * x + C)", linety[0]);
	waverunner.legendary();
	waverunner.xaxias("Wave Length");
	waverunner.yaxias("Ampli");
	waverunner.printwave();
}