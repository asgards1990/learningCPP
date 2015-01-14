#include <iostream>

using namespace std;
bool isPalindrome(int x)
{
    int temp(x);
    int y(0);
    while (temp>0)
    {
        y = 10*y+temp%10;
        temp /= 10;
    }
    return x==y;
}
bool isPalindrome2(int x)
{
    if (x<10)
        return true;

    int l(1);

    while (x>=l)
    {cout << l << endl;
    l *= 10;}

    l /=10;
    cout << l << endl;
    while (x>9)
    {
        if (x/l != x%10)
            return false;
        x = (x%l)/10;
        l/=100;
    }
    return true;
}
int main()
{
    int x(1874994781);
    cout << isPalindrome2(x) << endl;
    return 0;
}
