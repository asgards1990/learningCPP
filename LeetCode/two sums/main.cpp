#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int> &numbers, int target)
{

    unordered_map<int,vector<int> > occurences;
    vector<int> result;
    int l(numbers.size());
    for (int k=0;k<l;k++)
    {

        occurences[numbers[k]].push_back(k);
    }
    for(auto it=occurences.begin();it!=occurences.end();it++)
    {
        if (occurences.find(target-it->first)!=occurences.end())
        {
            if(it->first==target-it->first)
            {
                if(it->second.size()>1)
                {
                    result.push_back(it->second[0]+1);
                    result.push_back(it->second[1]+1);
                }
            }
            else
            {
                if (it->second[0]<occurences[target-it->first][0])
                {
                    result.push_back(it->second[0]+1);
                    result.push_back(occurences[target-it->first][0]+1);
                }
                else
                {
                    result.push_back(occurences[target-it->first][0]+1);
                    result.push_back(it->second[0]+1);
                }
            }
        }
    }

    return result;
}
int main()
{
    vector<int> test;
    test.push_back(-3);
    test.push_back(4);
    test.push_back(3);
    test.push_back(90);

    vector<int> result(twoSum(test,0));
    cout << result[0] << ", " << result[1] << endl;
    return 0;
}
