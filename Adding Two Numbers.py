# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, a: ListNode, b: ListNode) -> ListNode:
        carry = 0
        ans = ListNode()
        tmp = ans

        while a != None and b != None:
            tmp.val = a.val + b.val + carry
            carry = tmp.val // 10
            tmp.val %= 10
            if a.next and b.next:
                tmp.next = ListNode()
                tmp = tmp.next
            a = a.next
            b = b.next

        node = a or b
        while carry > 0:
            if node:
                x = node.val
            else:
                x = 0
            tmp.next = ListNode(carry + x)
            tmp = tmp.next
            carry = tmp.val // 10
            tmp.val %= 10
            if node:
                node = node.next or None

        tmp.next = node

        return ans

