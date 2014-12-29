#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int findMin (vector<int> &num)
{
    int l(num.size());
    if (l == 1)
    {
        return num[0];
    }
    else
    {
        int result(num[0]);
        for (int k=1; k<l; k++)
        {
            if (num[k]<result)
            {
                result = num[k];
            }


        }
        return result;

    }

}

int findMax (vector<int> &num)
{
    int l(num.size());
    if (l == 1)
    {
        return num[0];
    }
    else
    {
        int result(num[0]);
        for (int k=1; k<l; k++)
        {

            if (num[k]>result)
            {
                result = num[k];
            }

        }
        return result;
    }

}


int maximumGap(vector<int> &num)
{

    int l(num.size());
//    cout << "l == " << l << endl;

    if (l < 2)
    {
        return 0;
    }
    else if ((l==2))

    {
        int mini(findMin(num));
        int maxi(findMax(num));
        return maxi-mini;
    }

    else
    {
        int mini(findMin(num));
        int maxi(findMax(num));

        int maxDiff(maxi-mini);
        vector<vector<int> > vDiff(l);
//        cout << "here 1. " << endl;
        for (int k=0; k<l; k++)
        {
            vDiff[int((l-1)*(float(num[k]-mini)/float(maxi-mini)))].push_back(num[k]);
        }
//        cout << "here 2. " << endl;
        vector<int> eligibleDiff;
        int indexMaxi(0);
        int runningMaxi(findMax(vDiff[0]));
        int nextMini(0);
        int nextMaxi(0);

        int indexMini(1);
        while (indexMaxi < l-1)
        {

            while (indexMini < l)
            {
                if (vDiff[indexMini].empty())
                {
                    ++indexMini;
//                    cout << "here 3. " << endl;
                }
                else
                {
//                    cout << "here 4. " << endl;
//                    cout << "indexMini: " << indexMini << "; indexMaxi: " << indexMaxi << endl;
                    nextMini= findMin(vDiff[indexMini]);
                    nextMaxi= findMax(vDiff[indexMini]);
//                    cout << "nextMini: " << nextMini << "; runningMaxi: " << runningMaxi << endl;
                    eligibleDiff.push_back(nextMini-runningMaxi);
                    runningMaxi = nextMaxi;
                    indexMaxi = indexMini;

                    ++indexMini;

                }
            }

        }
//        cout << "size of eligibleDiff: " << eligibleDiff.size() << "value0: " << eligibleDiff[0]<< endl;
        int result(findMax(eligibleDiff));
        return result;



    }
}


int main()
{
    static const int arr[] = {5,6,9,7,12,36,5,12,45,8,54,22,26,38,25,47,31,2,7,9,8,29,49,51};
    vector<int> test(arr,arr + 24);
    vector<int> test2;
    test2.push_back(5);
    vector<int> test3;
    static const int arr4[] = {601408776,63967816,431363697,242509930,15970592,60284088,228037800,147629558,220782926,55455864,456541040,106650540,17290078,52153098,103139530,294196042,16568100,426864152,61916064,657788565,166159446,1741650,101791800,28206276,6223796,524849590,125389882,84399672,153834912,164568204,1866165,283209696,560993994,16266096,219635658,9188983,485969304,782013650,120332636,44659356,444517408,36369045,47370708,18542592,98802990,137690000,124889895,56062800,265421676,309417680,4634176,801661539,510541206,258227892,398938089,47255754,152260962,409663140,102847688,45756553,377936600,269498,375738702,263761134,53797945,329493948,224442208,508336845,189507850,40944620,127879560,119629476,186894520,62409156,693721503,4289916,523899936,28955240,266488028,20356650,40769391,483694272,97988044,84102,67246047,310688630,41288643,58965588,42881432,152159462,94786355,174917835,119224652,525034376,261516,274800528,62643819,23613832,8397240,797832131,855155367,337066320,26341480,61932200,20661075,515542796,390337500,522552030,43538516,150800550,116747540,152989123,488640056,700610304,233604,344277340,21439176,9397864,16365822,73027584,453041413,197374275,157735188,15273822,187081152,379611084,865005504,223099767,80478651,377729400,186738219,34738263,16634072,112791343,99631856,119364960,477106486,583953920,624509809,188442472,294181256,213023715,146645884,149530380,497592753,132170327,72770643,126683010,405141255,590214306,26670714,95582385,162080790,231120099,8946432,204967980,592849110,54120698,375915096,602145859,5346440,226337825,425156369,653591624,578483360,572410800,32290700,381384563,149939976,183225375,155695620,38307636,457513760,97085778,75200576,8068176,221650296,556889418,252495726,895020231,19932465,156334887,191383314,348432526,368701264,14315598,148936587,279419435,237325542,252587218,322929504,26331343,355297676,600420786,652017765,51673622,159015675};
    vector<int> test4(arr4,arr4 + 197);

    static const int arr5[] = {100,3,2,1};
    vector<int> test5(arr5, arr5 + 4);
//    for (int k=0;k<24;k++)
//    {
//      cout << test4[k]<< ", " << endl;
//    }
//    cout << endl;

    int answer(maximumGap(test5));
    cout << "checking length: " << sizeof(arr4)/sizeof(arr4[0]) << endl;
    cout << "The maximum gap is: " << answer << endl;
    return 0;
}
