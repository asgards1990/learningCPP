#ifndef DECK_H
#define DECK_H
#include <iostream>

#include <vector>
#include <utility>

using namespace std;

class Deck
{
public:
    Deck();
    virtual ~Deck();
    void display();
protected:
private:
    vector<pair<int,int> > numberCards;
    vector<pair<char,int> > figureCards;
};

#endif // DECK_H
