#include "waves.h"

using namespace std;
/* Functions to make curve data of the waves*/
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
void basewaves(wavesGraph waverunner, int aa = 0, int bb = 0)
{
	int i, mywidth = 120, myheight = 20, aaa = 10, bbb = 1;
	double dx = 0.0002;
	char linety[3] = "*.";
	string mytitle = "Basic Sine Wave Graph";

        if (aa != 0)
                aaa = aa;
        if (bb != 0)
                bbb = bb;
	/* if (cc != 0)
		ccc = cc;*/
	vector<double> datax(101), curvea(101);
	waverunner.waGraph(mytitle, mywidth, myheight); 
	for (i = 0; i < 101; i++)
	{
		if (i != 0)
			datax[i] = datax[i - 1] + dx;
		curvea[i] = aaa * (sin(2 * MYPI * 60.0 * bbb * datax[i]));
	}
	waverunner.addGiraffe(datax, curvea, "y = A * sin(B * x)", linety[0]);
	waverunner.legendary();
	waverunner.xaxias("Wave Length");
	waverunner.yaxias("Ampli");
	waverunner.printwave();
}

/* wave interference */
void interferwave(wavesGraph waverunner, int aa = 0, int bb = 0, int cc = 0, int dd = 0)
{
	int i, mywidth = 120, myheight = 20, aaa = 10, bbb = 1, ccc = 7, ddd = 1;
	double dx = 0.0002;
	char linety[4] = "X*.";
	string mytitle = "Three-Phase Current Graph";

        if (aa != 0)
                aaa = aa;
        if (bb != 0)
                bbb = bb;
        if (cc != 0)
                ccc = cc;
        if (dd != 0)
                ddd = dd;
	vector<double> datax(101), curvea(101), curveb(101), curvec(101);
	waverunner.waGraph(mytitle, mywidth, myheight); 
	for (i = 0; i < 101; i++)
	{
		if (i != 0)
			datax[i] = datax[i - 1] + dx;
		curvea[i] = aaa * sin(2 * MYPI * 60.0 * bbb * datax[i]);
		curveb[i] = ccc * sin(2 * MYPI * 60.0 * ddd * datax[i]);
		curvec[i] = (aaa * sin(2 * MYPI * 60.0 * bbb * datax[i])) + (ccc * sin(2 * MYPI * 60.0 * ddd * datax[i]));
	}
	waverunner.addGiraffe(datax, curvea, "Function Y1", linety[0]);
	waverunner.addGiraffe(datax, curveb, "Function Y2", linety[1]);
	waverunner.addGiraffe(datax, curvec, "Interferred Wave", linety[2]);
	waverunner.legendary();
	waverunner.xaxias("Wave Length");
	waverunner.yaxias("Ampli");
	waverunner.printwave();
}

/* title art */
void asciiArtTitle()
{
	cout << "   _____ _             __          __" << endl;
        cout << "  / ____(_)            \\ \\        / /" << endl;
        cout << " | (___  _ _ __   ___   \\ \\  /\\  / /_ ___   _____  ___" << endl;
        cout << "  \\___ \\| | '_ \\ / _ \\   \\ \\/  \\/ / _` \\ \\ / / _ \\/ __|" << endl;
        cout << "  ____) | | | | |  __/    \\  /\\  / (_| |\\ V /  __/\\__ \\" << endl;
        cout << " |_____/|_|_| |_|\\___|     \\/  \\/ \\__,_| \\_/ \\___||___/\n" << endl;
}
