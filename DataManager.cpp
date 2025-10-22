#include "DataManager.h"
#include <iostream>
#include <ctime>
#include <cmath>
#include <algorithm>

using namespace std;

//Logik för funktioner. Då det används en vektor nu så måste vissa saker ändras
//Testa logiken och se hur mycket som måste ändras.

void DataManager::Add_Value(double val, const std::string& tstamp) {
    Measure m;
    m.value = val;
    m.timestamp = tstamp;
    data.push_back(m);
    
}

void DataManager::Show_Value() {
    if (data.empty()) {
        cout << "Listan har inga värden" << '\n';
    }

    for (size_t i = 0; i < data.size(); i++)
    {
        cout << data[i].timestamp << " " << data[i].value << '\n';
    }
    
}

void DataManager::Calc_Sum(double &sum) {
    sum = 0.0;
    if(data.empty())
        return;
    for (const auto &m : data) sum += m.value; 
}

void DataManager::Calc_Avg(double &avg) {
    avg = 0.0;
    if(data.empty())
        return;
    double sum;
    Calc_Sum(sum);
    avg = sum / data.size();
}

void DataManager::Calc_Min(double &MinVal) {
    if(data.empty())
        return;
    MinVal = data.front().value;
    for (const auto &m : data) if (m.value < MinVal) MinVal = m.value;
}

void DataManager::Calc_Max(double &MaxVal) {
    if(data.empty())
        return;
    MaxVal = 0.0;
    MaxVal = data.front().value;
    for (const auto &m : data) if (m.value > MaxVal) MaxVal = m.value;
}

void DataManager::Calc_Var(double &var) {
    if(data.empty())
        return;
    var = 0.0;
    double avg;
    Calc_Avg(avg);
    for (const auto &m : data) {
        var += (m.value - avg) * (m.value - avg);
    }
            var /= data.size();
}

void DataManager::calc_StdDev(double &StDev) {
    if(data.empty())
        return;
    StDev = 0.0;
    double var;
    Calc_Var(var);
    StDev = sqrt(var);
}

void DataManager::Sort_Func_Asc(double &val) {

}

void DataManager::Sort_Func_Desc(double &val) {

}

void DataManager::Search_Func(double &val) {

}