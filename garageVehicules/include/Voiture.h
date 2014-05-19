#ifndef VOITURE_H
#define VOITURE_H

#include <Vehicule.h>


class Voiture : public Vehicule
{
    public:
        Voiture(int prix, int portes);
        virtual ~Voiture();
        virtual void affiche() const;
        virtual void nbrRoues() const;

    protected:
        int m_portes;

    private:
};

#endif // VOITURE_H
