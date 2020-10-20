# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next


class Solution:
    def reorderList(self, head: ListNode) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        if not head:
            return
        arr = []
        tmp = head
        while tmp:
            arr += [tmp]
            tmp = tmp.next
        s, e = 0, len(arr)-1
        while s < e:
            arr[s].next = arr[e]
            s += 1
            arr[e].next = arr[s]
            e -= 1
        arr[s].next = None
