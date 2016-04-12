/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
  public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        bool flag_l1 = false;
        bool flag_l2 = false;
        int jinwei = 0;
        int val = 0;
        val = (l1->val + l2->val + jinwei) % 10;
        jinwei = (l1->val + l2->val + jinwei) / 10;
        ListNode *l3 = new ListNode(val);
        ListNode *l3_return = l3;
        l1 = l1->next;
        l2 = l2->next;
        while (l1 != NULL || l2 != NULL)
        {
            if (l1 == NULL)
            {
                flag_l1 = true;
            }
            if (l2 == NULL)
            {
                flag_l2 = true;
            }
            int val_l1;
            int val_l2;
            if (flag_l1)
            {
                val_l1 = 0;
                val_l2 = l2->val;
            }
            else if (flag_l2)
            {
                val_l2 = 0;
                val_l1 = l1->val;
            }
            else
            {
                val_l1 = l1->val;
                val_l2 = l2->val;
            }
            val = (l1->val + l2->val + jinwei) % 10;
            jinwei = (l1->val + l2->val + jinwei) / 10;
            l3->next = new ListNode(val);
            l3 = l3->next;
            if (flag_l1)
            {
                l2 = l2->next;
            }
            else if (flag_l2)
            {
                l1 = l1->next;
            }
            else
            {
                l1 = l1->next;
                l2 = l2->next;
            }
        }
        if (jinwei == 1)
        {
            l3->next = new ListNode(1);
        }
        return l3_return;
    }
};
