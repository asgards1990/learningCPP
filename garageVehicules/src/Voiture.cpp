#include "Voiture.h"

Voiture::Voiture(int prix, int portes)
    :Vehicule(prix), m_portes(portes)
{
    //ctor
}

Voiture::~Voiture()
{
    //dtor
}

void Voiture::affiche() const
{
    cout << "Ceci est une voiture avec " << m_portes << " portes et coutant " << m_prix << " euros." << endl;
}

void Voiture::nbrRoues() const
{
    cout << "Ceci est une voiture, et a donc 4 roues." << endl;
}
