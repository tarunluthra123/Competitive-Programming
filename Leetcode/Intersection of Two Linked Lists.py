# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        a, b, flag = headA, headB, False
        if not headA or not headB:
            return None
        while a != b:
            if a.next:
                a = a.next
            else:
                if not flag:
                    a = headB
                    flag = True
                else:
                    return None
            b = b.next if b.next else headA
        return a
