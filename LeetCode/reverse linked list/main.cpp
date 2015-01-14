#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void display(ListNode *n)
{
    if(!n)
        return;
    cout << n->val;
    n=n->next;
    while(n)
    {

        cout<<"->"<<n->val;
        n=n->next;
    }
    cout<< endl;
    return;
}



ListNode *reverseBetween(ListNode *head, int m, int n)
{
    if (m>=n)
        return head;
    ListNode *p1 = head;
    ListNode *p2 = head;
    ListNode *previous = NULL;
    for (int k=0; k<n-m; k++)
    {
        p1 = p1->next;
    }
    for (int k=n-m; k<n-1; k++)
    {
        previous = p2;
        p2=p2->next;
        p1=p1->next;
    }

    ListNode *newPrevious = p2->next;
    p2->next=p1->next;
    for (int k=0; k<n-m; k++)
    {
        ListNode *temp = newPrevious->next;
        newPrevious->next=p2;
        p2=newPrevious;
        newPrevious = temp;
    }
    if (m==1)
    {
        return p2;
    }
        previous->next = p2;
        return head;

}

int main()
{
    ListNode *n = new ListNode(3);
    n->next = new ListNode(5);
    display(n);
    ListNode *m=reverseBetween(n,1,2);
    display(m);

//    vector<int> v ;
//    v.insert(v.begin(),1);
//    cout << v.size() << endl;
//
//    vector<int> w(v.end(),v.end());
//    cout << w.size() << endl;
        cout << (-5%-2) << endl;
    return 0;
}
