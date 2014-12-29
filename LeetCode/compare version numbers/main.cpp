#include <iostream>
#include <string>
#include <sstream>


using namespace std;

int compareVersion(string version1, string version2)
{
    int index1(0);
    int index2(0);
    string str1("0");
    string str2("0");
    int num1(0);
    int num2(0);
    int l1(version1.length());
    int l2(version2.length());
    while (version1.compare(index1,1,".")!=0&&index1<l1)
    {
        str1.append(version1.substr(index1,1));
        ++index1;

    }

    while (version2.compare(index2,1,".")!=0&&index2<l2)
    {
        str2.append(version2.substr(index2,1));
        ++index2;

    }

    stringstream convert(str1);
    convert >> num1;
    convert.str("");
    convert.clear();

    convert << str2;
    convert >> num2;
    convert.str("");
    convert.clear();

    if (num1>num2)
    {
        return 1;
    }
    else if (num1<num2)
    {
        return -1;

    }
    else
    {
//        cout << "index1: " << index1 << "index2: " << index2 << endl;
        if (index1 >= l1-1&&index2>=l2-1)
        {
            return 0;

        }
        if (index1 >= l1-1)
        {
            str1 ="";
        }
        else
        {
            str1 = version1.substr(index1+1);

        }

        if (index2 >= l2-1)
        {
            str2 ="";
        }
        else
        {
            str2 = version2.substr(index2+1);

        }
//        cout << "str1: " << str1 << "str2: " << str2 << endl;
        return compareVersion(str1,str2);


    }




}



int main()
{
//    string str("0");
//    stringstream convert(str);
//    int test;
//    int test2(0);
//    convert >> test;
//
//    string str2("1");
//    convert.str("");
//    convert.clear();
//    convert << str2;
//    convert >> test2;
//    cout << "test: " << (test) << endl;
//    cout << "test2: " << (test2) << endl;

    cout << compareVersion("1.0","1") << endl;
    return 0;
}
