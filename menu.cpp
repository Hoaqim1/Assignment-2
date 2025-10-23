//KOPIA AV MIN MENY FRÅN UPPGIFT 1
//ÄNDRINGAR KRÄVS DÅ DET ÄR EN VECTOR OCH INTE EN ARRAY SOM SKA ANVÄNDAS
//FLER ÄNDRINGAR KRÄVS
#include <iostream>
#include <windows.h>
#include <cmath>
#include <algorithm>
#include "DataManager.h"

using namespace std;

void Menu(DataManager &manager) {
    int choice;
    double sum, avg, MinVal, MaxVal, var, StDev;

    do {
    cout << "Välj mellan 1 till 10 " << '\n';
    cout << "1. Lägg till ett värde i listan " << '\n';
    cout << "2. Visa antal värden i listan " << '\n';
    cout << "3. Visa summan av alla värden i listan" << '\n';
    cout << "4. Visa medelvärdet av alla värden i listan " << '\n';
    cout << "5. Visa min- och maxvärde av alla värden i listan " << '\n';
    cout << "6. Visa varians och standardavvikelsen av alla värden i listan " << '\n';
    cout << "7. Sortera listan stigande ordning" << '\n';
    cout << "8. Sortera listan fallande ordning" << '\n';
    cout << "9. Sök efter ett visst värde i listan " << '\n';
    cout << "10. Avsluta " << '\n';
    cout << "Val: ";
    cin >> choice;

    //Kontroll efter ogiltig inmatning
    if (!cin) { 
        cout << "Ogiltig inmatning" << '\n';
        cin.clear();
        cin.ignore(1000, '\n');
        continue; //Fortsätter vidare i do while loop

    }
        //Menyval hanteras här
    switch (choice){

    case 1: 
        manager.Add_Value();
        break;
    case 2: 
        manager.Show_Value();
        cout << '\n';
        break;
    case 3: 
        sum = 0;
        manager.Calc_Sum(sum);
        if (sum != 0)
        cout << "Summan av alla värden i listan är: " << sum << '\n';
        break;
    case 4: 
        avg = 0;
        manager.Calc_Avg(avg);
        if (avg != 0)
        cout << "Medelvärdet är: " << avg << '\n';
        break;
    case 5: 
        manager.Calc_Min(MinVal);
        manager.Calc_Max(MaxVal);
            cout << "Minsta värdet i listan är: " << MinVal << " och största värdet i listan är: " << MaxVal << '\n';
        break;
    case 6: 
        manager.Calc_Var(var);
        manager.Calc_StdDev(StDev);
        cout << "Variansen är: " << var << " och standardavvikelsen är: " << StDev << '\n';
        break;
    case 7:
        manager.Sort_Func_Asc();
        cout << '\n';
        break;
    case 8:
        manager.Sort_Func_Desc();
        cout << '\n'; 
        break;
    case 9:
        manager.Search_Func();
        cout << '\n'; 
        break;
    case 10:
        manager.Save_File();
        cout << "Programmet Avslutas...";
        return;
    default:
        cout << "Ogiltig inmatning, Välj mellan 1 och 10!" << '\n';
        break;
    }
      //Loopar tills användaren avslutar med input 10    
    } while(choice != 10);

}
