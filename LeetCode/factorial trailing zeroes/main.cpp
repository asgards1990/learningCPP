#include <iostream>
#include <cmath>
using namespace std;

int timesDiv(int n,int d)
{
    int result(0);
    while(n>=d)
    {
        result += n/d;
        n /= d;
    }
    return result;
}
int trailingZeroes(int n)
{
    int number2(timesDiv(n,2));
    int number5(timesDiv(n,5));
    return min(number2,number5);
}

int factorial(int n)
{
    if (n<=1)
    {
        return 1;
    }
    else
    {
        return n*factorial(n-1);
    }
}
int main()
{
    int n(10);
    int nF(factorial(n));
    int zeroes(trailingZeroes(n));
    cout << "n!==" << nF << ", number of zeroes==" << zeroes << endl;
    return 0;
}
