#ifndef VEHICULE_H
#define VEHICULE_H

#include <iostream>
using namespace std;

class Vehicule
{
    public:
        Vehicule(int prix);
        virtual ~Vehicule();
        virtual void affiche() const;
        virtual void nbrRoues() const = 0;
/* ceci est une méthode virtuelle pure, ce qui fait de cette classe une classe abstraite
une classe abstraite ne peut pas être instanciée i.e il ne peut pas exister d'élément
véhicule, en revanche il est possible de créer un pointeur vehicule* pointant vers la case
0 lequel pourrait pointer sur une case comportant un élément d'une classe fille de vehicule
. De plus, toutes les classes filles dans lesquelles cette méthode n'est pas définie sont
considérées comme abstraites */

    protected:
        int m_prix;

    private:
};

#endif // VEHICULE_H
