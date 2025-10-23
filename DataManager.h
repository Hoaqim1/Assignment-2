#ifndef DataManager_h
#define DataManager_h
#include <string>
#include <vector>
#include "Measure.h"

//Här är klassen som hanterar listan, Lägger in gamla funktioner med tid
//Här deklareras alla funktioner, logiken ska vara i cpp filen.
class DataManager {
    private:
        std::vector<Measurement> data;
    
    public:
        void Add_Value();
        void Show_Value();
        void Calc_Sum(double &);
        void Calc_Avg(double &);
        void Calc_Min(double &);
        void Calc_Max(double &);
        void Calc_Var(double &);
        void Calc_StdDev(double &);
        void Sort_Func_Asc();
        void Sort_Func_Desc();
        void Search_Func();
        void Save_File();
        void Load_File();
    

};

#endif