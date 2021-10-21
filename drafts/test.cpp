#include <math.h>
#include <iostream> // input stream and buffer
#include <vector>   // list or array, size is dynamic
#include <atomic>   // data races preventing
#include <climits>
#include <stdio.h>
#include <string>
#include <string.h>
#include <sstream>

using namespace std;

int main()
{
        int exitCmd = 0, aaa, bbb;
	char firstthing[40], inputs[40];
	// string ininputs(inputs);

	cin >> firstthing;
	cout << "Graph type:" << endl;
        cout << "Type your parameters in order: " << endl;
	cin.getline(inputs, 40);
	string ininputs(inputs);
	cout << "let me see: " << ininputs << endl;
	stringstream ss(ininputs);
	ss >> aaa >> bbb;
	aaa = aaa * 10, bbb = bbb + 36;
	cout << aaa << endl;
	cout << bbb << endl;
	return 0;
}