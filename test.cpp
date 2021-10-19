#include <math.h>
#include <iostream> // input stream and buffer
#include <vector>   // list or array, size is dynamic
#include <atomic>   // data races preventing
#include <climits>
#include <stdio.h>
#include <string>
#include <string.h>

using namespace std;

int main()
{
        int exitCmd = 0;
	char inputs[20];
        bool firstin = false;

	cout << "Graph type:" << endl;
	cin >> inputs;
	while (strcmp(inputs, "sine") != 0)
        {
		cout << "Sorry we don't have this option" << endl;
		cin.getline(inputs, 20);
        }
        cout << "Type your parameters in order: " << endl;
	cin.getline(inputs, 20);
	cout << "let me see: " << inputs << endl;
	return 0;
}