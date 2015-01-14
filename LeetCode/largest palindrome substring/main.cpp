#include <iostream>
#include <vector>

using namespace std;

string longestPalindrome2(string s)
{

    int sizeInput(s.size());
    if (sizeInput<=1)
        return s;
    int maxL(1);
    string output(s.substr(0,1));
    vector<vector<bool> > isPalindromes(sizeInput);
    for (int k=0; k<sizeInput; k++)
    {
        isPalindromes[k].push_back(true);
        isPalindromes[k].push_back(true);
    }
    for (int j=2; j<=sizeInput; j++)
    {
        for (int i=0; i<=sizeInput-j; i++)
        {
            if (i+maxL>=sizeInput)
                break;
            if (s[i]==s[i+j-1]&&isPalindromes[i+1][j-2])
            {
                isPalindromes[i].push_back(true);
                if (j>maxL)
                {
                    maxL = j;
                    output =s.substr(i,j);
                }

            }
            else
                isPalindromes[i].push_back(false);
        }
    }
    return output;
}


string longestPalindrome(string s)
{
    int sizeInput(s.size());
    if (sizeInput<=1)
        return s;
    int maxL(1);
    string output(s.substr(0,1));
    vector<vector<bool> > singleCentroid(sizeInput);
    vector<vector<bool> > doubleCentroid(sizeInput);
    for (int i=0; i<sizeInput; i++)
    {
        for (int j=0; j<min(i+1,sizeInput-i); j++)
        {
            if (s[i-j]==s[i+j])
                singleCentroid[i].push_back(true);
            else
                break;
        }
        for (int j=0; j<min(i+1,sizeInput-i-1); j++)
        {
            if (s[i-j]==s[i+j+1])
                doubleCentroid[i].push_back(true);
            else
                break;
        }

    }
    for (int i=0; i<sizeInput; i++)
    {
        int temp1(singleCentroid[i].size()*2-1);
        int temp2(doubleCentroid[i].size()*2);
        cout << "temp1==" << temp1 << ", temp2==" << temp2 << endl;
        if(temp1>maxL)
        {
            maxL = temp1;
            output = s.substr(i-temp1/2,temp1);
        }
        if(temp2>maxL)
        {

            maxL = temp2;
            output = s.substr(i-temp2/2+1,temp2);

        }

    }
    return output;
}

int main()
{
    string x("bb");
    cout << longestPalindrome(x) << endl;
    return 0;
}
