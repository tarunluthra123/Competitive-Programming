# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next


class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        if not head or not head.next:
            return head
        first = head.next
        head.next = first.next
        first.next = head
        tmp = head
        while tmp.next and tmp.next.next:
            second = tmp.next.next
            prev = tmp.next
            tmp.next = second
            prev.next = second.next
            second.next = prev
            tmp = prev
        return first
