#include <iostream>

using namespace std;

string replaceSpace(string s)
{
    string output("");
    bool toBeReplaced(false);
    for (int k=0; k<s.size(); k++)
    {
        if (s[k]==' ')
        {
            toBeReplaced=true;

        }
        else
        {
            if(toBeReplaced)
            {
                toBeReplaced = false;
                output += "%20";
            }
            output+=s[k];

        }

    }
    return output;

}
//
//string replaceSpace2(string s,int l)
//{
//
//
//}
int main()
{
    string s("Mr John  Smith     ");

    string res(replaceSpace(s));
    cout << res << endl;
    return 0;
}
