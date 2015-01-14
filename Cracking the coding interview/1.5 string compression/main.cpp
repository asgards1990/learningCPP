#include <iostream>
#include <string>
#include <sstream>

using namespace std;


string compress(string s)
{
    int l(s.size());
    if (l==1)
        return s;
    string output("");
    int counter(1);

    for (int k=0; k<l-1; k++)
    {
        if (s[k+1]!=s[k])
        {
            stringstream out;
            out << counter;
            string temp(out.str());
            output+=s[k]+temp;
            counter =1;
        }
        else

            counter +=1;
    }
    stringstream out;
    out << counter;
    string temp(out.str());
    output+=s[l-1]+temp;
    if (output.size()<=l)
        return output;
    return s;
}
int main()
{
    string test("aaabccddgggffffgfhhhhh");
    string s("abchf");
    cout << compress(s) << endl;
    return 0;
}
