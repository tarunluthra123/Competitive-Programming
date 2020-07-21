# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next


class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        prev = None
        curr = head
        while curr:
            n = curr.next
            curr.next = prev
            prev = curr
            curr = n
        return prev

    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        if not head:
            return head
        i = 0
        tmp = head
        while i < k - 1 and tmp.next:
            tmp = tmp.next
            i += 1
        rem = tmp.next
        if tmp.next is None and i < k-1:
            return head
        tmp.next = None
        rem = self.reverseKGroup(rem, k)
        head = self.reverseList(head)
        tmp = head
        while tmp.next:
            tmp = tmp.next
        tmp.next = rem
        return head
