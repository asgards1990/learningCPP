#include <iostream>

using namespace std;


struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};



ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    ListNode *pa = headA;
    ListNode *pb = headB;

//  So one of them is empty at the end
    while (pa && pb)
    {
        pa = pa->next;
        pb = pb->next;
    }

//    trimming A
    while(pa)
    {
        headA = headA->next;
        pa = pa->next;
    }
//    trimming B
    while(pb)
    {
        headB = headB->next;
        pb = pb->next;
    }
//    Now they have the same length
    while(headA && headA != headB)
    {
        headA = headA->next;
        headB = headB->next;
    }
    return headA;
}

int main()
{


    return 0;
}
