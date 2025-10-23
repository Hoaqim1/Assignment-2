#include "DataManager.h"
#include <iostream>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <fstream>

using namespace std;


void DataManager::Add_Value() {
    double val;
    cout << "Ange ett värde: ";
    cin >> val;

    //Om input från användare är ogiltig
    if (!cin) {
        cout << "Ogiltig inmatning" << '\n';
        cin.clear();
        cin.ignore(1000, '\n');
        return;
    }


    Measurement m;
    m.value = val;
    
    time_t now = std::time(nullptr);
    m.timestamp = std::ctime(&now);
    m.timestamp.pop_back();
    data.push_back(m);
}

void DataManager::Show_Value() {
    if (data.empty()) {
    cout << "Listan har inga värden";
    return;
    }

    for (size_t i = 0; i < data.size(); i++)
    {
        cout << data[i].timestamp << " : " << data[i].value << '\n';
    }
    
}

void DataManager::Calc_Sum(double &sum) {
    if(data.empty()) { 
        cout << "Listan har inga värden" << '\n';
        return;
    }
    sum = 0.0;
    for (const auto &m : data) sum += m.value; 
}

void DataManager::Calc_Avg(double &avg) {
    if(data.empty()) { 
        cout << "Inga värden i listan";
        return;
    }
    avg = 0.0;
    double sum;
    Calc_Sum(sum);
    avg = sum / data.size();
}

void DataManager::Calc_Min(double &MinVal) {
    if(data.empty()) { 
        cout << "Inga värden i listan";
        return;
    }
    MinVal = data.front().value;
    for (const auto &m : data) if (m.value < MinVal) MinVal = m.value;
}

void DataManager::Calc_Max(double &MaxVal) {
    if(data.empty()) {
        cout << "Inga värden i listan";
        return;
    }
    MaxVal = data.front().value;
    for (const auto &m : data) if (m.value > MaxVal) MaxVal = m.value;
}

void DataManager::Calc_Var(double &var) {
    if(data.empty()) {
        cout << "Inga värden i listan";
        return;
    }
    var = 0.0;
    double avg;
    Calc_Avg(avg);
    for (const auto &m : data) {
        var += (m.value - avg) * (m.value - avg);
    }
            var /= data.size();
}

void DataManager::Calc_StdDev(double &StDev) {
    if(data.empty()) {
        cout << "Inga värden i listan";
        return;
    }
    StDev = 0.0;
    double var;
    Calc_Var(var);
    //Tar variansen från tidigare funktion och tar sedan kvadratroten ur variansen.
    StDev = sqrt(var);
}

void DataManager::Sort_Func_Asc() {
    if(data.empty()) {
        cout << "Inga värden i listan";
        return;
    }
    //sorteringsfunktion som använder lambda
    //(https://en.cppreference.com/w/cpp/algorithm/sort.html), (https://www.geeksforgeeks.org/cpp/sort-c-stl), fick iden härifrån.
    std::sort(data.begin(), data.end(), [](const Measurement &a, const Measurement &b) {
        return a.value < b.value;
    });

}

void DataManager::Sort_Func_Desc() {
    if(data.empty()) {
        cout << "Inga värden i listan";
        return;
    }
    //Pekar på start och slut av vektor, anger start och slut, använder sedan en Lambda funktion som gör att sort ska jämföra element a och b.
    //std::sort loopar sedan tills alla element är i rätt ordning.
    std::sort(data.begin(), data.end(), [](const Measurement &a, const Measurement &b) {
        return a.value > b.value;
    });

}

void DataManager::Search_Func() {
    if(data.empty()) {
        cout << "Inga värden i listan";
        return;
    }

    //(https://www.w3schools.com/cpp/ref_algorithm_search.asp)
    double search;
    cout << "Sök efter ett värde: ";
    cin >> search;

    //Programmet går igenom listan, om värdet finns i listan, så blir find true och användare får veta att den är i listan
    bool find = false;
    for (size_t i = 0; i < data.size(); ++i) {
        if (data[i].value == search) {
            cout << "Värdet " << search << " finns i listan" << '\n';
        find = true;
        }
    } 
    if (!find) {
        cout << "Värdet finns inte" << '\n';
    }
}

void DataManager::Save_File() {
    //skapar eller öppnar fil
    std::ofstream file("data.txt"); 
    //om det inte går att öppna filen
    if (!file) {
        cout << "Går ej att spara filen" << '\n';
        return;
    }

    for (const auto &m : data) {
        file << m.timestamp << "," << m.value << '\n';
    }
        cout << "Data sparad." << '\n';

}

void DataManager::Load_File() {
    //Läser in fil
    std::ifstream file("data.txt");

    if (!file) {
        cout << "Går ej att ladda in filen" << '\n';
        return;
        }
    data.clear();
    Measurement m;

    while (getline(file, m.timestamp, ',') && file >> m.value) {
        file.ignore();
        data.push_back(m);
    }
    file.close();
    //cout << "Värdet" << data.size() << " lagrat" << '\n';
}

