#ifndef CAMION_H
#define CAMION_H

#include <Vehicule.h>


class Camion : public Vehicule
{
    public:
        Camion(int prix, double poidsMax);
        virtual ~Camion();
        virtual void affiche() const;
        virtual void nbrRoues() const;

    protected:
        double m_poids; //poids maximal

    private:
};

#endif // CAMION_H
