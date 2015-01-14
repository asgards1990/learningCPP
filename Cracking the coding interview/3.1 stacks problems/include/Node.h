#ifndef NODE_H
#define NODE_H
#include <list>

class Node
{
public:
    Node(int val);
    Node(std::list<int> lis);
    Node(Node *n);
    virtual ~Node();
    void append(int v);
    int size();

    int val;
    Node *next;

protected:
private:
};

#endif // NODE_H
