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
/* ceci est une m�thode virtuelle pure, ce qui fait de cette classe une classe abstraite
une classe abstraite ne peut pas �tre instanci�e i.e il ne peut pas exister d'�l�ment
v�hicule, en revanche il est possible de cr�er un pointeur vehicule* pointant vers la case
0 lequel pourrait pointer sur une case comportant un �l�ment d'une classe fille de vehicule
. De plus, toutes les classes filles dans lesquelles cette m�thode n'est pas d�finie sont
consid�r�es comme abstraites */

    protected:
        int m_prix;

    private:
};

#endif // VEHICULE_H
