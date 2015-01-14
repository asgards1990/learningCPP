#include <iostream>
#include "include/Node.h"
#include <unordered_map>
#include <vector>

using namespace std;

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

void listDelete(Node *n)
{
    if (!n)
        return ;
    if (!(n->next))
    {
        n=NULL;
        return ;
    }
    n->val = n->next->val;
    n->next = n->next->next;
    return ;
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






//Stacks start here:
struct Stack
{
public:
    Node *top;
    Node *minimum;

    Stack(): top(NULL),minimum(NULL) {};

    Stack(int v): top(NULL),minimum(NULL)
    {
        top = new Node(v);
        minimum = top;
    };

//    this is a deep copy
    Stack(Node *n):top(NULL),minimum(NULL)
    {
        if (!n)
            return;
        Stack *s = new Stack(n->next);
        s->push(n->val);
        this->top = s->top;
        this->minimum = s->minimum;
    }
    int pop ()
    {
        if(top)
        {
            int output(top->val);
            if (output==minimum->val)
                minimum=minimum->next;
            top = top->next;
            return output;
        }

        return NULL;
    }
    void push(int v)
    {
        Node *temp = new Node(v);
        if(!top)
        {
            top = temp;
            minimum = temp;
            return;
        }
        if (v<=(minimum->val))
        {
            temp -> next = minimum;
            minimum = temp;
        }
        temp->next = top;
        top = temp;
    }

    int min()
    {
        return minimum->val;
    }



};

int stackDisplay(Stack *s)
{
    listDisplay(s->top);
}

struct SetOfStacks
{
public:
    SetOfStacks(int v):capacity(10),currentQuantity(1)
    {
        Node *n = new Node(v);
        tops.push_back(n);
    }
    int pop()
    {
        if (tops.empty())
            return NULL;
        int output(tops.back()->val);
        if (currentQuantity%capacity==1)
        {
            tops.pop_back();
        }
        else
        {
            tops.back() = tops.back()->next;
        }
        currentQuantity-=1;
        return output;

    }
    void push(int v)
    {
        Node *n = new Node(v);
        if (currentQuantity%capacity==0)
        {
            tops.push_back(n);
        }
        else
        {
            n->next = tops.back();;
            tops.back() = n;

        }
        currentQuantity+=1;
    }
    Node *getLastStack()
    {
        if (!tops.empty())
        {
            return tops.back();
        }
        return NULL;
    }
    int capacity;
    int currentQuantity;
    list<Node*> tops;


};

void displayHanoi(Stack *s1,Stack *s2,Stack *s3)
{
    int l1(s1->top->size()),l2(s2->top->size()),l3(s3->top->size());
    if(l1==0&&l2==0&&l3==0)
        return;
    if (l3>l2&&l3>l1)
        cout << "| " << "| " << s3->pop() << endl;
    else if (l1>l2&&l1>l3)
        cout << s1->pop() << " |" << "| " << endl;
    else if (l2>l1&&l3>l3)
        cout << "| "  << s2->pop() << " |" << endl;
    else if (l1==l2&&l1>l3)
        cout << s1->pop() <<" " << s2->pop() << "|" << endl;
    else if (l1==l3&&l1>l2)
        cout << s1->pop() <<" | " << s3->pop() << endl;
    else if (l2==l3&&l2>l1)
        cout <<"| " <<  s2->pop() << " " << s3->pop() << endl;
    else
        cout << s1->pop()  << " " << s2->pop()  << " "  << s3->pop() << endl;
    displayHanoi(s1,s2,s3);
    return;


}

vector<Stack*> Hanoi(int n,Stack *s1,Stack *s2,Stack *s3)
{
    if (n==0)
        return {s1,s2,s3};
    if (n==1)
    {
        int temp=s1->pop();
        s3->push(temp);
        return {s1,s2,s3};
    }
    else
    {
        displayHanoi(s1,s2,s3);
        vector<Stack*> v(Hanoi(n-1,s1,s3,s2));
        s1=v[0];
        s3=v[1];
        s2=v[2];
        displayHanoi(s1,s2,s3);
        v=Hanoi(1,s1,s2,s3);
        s1=v[0];
        s2=v[1];
        s3=v[2];
        displayHanoi(s1,s2,s3);
        v=Hanoi(n-1,s2,s1,s3);
        s2=v[0];
        s1=v[1];
        s3=v[2];
        displayHanoi(s1,s2,s3);
        return {s1,s2,s3};

    }


}

void solveHanoi(int n)
{
    if (n==0)
        return;
    Stack *s1 = new Stack(n);
    Stack *s2 = new Stack();
    Stack *s3 = new Stack();
    for (int k=n-1;k>0;k--)
    {
        s1->push(k);
    }
    Hanoi(n,s1,s2,s3);
    return;

}
int main()
{
    Node *x = new Node ({7,1,6,1});
    Node *y = new Node ({5,9,2});
    Node *z = new Node ({7,1,6,1});

    Stack *xs = new Stack(x);
    cout << "the xs stack is: ";
    stackDisplay(xs);
    Stack *ys = new Stack(y);
    cout << "the ys stack is: ";
    stackDisplay(ys);
    Stack *zs = new Stack(z);
    cout << "the zs stack is: ";
    stackDisplay(zs);
    cout << "the minimum of xs is: " << xs->min() << endl;
    cout << "the minimum of ys is: " << ys->min() << endl;
    cout << "the minimum of zs is: " << zs->min() << endl;

//    SetOfStacks *sos = new SetOfStacks(0);
//    for (int k=1; k<=37; k++)
//    {
//        sos->push(k);
//    }
//    cout << "the last stack is: ";
//    listDisplay(sos->getLastStack());
//    while(!sos->tops.empty())
//    {
//        cout << sos->pop() << endl;
//    }
solveHanoi(4);
    return 0;
}
