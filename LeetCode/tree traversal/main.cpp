#include <iostream>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> preorderTraversal(TreeNode *root)
{

    vector<TreeNode*> parentStack;
    vector<int> result;
    while (root or !parentStack.empty())
    {
        if (root)
        {
            result.push_back(root->val);
            if (root->right)
            {
                parentStack.push_back(root->right);
            }
            root = root->left;

        }
        else
        {
            root = parentStack.back();
            parentStack.pop_back();
        }

    }
    return result;

};



vector<int> preorderTraversalRec(TreeNode *root)
{
    vector<int> result;
    if (root)
    {
        result.push_back(root->val);
        if (root->left)
        {
            vector<int> lefties(preorderTraversal(root->left));
            result.insert(result.end(),lefties.begin(),lefties.end());
        }
        if (root->right)
        {
            vector<int> righties(preorderTraversal(root->right));
            result.insert(result.end(),righties.begin(),righties.end());
        }
    }
    return result;

};

vector<int> postorderTraversal(TreeNode *root)
{
    vector<TreeNode*> parentStack;
    vector<int> result;
    TreeNode* lastVisitedNode(0);
    TreeNode* parentNode(0);
    while (root or !parentStack.empty())
    {
        if (root)
        {
            parentStack.push_back(root);
            root = root->left;

        }
        else
        {
            parentNode = parentStack.back();
            if (parentNode->right and parentNode->right != lastVisitedNode)
            {
                root = parentNode->right;
            }
            else
            {
                result.push_back(parentNode->val);
                lastVisitedNode = parentNode;
                parentStack.pop_back();
            }
        }

    }
return result;
};

vector<int> postorderTraversalRec(TreeNode *root)
{
    vector<int> result;
    if (root)
    {
        if (root->left)
        {
            vector<int> lefties(postorderTraversal(root->left));
            result.insert(result.end(),lefties.begin(),lefties.end());
        }
        if (root->right)
        {
            vector<int> righties(postorderTraversal(root->right));
            result.insert(result.end(),righties.begin(),righties.end());
        }
        result.push_back(root->val);
    }
return result;
}


int main()
{
    TreeNode* test = new TreeNode(1);
    test->left = new TreeNode(2);
    test->right = new TreeNode(3);
    vector<int> elements(postorderTraversalRec(test));
    int l(elements.size());
    cout << "the size of the result is: " << l << endl;
    for (int k=0; k<l; k++)
    {
        cout << elements[k] << endl;
    }
    return 0;
}
