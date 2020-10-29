# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
from queue import PriorityQueue


class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        pq = PriorityQueue()
        for i in range(len(lists)):
            if lists[i]:
                pq.put((lists[i].val, i, lists[i]))

        res = ListNode()
        t = res
        while not pq.empty():
            u = pq.get()
            t.next = u[2]
            if u[2].next:
                pq.put((u[2].next.val, u[1], u[2].next))
            t = t.next
        res = res.next
        return res
