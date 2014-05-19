#include "Garages.h"

Garages::Garages()
{
    vector<Vehicule*> listeVehicules;
    m_listeVehicules=listeVehicules;
}

Garages::~Garages()
{
    for(int i(0); i<m_listeVehicules.size(); ++i)
    {
        delete m_listeVehicules[i];  //On lib�re la i-�me case m�moire allou�e
        m_listeVehicules[i] = 0;  //On met le pointeur � 0 pour �viter les soucis
    }
}

void Garages::ajouter(Vehicule* vehicule)
{
    m_listeVehicules.push_back(vehicule);
}

void Garages::supprimer(int position)
{
    if (m_listeVehicules.size()<=position)
    {
        cout << "Erreur: il n'y a pas autant de v�hicules dans le garage." << endl;
    }
    else
    {
        delete m_listeVehicules[position];  //On lib�re la position-�me case m�moire allou�e
        m_listeVehicules[position] = 0;
    }
}

void Garages::affiche(int position) const
{
    if (position==-1)
    {
        for(int i(0); i<m_listeVehicules.size(); ++i)
    {
        m_listeVehicules[i]->affiche();
    }

    }
    else if (m_listeVehicules.size()<=position)
    {
        cout << "Erreur: il n'y a pas autant de v�hicules dans le garage." << endl;
    }
    else
    {
        m_listeVehicules[position]->affiche();
    }

}
