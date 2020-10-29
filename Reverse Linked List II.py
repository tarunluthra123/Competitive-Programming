# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseBetween(self, head: ListNode, m: int, n: int) -> ListNode:
        dummy = pre = ListNode(0,head)
        for i in range(m-1):
            pre = pre.next
        curr = pre.next
        after = curr.next
        
        for i in range(n-m):
            curr.next = after.next
            after.next = pre.next
            pre.next = after
            after = curr.next
        
        return dummy.next
            
        
        