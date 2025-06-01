
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {

    auto one = list1;
    ListNode *current = nullptr;

    while (one && list2) {
      if (one->val <= list2->val) {
        current = one;
        one = one->next;
      } else {
        current = list2;
        list2 = list2->next;
      }

      current = current->next;
    }

    while (one) {
      current = one;
      one = one->next;
      current = current->next;
    }

    while (list2) {
      current = list2;
      list2 = list2->next;
      current = current->next;
    }

    return list1;
  }
};
