#include <iostream>
#include <fstream>
#include <deque>

using namespace std;

int main()
{
    int K(10);
    string const adress("test.txt");
    ifstream myFeed(adress.c_str());
    if (myFeed)
    {
        deque<string> s;
        string line;
        while (getline(myFeed,line))
        {
            s.push_back(line);
            if (s.size()>K)
                s.pop_front();
        }
        for (auto it=s.begin();it!=s.end();it++)
        {
            cout << *it << endl;
        }

    }
    return 0;
}
