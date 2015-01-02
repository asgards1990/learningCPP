#include <iostream>
#include <vector>
#include <string>
#include <array>

using namespace std;

bool isPalindrome(string s)

{
    int l(s.size());
    if(l<=1)
        return true;
    else
    {
        string subS(s.substr(1,l-2));
        return (isPalindrome(subS)&&s[0]==s[l-1]);
    }
}

vector<vector<bool> > isPalindrome2(string s)

{
    int l(s.size());
    vector<vector<bool> > isPalins;
    for (int k=0; k<l; k++)
    {
        vector<bool>* temp = new vector<bool>;
        temp->push_back(true);
        temp->push_back(true);
        isPalins.push_back(*temp);
    }

    for (int j=2; j<l+1; j++)
    {
        for (int k=0; k<=l-j; k++)
        {
            isPalins[k].push_back((s[k]==s[k+j-1]&&isPalins[k+1][j-2]));
        }
    }
    return isPalins;

}

vector<vector<string>> partition(string s)
{
    int l(s.size());
    vector<vector<vector<string>>> subSPartitions;
    string str("");
    vector<string> possiblePartition;
    vector<vector<string>> allPartitions;
    subSPartitions.push_back(allPartitions);

    allPartitions.clear();
    int tL(0);
    for (int k=1; k<=l; k++)
    {
        for (int j=1; j<=k; j++)
        {
            str = s.substr(k-j,j);
            if (isPalindrome(str))
            {
                tL = subSPartitions[k-j].size();
                if (tL == 0)
                {
                    possiblePartition.clear();
                    possiblePartition.push_back(str);
                    allPartitions.push_back(possiblePartition);
                }

                for (int m=0; m<tL; m++)
                {

                    possiblePartition = subSPartitions[k-j][m];
                    possiblePartition.push_back(str);
                    allPartitions.push_back(possiblePartition);
                }



            }
        }
        subSPartitions.push_back(allPartitions);
        allPartitions.clear();
    }
    return subSPartitions[l];

}


vector<vector<string>> partition2(string s)
{

    vector<vector<bool> > isPalins(isPalindrome2(s));
    int l(s.size());
    vector<vector<vector<string>>> subSPartitions;
    string str("");
    vector<string> possiblePartition;
    vector<vector<string>> allPartitions;
    subSPartitions.push_back(allPartitions);

    allPartitions.clear();
    int tL(0);
    for (int k=1; k<=l; k++)
    {
        for (int j=1; j<=k; j++)
        {

            if (isPalins[k-j][j])
            {
                str = s.substr(k-j,j);
                tL = subSPartitions[k-j].size();
                if (tL == 0)
                {
                    possiblePartition.clear();
                    possiblePartition.push_back(str);
                    allPartitions.push_back(possiblePartition);
                }

                for (int m=0; m<tL; m++)
                {

                    possiblePartition = subSPartitions[k-j][m];
                    possiblePartition.push_back(str);
                    allPartitions.push_back(possiblePartition);
                }



            }
        }
        subSPartitions.push_back(allPartitions);
        allPartitions.clear();
    }
    return subSPartitions[l];

}



int main()
{
    string test("kwtbjmsjvbrwriqwxadwnufplszhqccayvdhhvscxjaqsrmrrqngmuvxnugdzjfxeihogzsdjtvdmkudckjoggltcuybddbjoizu");
    vector<vector<string>> result(partition2(test));
    cout << result.size() << endl;

    for (int k=0; k<result.size(); k++)
    {
        for (int j=0; j<result[k].size(); j++)
        {
            cout << result[k][j] <<", ";
        }
        cout << endl;
    }
//    vector<vector<bool> > isPalins(isPalindrome2(test));
//    int l2(isPalins.size());
//    cout << l2 << endl;
//    cout << isPalindrome2(test) << endl;
    return 0;
}
