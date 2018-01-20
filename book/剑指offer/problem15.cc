/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/

/*
#include <algorithm>
#include <vector>

class Solution
{
  public:
    ListNode *FindKthToTail(ListNode *pListHead, unsigned int k)
    {
        if (pListHead == NULL)
        {
            return NULL;
        }
        vector<ListNode *> v;
        ListNode *lp = pListHead;
        for (; lp != NULL; lp = lp->next)
        {
            v.push_back(lp);
        }

        int s = v.size();
        if (k > s)
        {
            return NULL;
        }
        else
        {
            return v[s - k];
        }
    }
};

*/

class Solution
{
  public:
    ListNode *FindKthToTail(ListNode *pListHead, unsigned int k)
    {
        if (pListHead == NULL)
        {
            return NULL;
        }
        ListNode *p1 = pListHead;
        ListNode *p2 = pListHead;

        k--;
        while (k)
        {
            p2 = p2->next;
            k--;
            if (p2 == NULL)
            {
                return NULL;
            }
        }

        while (p2->next != NULL)
        {
            p1 = p1->next;
            p2 = p2->next;
        }
        return p1;
    }
};