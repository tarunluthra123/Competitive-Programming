# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        if not head:
            return head
        tmp,t = head,head.next
        while t:
            while t and t.val==tmp.val:
                t = t.next
            tmp.next = t
            tmp = t
        return head
            
            
        