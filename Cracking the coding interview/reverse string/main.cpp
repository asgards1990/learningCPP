#include <iostream>
#include <array>
#include <unordered_map>

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

bool haveUniqueCharacters(char* str)
{
    unordered_map<char,int> map;
    char *end = str;
    while (*end)
    {
        if (map.find(*end)!=map.end())
            return false;
        map[*end]=1;
        end++;
    }
    return true;

}

//If I only want the lower case letters.
bool haveAllUniqueCharacters(string str)
{
    if(str.length()>26)
        return false;
    bool isPresent[26] = {false};
    for (int i=0; i<26; i++)
    {
        if(isPresent[str[i]-'a'])
            return false;
        isPresent[str[i]-'a']=true;
    }
    return true;

}

bool isPermutation(string s1,string s2)
{
    int l1(s1.length());
    int l2(s2.length());
    if (l1!=l2)
        return false;
    unordered_map<char,int> map;
    for (int k=0; k<l1; k++)
    {
        map[s1[k]]++;
    }
    for (int k=0; k<l2; k++)
    {
        auto it = map.find(s2[k]);
        if (it==map.end())
            return false;
        if (it->second==1)
            map.erase(s2[k]);
        else
            (it->second)--;
    }
    return true;
}

//This one is faster, and especially if the strings are long.
bool isPermutation2(string s1,string s2)
{
    int l1(s1.length());
    int l2(s2.length());
    if (l1!=l2)
        return false;
    unordered_map<char,int> map;
    for (int k=0; k<l1; k++)
    {
        map[s1[k]]++;
        map[s2[k]]--;
    }
   for (auto it=map.begin();it!=map.end();it++)
   {
       if (it->second!=0)
        return false;
   }
    return true;
}


int main()
{
    char str[] = "1234565789";
    reverse(str);
    int l(lengthString(str));
    cout << "str==" << str << ", l==" << l << endl;

    cout << "Do we have unique characters: ";
    if (haveUniqueCharacters(str))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    string test("abcdefghijklmnopqrstuvwxyg");
    cout << "Is a permutation of the alphabet: ";
    if (haveAllUniqueCharacters(test))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    string s1("lksio");
    string s2("koils");

    cout << "Are \"" << s1 << "\" and \"" << s2 << "\" permutations?: ";
    if (isPermutation2(s1,s2))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}
