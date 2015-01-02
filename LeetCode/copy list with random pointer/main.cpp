#include <iostream>
#include <utility>
#include <unordered_map>

using namespace std;
struct RandomListNode
{
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

RandomListNode *copyRandomList(RandomListNode *head)
{
    if (!head)
    {
        return NULL;
    }

    else
    {
        unordered_map<RandomListNode*,RandomListNode*> mapNodes;
        RandomListNode* resultNode = new RandomListNode(head->label);
        RandomListNode* runningNode = resultNode;
        for (RandomListNode* p=head; p; p=p->next)
        {

            mapNodes[p]=runningNode;

            if (p->next)
            {
                runningNode -> next = new RandomListNode (p->next->label);
                runningNode = runningNode->next;
            }


        }
        runningNode = resultNode;
        for (RandomListNode* p=head; p; p=p->next)
        {
            unordered_map<RandomListNode*,RandomListNode*>::iterator it = mapNodes.find(p->random);
            if (it!=mapNodes.end())
            {
                runningNode->random = it->second;
            }
            runningNode = runningNode -> next;
        }
        return resultNode;

    }

}
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
