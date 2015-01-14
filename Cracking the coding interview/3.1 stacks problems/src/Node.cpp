#include "../include/Node.h"
#include <iostream>
using namespace std;
Node::Node(int v): val(v),next(NULL) {}

Node::Node(list<int> lis): val(0),next(NULL)
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
Node::Node(Node *n)
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


void Node::append(int v)
{
    Node *n = this;
    Node *child = new Node(v);
    while (n->next)
    {
        n = n->next;

    }
    n->next = child;
}
int Node::size()
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



Node::~Node()
{
    //dtor
}
