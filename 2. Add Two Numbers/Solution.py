from typing import Optional


class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution(object):
    def addTwoNumbers(
        self, l1: Optional[ListNode], l2: Optional[ListNode]
    ) -> Optional[ListNode]:
        carry = 0
        
        def recurse(one: Optional[ListNode], two: Optional[ListNode]):
            nonlocal carry

            if not one and not two and carry == 0:
                return None

            val1 = one.val if one else 0
            val2 = two.val if two else 0

            total = val1 + val2 + carry
            carry = total // 10

            node = ListNode(total % 10)
            node.next = recurse(one.next if one else None, two.next if two else None)
            return node

        return recurse(l1, l2)
