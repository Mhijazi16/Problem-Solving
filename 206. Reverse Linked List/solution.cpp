
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *prev = nullptr;
  ListNode *reverseList(ListNode *head) {
    if (head == nullptr)
      return head;

    if (head->next == nullptr) {
      head->next = prev;
      return head;
    }

    ListNode *next = head->next;
    head->next = prev;
    prev = head;
    return reverseList(next);
  }
};
