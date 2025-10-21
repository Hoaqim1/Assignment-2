//KOPIA AV MIN MENY FRÅN UPPGIFT 1
//ÄNDRINGAR KRÄVS DÅ DET ÄR EN VECTOR OCH INTE EN ARRAY SOM SKA ANVÄNDAS
//FLER ÄNDRINGAR KRÄVS

#include <iostream>
#include <windows.h>
#include <cmath>
#include <algorithm>

using namespace std;

//Deklarerade funktioner
void Add_Value(double list[], int &amount, double &sum);
void Show_Value(double list[], int amount, double &sum);
void Calc_Sum(double list[], int amount, double &sum);
void Calc_mdlv(double list[], int amount, double &mdlv);
void Calc_Min(double list[], int amount, double &MinVal);
void Calc_Max(double list[], int amount, double &MaxVal);
void Calc_Var(double list[], int amount, double &var);
void Calc_stdav(double list[], int amount, double &stdav);
void Sort_Func(double list[], int &amount);
void Search_Func_Asc(double list[], int amount);
void Sort_Func_Desc(double list[], int &amount);
void Search_Func();
void Menu(double list[], int &amount);

int main(){
    SetConsoleOutputCP(65001);


    double list[10];
    int amount = 0;

    //Huvudmenyn
    Menu(list, amount);


    
}