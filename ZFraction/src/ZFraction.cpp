#include "ZFraction.h"
#include <iostream>

ZFraction::ZFraction() : m_numerator(0), m_denominator(1)
{

}

ZFraction::ZFraction(int numerator) : m_numerator(numerator), m_denominator(1)
{

}

ZFraction::ZFraction(int numerator, int denominator)
{
    if (denominator==0)
    {
        std::cout << "ERROR: Division by 0 not allowed" << std::endl;
    }
    else
    {
        bool isPositive(true);

        if (numerator<0&&denominator<0)
        {
            numerator=-numerator;
            denominator=-denominator;
        }
        else if (numerator<0)
        {
            numerator=-numerator;
            isPositive=false;
        }
        else if (denominator<0)
        {
            denominator=-denominator;
            isPositive=false;
        }

        int big(numerator), small(denominator), residue(0);
        if(big<small)
        {
            big=denominator;
            small=numerator;
        }

        residue=big%small;
        while(residue!=0)
        {
            big=small;
            small=residue;
            residue=big%small;
        }
        if(isPositive)
        {
            m_numerator=numerator/small;
            m_denominator=denominator/small;
        }
        else
        {
            m_numerator=-numerator/small;
            m_denominator=denominator/small;
        }


    }

}

ZFraction::~ZFraction()
{
    //dtor
}

bool ZFraction::operator<(ZFraction const& b) const
{
    return (m_numerator*b.m_denominator<m_denominator*b.m_numerator);

}

bool ZFraction::operator>(ZFraction const& b) const
{
    return (m_numerator*b.m_denominator>m_denominator*b.m_numerator);
}

bool ZFraction::operator==(ZFraction const& b) const
{
    return (m_numerator*b.m_denominator==m_denominator*b.m_numerator);
}

ZFraction ZFraction::operator*(ZFraction const& b) const
{
    ZFraction result(m_numerator*b.m_numerator,m_denominator*b.m_denominator);
    return result;
}

ZFraction ZFraction::operator+(ZFraction const& b) const
{
    ZFraction result(m_numerator*b.m_denominator+m_denominator*b.m_numerator,m_denominator*b.m_denominator);
    return result;
}

ZFraction ZFraction::operator/(ZFraction const& b) const
{
    if (b.m_numerator==0)
    {
        std::cout << "ERROR: Division by 0 not allowed" << std::endl;
    }
    else
    {
        ZFraction result(m_numerator*b.m_denominator,m_denominator*b.m_numerator);
        return result;
    }

}

ZFraction ZFraction::operator-(ZFraction const& b) const
{
    ZFraction result(m_numerator*b.m_denominator-m_denominator*b.m_numerator,m_denominator*b.m_denominator);
    return result;
}

void ZFraction::show (std::ostream& flux) const
{
    if(m_denominator == 1)
    {
        flux << m_numerator;
    }
    else
    {
        flux << m_numerator << '/' << m_denominator;
    }
}

ZFraction ZFraction::abs()
{
    if (m_numerator>=0)
    {
        ZFraction result(m_numerator,m_denominator);
        return result;
    }

     else
    {
        ZFraction result(-m_numerator,m_denominator);
        return result;
    }

};

//std::ostream& ZFraction::operator<<(std::ostream &flux) const
//{
//    flux << m_numerator << "/" << m_denominator << std::endl;
//    return flux;
//}
