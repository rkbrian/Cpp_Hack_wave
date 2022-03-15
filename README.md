# Hack Week in C++
Design and develop a C++ application for the theme: Waves. 10-day project (from 10-11-2021 to 10-21-2021) for Holberton School.

## Project Developer
**[Brian Kong](https://github.com/rkbrian)** - software engineer, learning to code at Holberton School since Jan, 2021, specialization and passion in Low Level & Algorithms.\
LinkedIn: https://www.linkedin.com/in/ran-kong/ \
Email: rkbriankong@gmail.com

## Design Purpose:
This application is an analytical tool for the study of sine wave graphs in trigonometry and physics. It takes inputs as the function parameters and print the graph in ascii art according to them. There are 3 graph options available.

## Workable Environment:
 - WSL

<div align="center"><img src="https://github.com/rkbrian/Cpp_Hack_wave/blob/main/Cpp_001.jpg" width="500"></div>

## Commands
Compile: **make all** - create the appliaction "sinewave".\
Usage: **./sinewave** - open the application, will be closed after the graph is printed.

## Graph Options
1. Basic Sine Wave - print 1 graph, user provides the wave amplitude (parameter A) and the frequency (parameter B).<br>
<div align="center"><img src="https://github.com/rkbrian/Cpp_Hack_wave/blob/main/Cpp_002.jpg" width="700"></div><br>

2. Wave interference - print 3 graphs, the 1st one and the 2nd one are the waves defined by user, the 3rd one is the interfered result of the prior two, user provides the wave amplitude (parameter A & C) and the frequency (parameter B & D).<br>
<div align="center"><img src="https://github.com/rkbrian/Cpp_Hack_wave/blob/main/Cpp_003.jpg" width="700"><br><br>
<img src="https://github.com/rkbrian/Cpp_Hack_wave/blob/main/Cpp_003_2.jpg" width="700"></div><br>

3. Three-Phase Current - print the three-phase electric current graphs, only one set of parameters is needed, user provides the wave amplitude (parameter A) and the frequency (parameter B).<br>
<div align="center"><img src="https://github.com/rkbrian/Cpp_Hack_wave/blob/main/Cpp_004.jpg" width="700"></div><br>

## Flowchart:
<div align="center"><img src="https://github.com/rkbrian/Cpp_Hack_wave/blob/main/Flowchart_SineWaves.jpg" height="800"></div>

## Features and Design Changes
This application is printing graphs in ascii art. In the beginning, I planned to show the graphs with more visually refined effects. I changed my plan due to the unsolved issues of the C++ editor and the running environment setup. The final product meets my goal: to design an analytical tool by using finite element calculation to show graphs.\
The most difficult issue in this project was the setup of environment, due to the nature of the powerful but restricted C++ language.

## More info:
 - [Wikipedia: Sine Waves](https://en.wikipedia.org/wiki/Sine_wave)
 - [Interference of Waves](https://www.physicsclassroom.com/class/waves/Lesson-3/Interference-of-Waves)
 - [Three-Phase Electric Power](https://en.wikipedia.org/wiki/Mathematics_of_three-phase_electric_power)
