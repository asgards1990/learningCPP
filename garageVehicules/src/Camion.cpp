#include "Camion.h"

Camion::Camion(int prix, double poidsMax)
    : Vehicule(prix), m_poids(poidsMax)
{
    //ctor
}

Camion::~Camion()
{
    //dtor
}

void Camion::affiche() const
{
    cout << "Ceci est un camion supportant " << m_poids << " kilos et coutant " << m_prix << " euros." << endl;
}

void Camion::nbrRoues() const
{
    cout << "Ceci est un camion, et a donc 10 roues." << endl;
}
