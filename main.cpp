#include "DataManager.h"
#include "menu.h"
#include <iostream>
#include <windows.h>

using namespace std;

int main () {
    SetConsoleOutputCP(65001);
    DataManager manage;
    //läser in data från data.txt
    manage.Load_File();
    //startar programmet
    Menu(manage); 
    return 0;

    



    //Menu();
}