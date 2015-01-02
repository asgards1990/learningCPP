#include <iostream>
#include <array>

using namespace std;

int lengthString(char* str)
{
    int l(0);
    while (str[l]!='\0')
    {
        l++;
    }
    return l;
    }

void reverse(char* str)
{
    char *end = str;
    char tmp;
    if (str)
    {
        while (*end)
            ++end;
    }
    --end;
    while (str<end)
    {
        tmp = *str;
        *str++ = *end;
        *end-- = tmp;
    }
}
int main()
{
    char str[] = "123456789";
    reverse(str);
    int l(lengthString(str));
    cout << "str==" << str << ", l==" << l << endl;
    return 0;
}
