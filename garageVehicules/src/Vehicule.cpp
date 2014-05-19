#include "Vehicule.h"

Vehicule::Vehicule(int prix)
    :m_prix(prix)
{
    //ctor
}

Vehicule::~Vehicule()
{
    //dtor
}

void Vehicule::affiche() const
{
    cout << "Ceci est un vehicule coutant " << m_prix << " euros." << endl;
}
