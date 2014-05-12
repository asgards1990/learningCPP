#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    double a(0), b(0), sum(0);
    cout << "voulez vous faire la somme entre: " << endl;
    cin >> a;
    cin >> b;

    sum = a+b;
    cout << a << "+" << b << "=" << sum << endl;

    vector<int> vector(5);
    int table[5];
    int sizeVector(vector.size());
    cout << sizeVector << " " << vector[0]<< endl;

    string const nomFichier("learningDocuments/informations.txt");
    ofstream monFlux(nomFichier.c_str(), ios::app);

    if(monFlux)
    {
        monFlux << "My name is Su, Su YANG." << endl;
    }
    else
    {
        cout << "ERROR: Unable to open the file." << endl;
    }

    return 0;
}
