# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def partition(self, head: ListNode, x: int) -> ListNode:
        if not head:
            return head
        less, greater, tmp = None,None,head
        while tmp:
            if tmp.val < x:
                if less:
                    lessTmp.next = tmp
                    lessTmp = tmp
                else:
                    less = lessTmp = tmp
            else:
                if greater:
                    greaterTmp.next = tmp
                    greaterTmp = tmp
                else:
                    greater = greaterTmp = tmp
            tmp = tmp.next
        if less:
            lessTmp.next = greater
        if greater:
            greaterTmp.next = None
        return less or greater
        