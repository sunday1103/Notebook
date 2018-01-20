/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/

/* using stack o(n) space complixity
#include <algorithm>
#include <stack>

class Solution
{
  public:
    ListNode *ReverseList(ListNode *pHead)
    {
        if (pHead == NULL)
        {
            return NULL;
        }
        stack<ListNode *> st;
        for (; pHead != NULL; pHead = pHead->next)
        {
            st.push(pHead);
        }

        ListNode *p_re = st.top();
        st.pop();
        pHead = p_re;

        while (!st.empty())
        {
            pHead->next = st.top();
            st.pop();
            pHead = pHead->next;
        }
        pHead->next = NULL;

        return p_re;
    }
};


*/

/* using two pointor

class Solution
{
  public:
    ListNode *ReverseList(ListNode *pHead)
    {
        if (pHead == NULL)
        {
            return NULL;
        }
        ListNode *p = pHead;
        ListNode *pn = pHead->next;
        p->next = NULL;

        while (pn != NULL)
        {
            ListNode * temp = pn->next;
            pn->next = p;
            p = pn;
            pn = temp;
        }

        return p;
    }
};

*/ recursion

    class Solution
{
  public:
    ListNode *ReverseList(ListNode *pHead)
    {
        if (pHead == NULL)
        {
            return NULL;
        }

        if (pHead->next == NULL)
        {
            return pHead;
        }

        ListNode *re = ReverseList(pHead->next);
        pHead->next->next = pHead;
        pHead->next = NULL;

        return re;
    }
};
