#include <iostream>
#include <string>

using namespace std;


bool isMatch(const char *s, const char *p)
{

   if (*p=='\0')
    return (*s=='\0');
   if (*(p+1)!='*')
   {
       return (*s==*p||(*p=='.'&&*s!='\0'))&&isMatch(s+1,p+1);
   }
   else
   {

       return (isMatch(s,p+2))||((*s==*p||(*p=='.'&&*s!='\0'))&&(isMatch(s+1,p)));
   }
   return false;

}

int main()
{
    char s[] = "acaabbaccbbacaabbbb";
    char p[] = "a*.*b*.*a*aa*a*";
    cout << isMatch(s,p) << endl;
    return 0;
}
