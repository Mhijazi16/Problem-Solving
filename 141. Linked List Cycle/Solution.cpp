
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
  bool hasCycle(ListNode *head) {
    ListNode* fast = head->next;
    ListNode* slow = head;

    while (fast != nullptr || fast->next != nullptr) {
      if (slow == fast)
        return true;

      slow = slow->next;
      fast = fast->next->next;
    }

    return false;
  }
};
