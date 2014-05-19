#include "Moto.h"

Moto::Moto(int prix, double vitesseMax)
    :Vehicule(prix), m_vitesse(vitesseMax)
{
    //ctor
}

Moto::~Moto()
{
    //dtor
}

void Moto::affiche() const
{
    cout << "Ceci est une moto allant a " << m_vitesse << " km/h et coutant " << m_prix << " euros." << endl;
}

void Moto::nbrRoues() const
{
    cout << "Ceci est un moto, et a donc 2 roues." << endl;
}
