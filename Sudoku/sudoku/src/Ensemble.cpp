#include "Ensemble.h"


Ensemble::Ensemble()
{

    //ctor
}

Ensemble::Ensemble(list<int> entry)
{
    int position(0);
    m_howManyMissingNumbers = 9;
    for (int k=0;k<9;k++)
    {
        m_numbers[k] = 0;
    }
    int temp[9] = {0};
    if (!(entry.size()==9))
    {
        cout << "Error: The list does not contain exactly 9 numbers." << endl;
    }
    while (!entry.empty())
    {

        if (entry.front()==0)
        {

            position += 1;
            m_howManyMissingNumbers--;
            entry.pop_front();
        }
        else if (add(entry.front()),position))
        {

            position += 1;
            m_howManyMissingNumbers--;
            entry.pop_front();
        }

        else
        {
            throw new exception();

        }

    }
    return;
    //ctor
}

Ensemble::~Ensemble()
{
    //dtor
    delete m_numbers;
    delete m_howManyMissingNumbers;
}

int* Ensemble::getNumbers()
{
    return m_numbers;

}

bool Ensemble::isCompleted()
{
    if (m_howManyMissingNumbers = 0)
        return true;
    else
        return false;
}

using namespace std;

bool Ensemble::add(int number,int position)
{

    if ((number<1)||(number>9))
    {
        cout << "Error: The number you entered is out of the range 1 - 9." << endl;
        return false;
    }
    else if (position<0||position>8)
    {
        cout << "Error: The position you entered is out of the range 0 - 8." << endl;
        return false;
    }
    else
    {

        for (int k = 0; k<9; k++)
        {



            if (m_numbers[k] == number)
            {

                cout << "Error: The number you entered is already in the ensemble." << endl;
                return false;

            }
        }
        if (m_numbers[position] == 0)
        {
            m_numbers[position] = number;
            m_howManyMissingNumbers --;
            return true;
        }
        else
        {
            cout <<  "This position is already occupied" << endl;
            return false;
        }

    }
}
