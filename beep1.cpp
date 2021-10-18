#include "waves.h"
#include <iostream>
#include <vector>
#include <iomanip>

using std::cout; using std::vector;
using std::endl; using std::setw;

int main()
{
    cout << "    O__." << endl;
    cout << ",__/_,--+`7" << endl;
    cout << "/___/____/" << endl;

        std::cout << "__/C__/C__/C__/C" << std::flush;
        for (;;) {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            //sleep(1);
            std::cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b_/C__/C__/C__/C_" << std::flush;
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            //sleep(1);
            std::cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b/C__/C__/C__/C__" << std::flush;
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            //sleep(1);
            std::cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\bC__/C__/C__/C__/" << std::flush;
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            //sleep(1);
            std::cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b__/C__/C__/C__/C" << std::flush;
            //sleep(0.5);
            //std::cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b_/C__/C__/C__/C_" << std::flush;
        }
    return 0;
}
