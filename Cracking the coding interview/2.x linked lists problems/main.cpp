#include <iostream>
#include <list>
#include <array>
#include <vector>
#include <unordered_map>

using namespace std;

struct Node
{
public:
    Node(int v): val(v),next(NULL) {};
    Node(list<int> lis):val(0),next(NULL)
    {
        auto it = lis.begin();
        if (it!=lis.end())
            val=*it;
        it++;
        Node *n = this;
        while (it!=lis.end())
        {
            Node *child = new Node(*it);
            n->next = child;
            n = child;
            it++;
        }
    }
    Node(Node *n)
    {
        if (n)
            this->val = n->val;
        while (n->next)
        {
            Node *child = new Node(n->next->val);
            this->next=child;
            n = n->next;

        }

    }

    Node *next;
    int val;
    void append(int v)
    {
        Node *n = this;
        Node *child = new Node(v);
        while (n->next)
        {
            n = n->next;

        }
        n->next = child;
    }
    int size()
    {
        int l(0);
        Node *n = this;
        while (n)
        {
            l++;
            n = n->next;
        }
        return l;

    }

};
bool operator == (Node n, Node m)
{
    if (!n.next&&!m.next);
    else if (!n.next||!m.next)
        return false;
    else if (!(*n.next==*m.next))
        return false;
    return n.val==m.val;
}
void listDisplay(Node *n)
{
    if (n)
        cout << n->val;
    n = n->next;
    while (n)
    {
        cout << "->" << n->val;
        n=n->next;
    }
    cout << endl;
}
void listDisplay2(list<int> lis)
{
    auto it = lis.begin();
    cout << *it;
    it++;
    while (it!=lis.end())
    {
        cout << "->" << *it;
        it++;
    }
    cout << endl;
}

void removeDuplicates(Node *n)
{
    unordered_map<int,int> map;
    if (n)
        map[n->val]=1;
    while (n->next)
    {
        if (map.find(n->next->val)!=map.end())
        {
            n->next=n->next->next;

        }
        else
        {
            map[n->next->val]=1;
            n=n->next;
        }

    }

}

void removeDuplicates2(Node *n)
{
    unordered_map<int,int> map;
    Node *previous = NULL;
    while (n)
    {
        if (map.find(n->val)!=map.end())
        {
            previous->next=n->next;

        }
        else
        {
            map[n->val]=1;
            previous=n;

        }
        n=n->next;

    }

}

void removeDuplicatesWithoutBuffer(Node *n)
{
    Node *checkPoint=n;
    while(checkPoint)
    {
        Node *iter = checkPoint->next;
        Node *previous = checkPoint;
        while(iter)
        {
            if (iter->val==checkPoint->val)
            {
                previous->next=iter->next;
            }
            else
                previous=iter;
            iter = iter->next;
        }
        checkPoint = checkPoint->next;
    }
}

Node *fromKthElement(Node *n,int k)
{
    int counter(1);
    while (counter<k&&n)
    {
        counter++;
        n=n->next;
    }
    return n;

}

Node *lastKElements(Node *n, int k)
{
    if (k<=0)
        return NULL;
    int counter(0);
    Node *p1 = n;
    while (p1&&counter<k)
    {
        counter++;
        p1 = p1->next;
    }
    Node *p2 = n;
    while (p1)
    {
        p1 = p1->next;
        p2 = p2->next;
    }
    return p2;
}
void listDelete(Node *n)
{
    if (!n)
        return ;
    if (!(n->next))
    {
        *n=NULL;
        return ;
    }
    n->val = n->next->val;
    n->next = n->next->next;
    return ;
}

Node *partition(Node *n,int x)
{
    if (!n)
        return n;
    Node *head = NULL;
    Node *small = NULL;
    Node *big = NULL;
    while (n)
    {
        Node *temp = new Node(n->val);
        if (n->val<x)
        {
            head = temp;
            small = head;
            n = n->next;
            break;
        }
        else
        {

            temp->next =  big;
            big = temp;
            n = n->next;
        }


    }
    while (n)
    {
        Node *temp = new Node(n->val);
        if (n->val<x)
        {
            small->next = temp;
            small = temp;
        }
        else
        {

            temp->next =  big;
            big = temp;
        }
        n = n->next;
    }
    if (!head)
        return big;
    small->next = big;
    return head;

}

Node *partition2(Node *n, int x)
{
    Node *small =NULL;
    Node *headSmall=NULL;
    Node *big = NULL;
    Node *headBig = NULL;
    while (n)
    {
        Node *temp = new Node(n->val);
        if (n->val<x)
        {

            if (!headSmall)
            {

                headSmall = temp;
                small = temp;
            }
            else
            {
                small->next = temp;
                small = temp;
            }
        }
        else
        {
             if (!headBig)
            {

                headBig = temp;
                big = temp;
            }
            else
            {
                big->next = temp;
                big = temp;
            }
        }
        n=n->next;

    }
    if (!headSmall)
        return headBig;
    if (!headBig)
        return headSmall;
    small->next = headBig;
    return headSmall;

}
Node *add(Node *n,Node *m, int rest = 0)
{
    if (!n&&!m)
    {
        return NULL;

    }
    else if (!n)
        return add(m,n,rest);
    else
    {

        int sum(rest+n->val);
        bool isMNull(false);
        if (m)
            sum+=m->val;
        else
            isMNull = true;
        Node *temp = new Node(sum);
        if (sum>9)
        {
            temp->val -= 10;
            rest = 1;
        }
        else
            rest = 0;
        Node *next = NULL;
        if (isMNull)
            next = add(n->next,NULL,rest);
        else
            next = add(n->next,m->next,rest);
        temp->next = next;
        return temp;
    }
}

Node *headCircularList(Node *n)
{
    unordered_map<Node*,int> map;
    while (n)
    {
        if (map.find(n)!=map.end())
        {
            cout << "The starting value of the loop is: " << n->val << endl;
            return n;
        }
        map[n]=1;
        n = n->next;
    }
    cout << "The starting value of the loop is: " << n->val << endl;
    return n;
}

void displayCircularList(Node *n)
{
    if (!n)
        return ;
    cout << n->val;
    n= n->next;
    unordered_map<Node*,int> map;
    while (n)
    {
        if (map.find(n)!=map.end())
        {

            cout << "->" << n->val << endl;
            cout << "The above was a circular linked list." << endl;
            return ;

        }
        else
        {
            map[n]=1;
            cout << "->" << n->val;
            n=n->next;
        }
    }
    cout << endl;
    cout << "The above was not a circular linked list but a normal list." << endl;
    return;
}

Node *reverse(Node *n)
{
    if (!n||!(n->next))
        return n;
    Node * output = NULL;
    while(n)
    {
        Node *temp = new Node(n->val);
        n = n->next;
        temp->next = output;
        output = temp;
    }
    return output;
}

bool isPalindrome(Node *n1, Node* n2)
{
    if(!n1&&!n2)
        return true;
    if (!n1||!n2)
        return false;
    Node *n3 = reverse(n2);
    return *n3==*n1;
}

void displayTrueFalse(bool b)
{
    if (b)
        cout << "true";
    else
        cout << "false";
}
int main()
{
    int t[]= {1,2,3,5,6,9,8,7,4,1,2,6,5,3,2,5,6,9};


    list<int> lis {1,2,3,5,6,9,8,7,4,1,2,6,5,3,2,5,6,9,10};
    Node *n = new Node(lis);;
    listDisplay(n);
    removeDuplicatesWithoutBuffer(n);
    listDisplay(n);

    Node *m = fromKthElement(n,3);
    listDisplay(m);

    Node *afterPartition=partition(n,5);
    cout << "after fast partition: ";
    listDisplay(afterPartition);
    Node *afterPartition2=partition2(n,5);
    cout << "after faithful parition: ";
    listDisplay(afterPartition2);

    Node *afterDelete = n;
    afterDelete = afterDelete->next->next->next;
    listDelete(afterDelete);
    cout << "after deleting the 4th element which should be 5 here:";
    listDisplay(n);

    Node *x = new Node ({7,1,6,1});
    Node *y = new Node ({5,9,2});
    Node *z = new Node ({7,1,6,1});
    cout << "the list x is: ";
    listDisplay(x);
    cout << "the list y is: ";
    listDisplay(y);
    cout << "x+y = ";
    listDisplay(add(x,y));
    cout << "x==y?: ";
    displayTrueFalse(*x==*y);
    cout << endl;
    cout << "the list z is: ";
    listDisplay(z);
    cout << "x==z?: " ;
    displayTrueFalse(*x==*z);
    cout << endl;

    Node *test = NULL;
//        cout << "test null" << *test==*test << endl;


    Node *circular = new Node({1,2,3,4,5,6,7,8,9,10});
    Node *endNode = circular;
    for (int k=1; k<circular->size(); k++)
    {
        endNode = endNode->next;
    }
    endNode->next = circular->next->next->next;
    headCircularList(circular);
    displayCircularList(circular);
    displayCircularList(add(x,y));

    Node *n1 = reverse(n);
    cout << "the reverse of n is: ";
    listDisplay(n1);
    cout << "Are n and his reverse palindromes?...: ";
    displayTrueFalse(isPalindrome(n,n1));
    cout << endl;
    cout << "Are n and x palindromes?: ";
    displayTrueFalse(isPalindrome(n,x));
    cout << endl;

    Node *n2 = lastKElements(n1,3);
    cout << "the last 3 elements of the reverse of n is: ";
    listDisplay(n2);
    return 0;
}
