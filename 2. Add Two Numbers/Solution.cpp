
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    int carry = 0; 
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      if (!l1 && !l2 && !carry) return nullptr;
      if (!l1 && l2) return l2;
      if (l1 && !l2) return l1;

      int val1 = l1? l1->val : 0; 
      int val2 = l2? l2->val : 0; 
      int value = val1 + val2 + carry; 

      ListNode* node = new ListNode(value % 10);
      carry = value / 10;

      node->next = addTwoNumbers(l1? l1->next : nullptr, l2? l2->next : nullptr);
      return node;
    }
};
