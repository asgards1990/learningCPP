#include <iostream>
#include <array>


using namespace std;
//double findMedianSortedArrays(int A[], int m, int B[], int n)
//{
//    double result(0);
//    if (m==0)
//    {
//        if(n%2==0)
//        {
//            result = (double)(B[n/2-1]+B[n/2])/2;
//        }
//        else
//        {
//            result = (double)B[n/2];
//        }
//    }
//    else if (n==0)
//    {
//        if(m%2==0)
//        {
//            result = (double)(A[m/2-1]+A[m/2])/2;
//        }
//        else
//        {
//            result = (double)A[m/2];
//        }
//    }
//
//    else
//    {
//        int indexA(m/2);
//        int indexADown(0);
//        int indexAUp(m-1);
//        int indexB((n-1)/2);
//        int indexBDown(0);
//        int indexBUp(n-1);
//
//        int minimum(min(A[indexA],B[indexB]));
//        int maximum(max(A[indexA],B[indexB]));
//
//        int diff(min(indexAUp-indexADown,indexBUp-indexBDown));
//        while (diff>0)
//        {
//            cout << "diff ==" << diff << endl;
//            if (minimum==maximum)
//            {
//                return (double)minimum;
//            }
//            else
//            {
//
//                if(A[indexA]==maximum)
//                {
//                    indexAUp=indexA;
//                    indexBDown=indexB;
//
//                    if(A[indexA-(diff+1)/2]>=minimum&&B[indexB+(diff+1)/2]<=maximum)
//                    {
//
//                        indexA -=(diff+1)/2;
//                        indexB +=(diff+1)/2;
//                        indexAUp=indexA;
//                        indexBDown=indexB;
//
//
//                    }
//                    else
//                    {
//                        if(A[indexA-(diff+1)/2]<minimum)
//                            indexADown = indexA -diff/2;
//                        if(B[indexB+(diff+1)/2]>maximum)
//                            indexBUp = indexB +diff/2;
//
//
//                    }
//
//                }
//                else
//                {
//
//                    indexADown=indexA;
//                    indexBUp=indexB;
//
//
//                    if(B[indexB-(diff+1)/2]>=minimum&&A[indexA+(diff+1)/2]<=maximum)
//                    {
//
//                        indexB -=(diff+1)/2;
//                        indexA +=(diff+1)/2;
//                        indexADown=indexA;
//                        indexBUp=indexB;
//
//
//                    }
//                    else
//                    {
//
//                        if(B[indexB-(diff+1)/2]<minimum)
//                            indexBDown = indexB -diff/2;
//                        if(A[indexA+(diff+1)/2]>maximum)
//                            indexAUp = indexA +diff/2;
//
//                    }
//
//                }
//
//                diff = min(indexAUp-indexADown,indexBUp-indexBDown);
//                minimum = min(A[indexA],B[indexB]);
//                maximum = max(A[indexA],B[indexB]);
//
//            }
//
//        }
//        if(indexAUp-indexADown>0)
//        {
//            if (indexA==indexADown)
//            {
//                if(B[indexB]>A[indexA])
//                {
//                    minimum=A[indexA];
//                    maximum=min(B[indexB],A[indexA+1]);
//                }
//
//
//
//            }
//            else if ((indexA==indexAUp))
//            {
//
//                if(B[indexB]<A[indexA])
//                {
//
//                    maximum=A[indexA];
//                    minimum=max(B[indexB],A[indexA-1]);
//                }
//
//            }
//            else
//            {
//                if(B[indexB]>=A[indexA])
//                {
//                    minimum=A[indexA];
//                    maximum=min(B[indexB],A[indexA+1]);
//                }
//                else
//                {
//                    maximum=A[indexA];
//                    minimum=max(B[indexB],A[indexA-1]);
//                }
//            }
//
//        }
//
//        else if (indexBUp-indexBDown>0)
//        {
//            if (indexB==indexBDown)
//            {
//                if(A[indexA]>B[indexB])
//                {
//                    minimum=B[indexB];
//                    maximum=min(A[indexA],B[indexB+1]);
//                }
//
//            }
//            else if ((indexB==indexBUp))
//            {
//
//                if(A[indexA]<B[indexB])
//                {
//
//                    maximum=B[indexB];
//                    minimum=max(A[indexA],B[indexB-1]);
//                }
//            }
//            else
//            {
//                if(A[indexA]>=B[indexB])
//                {
//
//                    minimum=B[indexB];
//                    maximum=min(A[indexA],B[indexB+1]);
//                }
//                else
//                {
//                    maximum=B[indexB];
//                    minimum=max(A[indexA],B[indexB-1]);
//                }
//            }
//
//        }
//        cout << "minimum==" << minimum << ", maximum==" << maximum << endl;
//        if ((m+n)%2==0)
//        {
//            result = double(minimum+maximum)/2;
//
//        }
//        else
//        {
//            if(m%2==0)
//                result = double(minimum);
//
//            else
//                result = double(maximum);
//
//        }
//        cout << "indexBUp==" << indexBUp << ", indexBDown==" << indexBDown << endl;
//
//    }
//
//    return result;
//}
double findMedianSortedArrays(int A[], int m, int B[], int n)
{

    if(m==0&&n==0)
    {
        return NULL;
    }
    else if (m==0)
    {
        if(n%2==0)
        {
            return (double)(B[n/2-1]+B[n/2])/2;
        }
        else
        {
            return (double)B[n/2];
        }
    }
    else if (n==0)
    {
        if(m%2==0)
        {
            return (double)(A[m/2-1]+A[m/2])/2;
        }
        else
        {
            return (double)A[m/2];
        }
    }
    else if (m>n)
    {
        return findMedianSortedArrays(B,n,A,m);
    }
    else
    {
        int indMin(0);
        int indMax(m);
        int indA(0);
        int indB(0);
        int n1(0);
        while (indMin<=indMax)
        {
            indA = (indMin + indMax) >> 1;
            indB = ((m+n + 1) >> 1) - indA;
            cout << "indB==" << indB <<", indA==" << indA << endl;
            if(indB>0&&indA<m&&B[indB-1]>A[indA])
            {
                indMin = indA + 1;
            }
            else if(indA>0&&indB<n&&A[indA-1]>B[indB])
            {
                indMax = indA - 1;
            }
            else
            {

                if (indA==0)
                    n1=B[indB-1];
                else if (indB==0)
                    n1=A[indA-1];
                else
                    n1=max(B[indB-1],A[indA-1]);

                if ((m+n)&1)
                {

                    return n1;
                }


                int n2(0);
                if (indA==m)
                    n2=B[indB];
                else if (indB==n)
                    n2=A[indA];
                else
                    n2=min(A[indA],B[indB]);
                return double(n1+n2)/2;


            }
        }

    }

}


int main()
{
    int A [] = {1,2,3,5,6};
    int B [] = {4};

    cout << findMedianSortedArrays(A,5,B,1) << endl;
    return 0;
}
