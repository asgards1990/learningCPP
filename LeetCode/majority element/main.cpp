#include <iostream>
#include <vector>
#include <map>

int majorityElement(std::vector<int> &num)
 {

    int l(num.size());
    std::map<int, int> m;
    for (int k=0;k<l;++k)
    {
        int argument(num[k]);
        m[argument] = 0;
    }
    for (int k=0;k<l;++k)

    {
        ++m[num[k]];
        std::cout <<" here is the number of times: " << m[num[k]] << " here the number: " << num[k] << std::endl;
    }
     for (int k=0;k<l;++k)

    {

        if (m[num[k]]>l/2)
        {
            std::cout << num[k] << std::endl;
            return num[k];
        }
    }
};


int main()
{
    std::vector<int> test;
    for (int k=0;k<100;++k)
    {
        test.push_back(k%2);
    }
    test.push_back((0));
    test.push_back((0));

std::vector<int> test2;
test2.push_back(1);

    majorityElement(test2);

    return 0;
}


