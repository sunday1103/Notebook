/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution
{
  public:
    RandomListNode *Clone(RandomListNode *pHead)
    {
        if (pHead == NULL)
        {
            return NULL;
        }

        RandomListNode *cp = new RandomListNode(pHead->label);

        RandomListNode *head_temp = pHead;
        RandomListNode *cp_temp = cp;

        map<RandomListNode *, RandomListNode *> mymap;
        mymap[pHead] = cp;

        while (head_temp->next != NULL)
        {
            cp_temp->next = new RandomListNode(head_temp->next->label);
            head_temp = head_temp->next;
            cp_temp = cp_temp->next;
            mymap[head_temp] = cp_temp;
        }

        head_temp = pHead;
        cp_temp = cp;

        while (head_temp != NULL)
        {
            if (head_temp->random != NULL)
            {
                cp_temp->random = mymap[head_temp->random];
            }
            head_temp = head_temp->next;
            cp_temp = cp_temp->next;
        }

        return cp;
    }
};