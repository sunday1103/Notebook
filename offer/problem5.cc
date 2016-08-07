/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
#include <stack>

class Solution {
 public:
  vector<int> printListFromTailToHead(struct ListNode* head) {
    std::vector<int> v;
    if (head == NULL) return v;
    std::stack<int> st;
    while (head->next != NULL) {
      st.push(head->val);
      head = head->next;
    }
    st.push(head->val);

    while (!st.empty()) {
      v.push_back(st.top());
      st.pop();
    }
    return v;
  }
};