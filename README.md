# Assignment-2
https://github.com/Hoaqim1/Assignment-2
ASSIGNMENT 1 REPO WITH FULL README BELOW!
https://github.com/Hoaqim1/Assignment-1---Programing

How to compile:
Download files
In terminal, run:
g++ main.cpp menu.cpp DataManager.cpp -o DataManager.exe


*Structure*
main.cpp - Starts program and calls menu
menu.cpp/menu.h - User interface, header file for menu.
DataManager.cpp/DataManager.h - Contains logic for methods used, example is sorting or saving data. Header file for DataManager.
Measure.h - Measurement structure is defined here, value + timestamp variables.

*New Features*
Uses a vector that stores a value and a timestamp(Measurement).
Saves and loads data to a txt file.
Methods instead of functions that now work with a vector, no more 10 value limit.
Header files instead of just forward declaration.