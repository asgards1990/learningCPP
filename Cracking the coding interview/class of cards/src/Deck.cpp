#include "Deck.h"


Deck::Deck()
{
    for (int k=2; k<=10; k++)
    {
        for(int color=1; color<=4; color++)
            numberCards.push_back(make_pair(k,color));
    }
    for (char c : "JQKA" )
    {
        if(c=='\0')
            break;
        for(int color=1; color<=4; color++)
            figureCards.push_back(make_pair(c,color));
    }
    //ctor
}

Deck::~Deck()
{
    //dtor
}

void Deck::display()
{
    cout << "we have the following number cards: " << endl;
    for (auto it=numberCards.begin(); it!=numberCards.end(); it++)
    {
        cout << "number " << it->first  << " of color " << it->second << endl;
    }

    cout << "And we have the following number cards: " << endl;

    for (auto it=figureCards.begin(); it!=figureCards.end(); it++)
    {
        cout << "figure " << it->first  << " of color " << it->second << endl;
    }
}
