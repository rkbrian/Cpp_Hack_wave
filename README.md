# Hack Week in C++
Design and develop a C++ application for the theme: Waves

### Design Purpose:
This application is an educational tool for the study of sine wave graphs in trigonometry and physics. It takes inputs as the function parameters and print the graph in ascii art according to them. There are 3 graph options available.

### Workable Environment:
 - WSL

<img src="https://github.com/rkbrian/Cpp_Hack_wave/blob/main/Cpp_001.jpg" align="center" width="600">

### Commands
Compile: **make all** - create the appliaction "sinewave".\
Usage: **./sinewave** - open the application, will be closed after the graph is printed.

### Graph Options
1. Basic Sine Wave - print 1 graph, user provides the wave amplitude (parameter A) and the frequency (parameter B).<br>
<img src="https://github.com/rkbrian/Cpp_Hack_wave/blob/main/Cpp_002.jpg" width="700" align="center">
2. Wave interference - print 3 graphs, the 1st one and the 2nd one are the waves defined by user, the 3rd one is the interfered result of the prior two, user provides the wave amplitude (parameter A & C) and the frequency (parameter B & D).<br>
<img src="https://github.com/rkbrian/Cpp_Hack_wave/blob/main/Cpp_003.jpg" width="700" align="center"><br>
<img src="https://github.com/rkbrian/Cpp_Hack_wave/blob/main/Cpp_003_2.jpg" width="700" align="center">
3. Three-Phase Current - print the three-phase electric current graphs, only one set of parameters is needed, user provides the wave amplitude (parameter A) and the frequency (parameter B).<br>
<img src="https://github.com/rkbrian/Cpp_Hack_wave/blob/main/Cpp_004.jpg" width="700" align="center">

### Flowchart:
<img src="https://github.com/rkbrian/Cpp_Hack_wave/blob/main/Flowchart_SineWaves.jpg" height="800" align="center">

### More info:
 - https://en.wikipedia.org/wiki/Sine_wave
 - https://www.physicsclassroom.com/class/waves/Lesson-3/Interference-of-Waves
 - https://en.wikipedia.org/wiki/Mathematics_of_three-phase_electric_power
