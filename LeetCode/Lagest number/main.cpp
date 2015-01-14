#include <iostream>
#include <vector>
using namespace std;

bool specialOrderBigger(int n,int m)
{
    if (n==0)
        return false;
    if (m==0)
        return true;
    if (n==m)
        return false;

    string stringNM(to_string(n)+to_string(m));
    string stringMN(to_string(m)+to_string(n));

    for (int indexString=0; indexString<stringNM.size(); indexString++)
    {
        if (stringNM[indexString]!=stringMN[indexString])
            return (stringNM[indexString]>stringMN[indexString]);

    }
    return false;
}

int quicksortPartition(vector<int> &num, int start,int end,int pivot)
{
    swap(num[end],num[pivot]);
    int finalPositionPivot(start);
    for (int i=start; i<end; i++)
    {
        if (specialOrderBigger(num[i],num[pivot]))
        {
            swap(num[i], num[finalPositionPivot]);
            finalPositionPivot++;

        }
    }
    swap(num[finalPositionPivot],num[end]);
    return finalPositionPivot;
}

void quicksortRec(vector<int>&num,int start,int end)
{
    if(start>=end)
        return;
    int pivot(quicksortPartition(num,start,end,end));
    quicksortRec(num,start,pivot-1);
    quicksortRec(num,pivot+1,end);
}
string concatenate(vector<int> &num)
{
    if (num[0]==0)
        return "0";
    string s("");
    for (int i=0; i<num.size(); i++)
    {
        s += to_string(num[i]);
    }

    return s;
}

string largestNumber(vector<int> &num)
{
    if (num.empty())
        return "0";

    quicksortRec(num,0,((num.size())-1));
    cout << "test" << endl;
    return concatenate(num);

}

 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };

ListNode *swapPairs(ListNode *head) {
        if (!head||!head->next)
        return head;

        ListNode *n(head->next);
        ListNode *p(n->next);
        ListNode *previous(head);
        n->next = previous;

        while(p&&(p->next))
        {
            previous ->next= p->next;
            p->next=p->next->next;
            previous->next->next=p;
            previous = p;
            p = p->next;

        }

        previous -> next = p;
        return n;
    }



int main()
{
    vector<int> t{0,9,8,7,6,5,4,3,2,1};
    cout << largestNumber(t) << endl;
    ListNode *n = new ListNode(1);
    n->next = new ListNode(2);
    ListNode *m = swapPairs(n);
    cout << m->val << endl;
    return 0;
}
