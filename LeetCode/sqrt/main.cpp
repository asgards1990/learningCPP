#include <iostream>

using namespace std;
 int sqrt(int y) {
    if (y<2)
        return y;
    long long x = (long long)y;
    long long lBound(1);


    while (lBound*lBound*4<=x)
    {
        lBound *=2;

    }


    if (lBound*lBound==x)
        return lBound;
    long long uBound(min(2*lBound,(long long)65535));
    long long mid((lBound+uBound)/2);
    while(uBound-lBound>1)
    {
        long long temp(mid*mid);
        if (temp==x)
            return (int) mid;
        if (temp>x)
            uBound=mid;
        else
            lBound=mid;
        mid=(lBound+uBound)/2;
    }
    return (int)lBound;
}
int main()
{
    cout <<sqrt(2147395599) << endl;

    return 0;
}
