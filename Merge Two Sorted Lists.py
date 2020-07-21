# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next


class Solution:
    def mergeTwoLists(self, a: ListNode, b: ListNode) -> ListNode:
        if a is None or b is None:
            return a or b
        sortedList = None
        if a.val < b.val:
            sortedList = a
            a = a.next
        else:
            sortedList = b
            b = b.next
        t = sortedList
        while a is not None and b is not None:
            if a.val < b.val:
                t.next = a
                a = a.next
            else:
                t.next = b
                b = b.next
            t = t.next
        t.next = a or b
        return sortedList
