# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next


class Solution(object):
    def sortList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        def midPoint(head):
            slow = head
            fast = head.next
            while fast and fast.next:
                fast = fast.next.next
                slow = slow.next
            return slow

        def merge(a, b):
            if not a:
                return b
            if not b:
                return a
            if a.val < b.val:
                res = a
                res.next = merge(a.next, b)
            else:
                res = b
                res.next = merge(a, b.next)
            return res

        def mergeSort(head):
            if not head or not head.next:
                return head
            mid = midPoint(head)
            a = head
            b = mid.next
            mid.next = None
            a = mergeSort(a)
            b = mergeSort(b)
            return merge(a, b)

        return mergeSort(head)
