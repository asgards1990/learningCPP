#include <iostream>
#include "ZFraction.h"
using namespace std;

std::ostream& operator<<(std::ostream& flux, ZFraction const& a)
{
    a.show(flux);
    return flux;
}


int main()
{

    ZFraction a(48,-52);      //Déclare une fraction valant 4/5
    ZFraction b(-2);        //Déclare une fraction valant 2/1 (ce qui vaut 2)
    ZFraction c,d;         //Déclare deux fractions valant 0

    c = a+b;               //Calcule 4/5 + 2/1 = 14/5

    d = a*b;               //Calcule 4/5 * 2/1 = 8/5

    cout << a << " + " << b << " = " << c << endl;

    cout << a << " * " << b << " = " << d << endl;

    cout << "The absolute value of a is: " << a.abs() << endl;


    if(a > b)
        cout << "a is bigger than b." << endl;
    else if(a==b)
        cout << "a and b are equal." << endl;
    else
        cout << "a is smaller than b." << endl;

    return 0;

}
