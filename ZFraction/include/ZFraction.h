#ifndef ZFRACTION_H
#define ZFRACTION_H
#include <iostream>
class ZFraction
{
    public:
        ZFraction();
        ZFraction(int numerator);
        ZFraction(int numerator, int denominator);
        virtual ~ZFraction();

        bool operator<(ZFraction const& b) const;
        bool operator>(ZFraction const& b) const;
        bool operator==(ZFraction const& b) const;
        ZFraction operator*(ZFraction const& b) const;
        ZFraction operator+(ZFraction const& b) const;
        ZFraction operator/(ZFraction const& b) const;
        ZFraction operator-(ZFraction const& b) const;
        ZFraction abs();
        void show (std::ostream &flux) const;
//        std::ostream& operator<<(std::ostream &flux) const;
    protected:
    private:
        int m_numerator;
        int m_denominator;
};


#endif // ZFRACTION_H
