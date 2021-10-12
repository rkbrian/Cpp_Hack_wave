#ifndef WAVES_H
#define WAVES_H

#define PIE 3.14159

#include <math.h>
#include <iostream> // input stream and buffer
#include <vector> // list or array, size is dynamic
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <limits>

namespace reg_note
{
        short SineWave(double freq, double time, double amplt)
        {
                short note;
                double tpc = 44100 / freq; // ticks per cycle
                double cycl = time / tpc; // cycle
                double radian = 2 * PIE * cycl;
                short amplitude = SHRT_MAX * amplt;
                ret = amplitude * sin(radian);
                return ret;
        };
}

#endif //WAVES_H
