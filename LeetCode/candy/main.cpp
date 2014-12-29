#include <iostream>
#include <utility>
#include <vector>
using namespace std;


int candy(vector<int> &ratings)
{
    int l(ratings.size());
    if (l==0)
    {
        return 0;
    }
    else if (l==1)
    {
        return 1;

    }
    else if (l==2)
    {
        if (ratings[0]==ratings[1])
            return 2;
        else
            return 3;
    }
    else
    {
//  let's look at the cycles up and down.
        int consecutiveUp(1);
        int consecutiveDown(1);
        bool isIncreasing(true);
        int result(0);
        int inc(0);
        while (inc<l-1)
        {

            if (isIncreasing)
            {
                if (ratings[inc+1]>ratings[inc])
                {
                    result += consecutiveUp;
                    consecutiveUp++;
                }
                else if (ratings[inc+1]==ratings[inc])
                {
                    result += consecutiveUp;

                    consecutiveUp = 1;
                }
                else
                {
                    isIncreasing = false;
                    consecutiveDown = 2;
                }

            }
            else
            {
                if  (ratings[inc+1]<ratings[inc])
                {
                    consecutiveDown++;
                }
                else
                {
                    if (consecutiveDown <= consecutiveUp )
                    {
                        result += consecutiveUp + (consecutiveDown-1)*consecutiveDown/2;

                    }
                    else
                    {
                        result += consecutiveDown*(consecutiveDown+1)/2;
                    }

                    if (ratings[inc+1]==ratings[inc])
                    {
                        consecutiveUp = 1;
                        consecutiveDown = 1;
                    }
                    else
                    {
                        consecutiveUp = 2;
                        isIncreasing = true;
                    }


                }


            }
            cout << "current result: " << result << endl;

            inc++;
        }
        if (ratings[l-1]==ratings[l-2])
            result++;
        else if (ratings[l-1]>ratings[l-2])
            result += consecutiveUp;
        else
        {
            if (consecutiveDown <= consecutiveUp )
            {
                result += consecutiveUp + (consecutiveDown-1)*consecutiveDown/2;

            }
            else
            {
                result += consecutiveDown*(consecutiveDown+1)/2;
            }

        }


        return result;
    }


}

int main()
{
    vector<int> test(2);
    test.push_back(2);
    test.push_back(1);
    test.push_back(0);
    test.push_back(0);

    int result(candy(test));
    cout << result << endl;
    return 0;
}
