#include <iostream>
#include <list>
#include "Ensemble.h"


using namespace std;

void test(int tableau[])
{
    tableau[0] = -1;
    cout << sizeof(tableau)/sizeof(tableau[8]) << endl;
}
int main()
{
    list<int> setNumbers;
    for (int k=0;k<9;k++)
    {
        setNumbers.push_back(k+1);
//        cout << setNumbers.back() << endl;

    }


    Ensemble ensemble(setNumbers);
//    int* numbers(ensemble.getNumbers());
    for (int k=0;k<9;k++)
    {
        cout << k << endl;

    }


    return 0;
}
