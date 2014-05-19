#include <iostream>
#include <Vehicule.h>
#include <Voiture.h>
#include <Moto.h>
#include <Camion.h>
#include <vector>
#include <Garages.h>

using namespace std;

int main()
{
//    vector<Vehicule*> listeVehicules;
//
//    listeVehicules.push_back(new Voiture(15000, 5));
//    listeVehicules.push_back(new Voiture(12000, 3));
//    listeVehicules.push_back(new Moto(2000, 212.5));

    Garages garage;

    garage.ajouter(new Voiture(15000, 5));
    garage.ajouter(new Voiture(12000, 3));
    garage.ajouter(new Moto(2000, 212.5));


    garage.affiche(0);
    garage.affiche(2);
//    listeVehicules[0]->affiche();
//    //On affiche les informations de la première voiture
//
//    listeVehicules[2]->affiche();
//    //Et celles de la moto


    return 0;
}
