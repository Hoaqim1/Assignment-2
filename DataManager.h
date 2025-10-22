#ifndef DataManager_h
#define DataManager_h
#include <string>
#include <vector>
#include "Measure.h"

//Här är klassen som hanterar listan, Lägger in gamla funktioner med tid
//Här deklareras alla funktioner, logiken ska vara i cpp filen.
class DataManager {
    private:
        std::vector<Measure> data;
    
    public:
        void Add_Value(double, const std::string&);
        void Show_Value(double, const std::string&);
        void Calc_Sum(double &);
        void Calc_Avg(double &);
        void Calc_Min(double &);
        void Calc_Max(double &);
        void Calc_Var(double &);
        void calc_StdDev(double &);
        void Sort_Func_Asc();
        void Sort_Func_Desc();
        void Search_Func(double);
    

};

#endif