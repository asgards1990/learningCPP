#include <iostream>
//Using list will cause memory limit excess...
#include <deque>
#include <vector>
#include "MinStack.h"

using namespace std;

int findMin(vector<int> &num) {
        int l(num.size());
        if (l==1)
        {

//            cout << "only 1 element left" << num[0] << endl;
            return num[0];
        }
        else if (l==2)
        {
            if (num[0]<num[1])
            {
//                cout << "l == 2 and num [0] is smaller" << num[0] << endl;
                return num[0];
            }
            else
            {
//                cout << "num[1] == " << num[1] << endl;
                return num[1];
            }


        }
        else
        {
            if (num[0]<=num[l/2])
            {
                vector<int> newV;
                vector<int> newV2;
                newV.insert(newV.begin(),num.begin(),num.begin()+l/2);
                newV2.insert(newV2.begin(),num.begin()+l/2+1,num.end());
                return min(findMin(newV),findMin(newV2));
            }
            else
            {
                vector<int> newV;
                newV.insert(newV.begin(),num.begin(),num.begin()+l/2+1);
                return findMin(newV);
            }
        }
    }

int main()
{
//    MinStack test;
//    test.push(5);
//    test.push(10);
//    test.push(11);
//    test.push(7);
//    test.push(2);
//    test.push(3);
//    test.push(9);
////    cout << test.getMin() << endl;
//
//    vector<int> test2(10);
//    vector<int> newV;
//    newV.insert(newV.begin(),test2.begin()+5,test2.end());
//    int l(newV.size());
//    cout << l << endl;


    vector<int> test3;
    test3.push_back(1);
    test3.push_back(3);
    test3.push_back(3);
    int result(findMin(test3));
    cout << "result is == " << result << endl;
    return 0;
}
