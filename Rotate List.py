# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def rotateRight(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        if not head or not head.next:
            return head

        pointer = head
        length = 1

        while pointer.next:
            pointer = pointer.next
            length += 1

        k = k%length

        if k == 0:
            return head

        fastPointer, slowPointer = head, head

        for i in range(k):
            fastPointer = fastPointer.next

        while fastPointer.next:
            slowPointer, fastPointer = slowPointer.next, fastPointer.next

        head, slowPointer.next, fastPointer.next = slowPointer.next, None, head

        return head