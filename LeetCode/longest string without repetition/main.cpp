#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

//int lengthOfLongestSubstring(string s)
//{
//    unordered_map<char,int> map;
//    int result(0);
//    int current(0);
//    for(int k=0; k<s.size(); k++)
//    {
//        if (map.find(s[k])==map.end()||map[s[k]]==0)
//        {
//            current++;
//            map[s[k]]=current;
//
//        }
//        else
//        {
//            int temp(map[s[k]]);
//
//            for (auto it=map.begin(); it!=map.end(); it++)
//            {
//                if (it->second!=temp)
//                {
//                    it->second=max((it->second - temp),0);
//                }
//                else
//                {
//                    cout  << "s[k]==" << s[k] << ", map[s[k]]== " << temp << ", ";
//
//                    current = current - map[s[k]]+1;
//                    map[s[k]] = current;
//
//                }
//
//
//            }
//        }
//         cout << "current== " << current  << endl;
//        if (current>result)
//            result = current;
//
//    }
//     return result;
//}
//
//


//int lengthOfLongestSubstring(string s)
//{
//    unordered_map<char,int> map;
//    int current(0);
//    for(int k=0; k<s.size(); k++)
//    {
//        if (map.find(s[k])==map.end())
//        {
//            current++;
//            map[s[k]]=current;
//
//        }
//        else
//        {
//            int temp(lengthOfLongestSubstring(s.substr(map[s[k]])));
//            return max(current,temp);
//        }
//    }
//    return current;
//}

int lengthOfLongestSubstring(string s)
{
    unordered_map<char,int> map;
    int result(0);
    int current(0);
    for(int k=0; k<s.size(); k++)
    {
        if (map.find(s[k])==map.end()||map[s[k]]<k-current)
        {
            current++;
        }
        else
        {
            current = k - map[s[k]];
        }
        map[s[k]]=k;
        if (current>result)
            result = current;
    }

    return result;

}


int main()
{
    string s("wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmco");
    cout <<lengthOfLongestSubstring(s) << endl;
    return 0;
}
