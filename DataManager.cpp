#include "DataManager.h"
#include <iostream>
#include <ctime>

using namespace std;

//Logik för funktioner. Då det används en vektor nu så måste vissa saker ändras
//Testa logiken och se hur mycket som måste ändras.

void DataManager::Add_Value(double val, const std::string& tstamp) {
    Measure m;
    m.value = val;
    m.timestamp = tstamp
    data.push_back(m);
    
}

void DataManager::Show_Value(double val, const std::string& tstamp) {
    for (size_t i = 0; i < data.size());
    i++ {
        cout << data[i].timestamp << " " << data[i].value
    }
    
}

void DataManager::Calc_Sum(double val) {
    
}

void DataManager::Calc_Avg(double val) {

}

void DataManager::Calc_Min(double &MinVal) {

}

void DataManager::Calc_Max(double &MaxVal) {

}

void DataManager::Calc_Var(double &var) {

}

void DataManager::calc_StdDev(double &stdav) {

}

void DataManager::Sort_Func_Asc(double &val) {

}

void DataManager::Sort_Func_Desc(double &val) {

}

void DataManager::Search_Func(double &val) {

}