#include <iostream>
#include <unordered_map>

using namespace std;
string fractionToDecimal(int num, int den) {

        if (den==0)
        return to_string(num);
        if (den==1)
        return to_string(num);
        if (den==-1)
        {
            if (num<0)
            return to_string(-(long long) num);
            return "-"+to_string(num);
        }
        if (num%den==0)
        return to_string(num/den);

        long numerator(0);
        long denominator(0);
        string s("");

        if(num<0&&den<0)
        {
        numerator = - (long)num;
        denominator = - (long)den;
        }
        else if (num<0)
        {
            numerator = - (long)num;
            denominator = (long)den;
            s+="-";
        }
        else if (den<0)
        {
            denominator = - (long)den;
            numerator =  (long)num;
            s+="-";
        }
        else
            {denominator = (long)den;
            numerator =  (long)num;

        }

        long integerPart(numerator/denominator);
        long remainingNum(numerator%denominator);

        s+=to_string(integerPart)+".";
        int index(s.size());
        unordered_map<long,int> map;
        bool isPeriodical(true);


        while (map.find(remainingNum)==map.end()&&isPeriodical)
        {
            map[remainingNum]=index;
            remainingNum*=10;
            integerPart=remainingNum/denominator;
            remainingNum=remainingNum%denominator;
            s+=to_string(integerPart);
            isPeriodical=(remainingNum!=0);
            index++;

        }
        if (isPeriodical)
        {
        s.insert(map[remainingNum],"(");
        s.push_back(')');
        }
        return s;

    }
int main()
{
    cout << fractionToDecimal(1,5) << endl;
    return 0;
}
