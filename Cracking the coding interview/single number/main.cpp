#include <iostream>
#include <vector>
using namespace std;

        void display(vector<int> v)
        {
            for (int k=0;k<v.size();k++)
            {
                cout << v[k] << ", ";
            }
            cout << endl;
        }

 vector<int> toBase3 (int n) {
        //The extra bit is for the sign
        vector<int> result(22,0);
        if (n<0)
        {result[21]=-1;
        n=-(n+3);}
        int index=0;
        while (n>0)
        {
            result[index]=n%3;
            index++;
            n /= 3;
        }
        return result;

    }

    int toBase10(vector<int> v) {
        int n(0);
        for (int k=20;k>=0;k--)
        {
            n = 3*n+v[k];
        }
        if (v[21]==-1)
        n=-n;
        return n;
    }

    vector<int> base3XOR(vector<int> v1,vector<int> v2)
    {
        vector<int> result(22,0);
        for (int k=0;k<22;k++)
        {
            result[k]=(v1[k]+v2[k])%3;
        }
    return result;
    }

    int singleNumber(int A[], int n) {
        vector<int> vResult(22,0);
        for (int k=0;k<n;k++)
        {
            vResult = base3XOR(vResult,toBase3(A[k]));
        }
        if(vResult[21]==-1)
            return toBase10(vResult)-3;
        return toBase10(vResult);
        }

int main()
{
    int A[] = {-401451,-177656,-2147483646,-473874,-814645,-2147483646,-852036,-457533,-401451,-473874,-401451,-216555,-917279,-457533,-852036,-457533,-177656,-2147483646,-177656,-917279,-473874,-852036,-917279,-216555,-814645,2147483645,-2147483648,2147483645,-814645,2147483645,-216555};
   vector<int> B {-401451,-177656,-2147483646,-473874,-814645,-2147483646,-852036,-457533,-401451,-473874,-401451,-216555,-917279,-457533,-852036,-457533,-177656,-2147483646,-177656,-917279,-473874,-852036,-917279,-216555,-814645,2147483645,-2147483648,2147483645,-814645,2147483645,-216555};
    cout << singleNumber(A,B.size())<< " size==" << B.size()<<endl;
//    vector<int> C{0,1,2,2,0,0,0,0,0,1,0,2,0,0,0,0,0,0,0,0,0,0};
//     for (int k=0;k<31;k++)
//         display(toBase3(A[k]));
//         int x(2147483648);
//    cout << x<< endl;
        return 0;
}
