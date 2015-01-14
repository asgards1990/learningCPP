#include <iostream>
#include <vector>
using namespace std;
vector<string> wordsFromString(string &s)
{
     int k(0);
    int l(s.size());
    if(l==0)
    return {};
    while(s[k]==' '&&k<l)
    {
        k++;
    }

    string word("");
    vector<string> output;
    for (int j=k; j<l; j++)
    {

        if (s[j]==' ')
        {
            output.push_back(word);
            word="";
        }
        else
        {
            word+=s[j];
        }

    }
    output.push_back(word);
    k=output.size()-1;
    while(output[k]=="")
    {
        output.pop_back();
        k--;
    }

    return output;
}

string formString(vector<string> v)
{
    int l(v.size());
    if (l==0)
        return "";
    string output(v[l-1]);
    for (int k=l-2; k>=0; k--)
    {
        output+=" "+v[k];
    }
    return output;
}
void reverseWords2(string &s)
{
    s=formString(wordsFromString(s));
}


void reverseWords(string &s)
{
    int l(s.size());
    auto iter=s.end();
    string word ="";
    bool has1word(false);
    for (int k=0;k<l;k++)
    {
        if (s[k]==' ')
        {
            if (word!="")
            {s.insert(l,word+" ");
            has1word=true;
            word.clear();
            }

        }
        else
            word+=s[k];
    }
    if (word!="")
    {
        s.insert(l,word+" ");
         has1word=true;

    }
    if(has1word)
    {
         s.pop_back();

    }
    s.erase(0,l);


}

int main()
{
    string s = "";
    reverseWords(s);
    cout << s << endl;

//    s.insert(s.size(),"what");
//    cout << s << endl;
    return 0;
}
