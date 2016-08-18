/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution
{
  public:
    int length(ListNode *p)
    {
        int a = 0;
        while (p != NULL)
        {
            a++;
            p = p->next;
        }
        return a;
    }
    ListNode *FindFirstCommonNode(ListNode *pHead1, ListNode *pHead2)
    {
        int l1 = length(pHead1);
        int l2 = length(pHead2);
        if (l1 > l2)
        {
            int l3 = l1 - l2;
            while (l3 != 0)
            {
                pHead1 = pHead1->next;
                l3--;
            }
            while (pHead1 != pHead2)
            {
                pHead1 = pHead1->next;
                pHead2 = pHead2->next;
            }

            return pHead1;
        }
        else
        {
            int l3 = l2 - l1;
            while (l3 != 0)
            {
                pHead2 = pHead2->next;
                l3--;
            }
            while (pHead1 != pHead2)
            {
                pHead1 = pHead1->next;
                pHead2 = pHead2->next;
            }

            return pHead1;
        }
    }
};