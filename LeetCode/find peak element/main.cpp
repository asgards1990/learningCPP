#include <iostream>
#include <vector>

using namespace std;

int findPeakElement(const vector<int> &num) {
        int l(num.size());
        if (l==1)
        {
            return 0;
        }
        else
        {
            int previousElement(num[0]-1);
            int currentElement(num[0]);
            int nextElement(num[1]);
            for (int k=0;k<l-1;k++)
            {
                nextElement = num[k+1];
                if ((currentElement>previousElement)&&(nextElement<currentElement))
                {
                    return k;
                }
                else
                {
                    previousElement = currentElement;
                    currentElement = nextElement;

                }

                }
                return l-1;
                }
            }
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
