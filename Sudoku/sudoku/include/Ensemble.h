#ifndef ENSEMBLE_H
#define ENSEMBLE_H
#include <iostream>
#include <list>
using namespace std;

class Ensemble
{
    public:
        Ensemble();
        virtual ~Ensemble();
        Ensemble(list<int> entry);

        int* getNumbers();
        bool isCompleted();
        bool add(int number,int position);
    protected:
    private:
        int m_numbers[9];
        int m_howManyMissingNumbers;

};

#endif // ENSEMBLE_H
