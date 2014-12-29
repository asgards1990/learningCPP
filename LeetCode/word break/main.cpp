#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>
using namespace std;

int maxLength(unordered_set<string> &dict)
{
    int result(0);
    for (auto it=dict.begin(); it!=dict.end(); ++it)
    {
        int current((*it).size());
        if (current>result)
            result=current;

    }
    return result;
};

//bool fRec(string s, unordered_set<string> &dict, int maxLength)
//{
//    int l(s.size());
//    if (l==0)
//    {
//        return true;
//    }
//    else
//    {
//        for (int k=1; k<=min(maxLength,l); k++)
//        {
//
//            if (dict.find(s.substr(0,k))!=dict.end())
//            {
//                if (fRec(s.substr(k),dict,maxLength))
//                {
//                    return true;
//                }
//            }
//        }
//        return false;
//    }
//};

bool wordBreak(string s, unordered_set<string> &dict)
{
    vector<bool> substrEligible;
    substrEligible.push_back(true);
    int maxL(maxLength(dict));
    int l(s.size());
//    k designates the substrings of k latest letters
    for (int k=1; k<=l; k++)
    {
        for (int j=1; j<=min(k,maxL); j++)
        {
            cout << "k==" << k <<", j=="<<j<< ",k-j is: " << k-j << ", the substring is: " << s.substr(l-k,j) <<", the substrEligible is: "  << substrEligible[k-j]<< endl;
            if (dict.find(s.substr(l-k,j))!=dict.end() and substrEligible[k-j])
            {
                cout << "pushing true"<< endl;
                substrEligible.push_back(true);
                break;

            }
            else if (j==min(k,maxL))
            {
                cout << "pushing false"<< endl;
                substrEligible.push_back(false);
            }

        }

    }
    for (int k=0; k<=l; k++)
    {
        cout << "result in order " << substrEligible[k] << ", " << endl;
    }
    return substrEligible[l];


}
vector<string> wordBreak2(string s, unordered_set<string> &dict)
{
    vector<vector<string>> substrEligible;
    vector<string> runningSequencesWords;
    string runningString("");
    int maxL(maxLength(dict));
    int l(s.size());

    runningSequencesWords.push_back(runningString);
    substrEligible.push_back(runningSequencesWords);
    runningSequencesWords.clear();

//    k designates the substrings of k latest letters
    for (int k=1; k<=l; k++)
    {
        for (int j=1; j<=min(k,maxL); j++)
        {
            if (dict.find(s.substr(l-k,j))!=dict.end() and !substrEligible[k-j].empty())
            {
                if(k-j==0)
                {
                    runningSequencesWords.push_back(s.substr(l-k,j));
                }
                else
                {
                    for (int z=0; z<substrEligible[k-j].size(); z++)
                    {

                        runningString = s.substr(l-k,j)+" "+substrEligible[k-j][z];
                        runningSequencesWords.push_back(runningString);
                        runningString = "";
                    }

                }




            }

        }

        substrEligible.push_back(runningSequencesWords);
        runningSequencesWords.clear();


    }

    return substrEligible[l];


}



int main()
{
    unordered_set<string> test;
    test.insert("cat");
    test.insert("cats");
    test.insert("and");
    test.insert("sand");
    test.insert("dog");
    int l(maxLength(test));
    cout << "The length is: " << l << endl;

    string str("catsanddog");
    vector<string> result(wordBreak2(str,test));
    int resL(result.size());
    for (int k=0; k<resL; k++)
    {
        cout << result[k] << endl;
    }

    return 0;
}
;
