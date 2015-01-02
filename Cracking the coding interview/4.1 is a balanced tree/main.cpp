#include <iostream>
#include <utility>
#include <cmath>

using namespace std;

struct BinaryTreeNode
{
public:
    BinaryTreeNode(int v): val(v),left(NULL), right(NULL) {};
    int val;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
private:


};
pair<int,bool> isBalanced(BinaryTreeNode *n)
{
    if (!n)
    {
        return make_pair(0,true);
    }
    else
    {
        pair<int,bool> p1(isBalanced(n->left));
        pair<int,bool> p2(isBalanced(n->right));
        int height(max(p1.first,p2.first)+1);
//        cout << "value of the node: " << n->val << ", difference of height" << abs(p2.first-p1.first) << ", height==" << height << endl;
        if (p1.second&&p2.second&&abs(p2.first-p1.first)<=1)
        {
            return make_pair(height,true);
        }
        else
            return make_pair(height,false);
    }
}

int checkHeight(BinaryTreeNode *n)
{

    if (!n)
    {
        return 0;
    }

    int lH(checkHeight(n->left));
    if (lH==-1)
    {
        return -1;
    }

    int rH(checkHeight(n->right));
    if (rH==-1)
    {
        return -1;
    }

    int dH(abs(dH));
    if (dH>1)
    {
        return -1;
    }
    else
    {
        return max(lH,dH)+1;
    }
}

bool isBalanced2(BinaryTreeNode *n)
{
    int h(checkHeight(n));
    if (h==-1)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int main()
{
    BinaryTreeNode* test = new BinaryTreeNode(1);
    test->left = new BinaryTreeNode(2);
    test->right = new BinaryTreeNode(3);
    test->left->left = new BinaryTreeNode(4);
    test->left->right = new BinaryTreeNode(5);
    test->left->right->right = new BinaryTreeNode(6);
//
    pair<int,bool> p(isBalanced(test));
    cout << "height == " << p.first << ", isBalanced == " << p.second << endl;

    bool isB(isBalanced2(test));
    cout << "isBalanced==" << isB << endl;
    return 0;
}
