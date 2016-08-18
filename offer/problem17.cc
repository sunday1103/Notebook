/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/

#include <algorithm>

/*
head -> 1|
*/

class Solution
{
  public:
    ListNode *Merge(ListNode *pHead1, ListNode *pHead2)
    {
        if (pHead1 == NULL)
        {
            return pHead2;
        }
        if (pHead2 == NULL)
        {
            return pHead1;
        }

        ListNode *pHead3;

        if (pHead1->val > pHead2->val)
        {
            pHead3 = pHead2;
            pHead2 = pHead2->next;
        }
        else
        {
            pHead3 = pHead1;
            pHead1 = pHead1->next;
        }

        ListNode *pTail3 = pHead3;

        while (1)
        {
            if (pHead1 == NULL)
            {
                pTail3->next = pHead2;
                return pHead3;
            }
            if (pHead2 == NULL)
            {
                pTail3->next = pHead1;
                return pHead3;
            }

            if (pHead1->val > pHead2->val)
            {
                pTail3->next = pHead2;
                pTail3 = pTail3->next;
                pHead2 = pHead2->next;
            }
            else
            {
                pTail3->next = pHead1;
                pTail3 = pTail3->next;
                pHead1 = pHead1->next;
            }
        }
    }
};