#ifndef GARAGES_H
#define GARAGES_H

#include <Vehicule.h>
#include <vector>
class Garages
{
    public:
        Garages();
        virtual ~Garages();
        void ajouter(Vehicule* vehicule);
        void supprimer(int position);
        void affiche(int position=-1) const;

    protected:
        vector<Vehicule*> m_listeVehicules;

    private:
};

#endif // GARAGES_H
