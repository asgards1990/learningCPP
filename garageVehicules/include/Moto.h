#ifndef MOTO_H
#define MOTO_H

#include <Vehicule.h>


class Moto : public Vehicule
{
    public:
        Moto(int prix, double vitesseMax);
        virtual ~Moto();
        virtual void affiche() const;
        virtual void nbrRoues() const;

    protected:
        double m_vitesse; //vitesse maximale du moto.
    private:
};

#endif // MOTO_H
