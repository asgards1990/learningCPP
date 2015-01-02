#include <iostream>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class BSTIterator
{
public:
    TreeNode *currentNode;
    BSTIterator(TreeNode *root): currentNode(root)
    {
        if (!root||!(root->right))
        {
            nextNode=NULL;
        }
        else
        {
            nextNode = findMin(root->right);

        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext()
    {
        if (!nextNode)
        {
            return true;
        }
        else
        {
            return false;
        }

    }

    /** @return the next smallest number */
    int next()
    {
        if (!nextNode)
        {
            return currentNode->val;
        }
        else
        {
            return nextNode->val;
        }
    }
private:

    TreeNode* nextNode;
    TreeNode* findMin(TreeNode *n)
    {
        if (!n||!(n->left))
        {
            return n;
        }
        return findMin(n->left);

    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
