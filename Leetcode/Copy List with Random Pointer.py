"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""


class Solution:
    def copyRandomList(self, head: 'Node') -> 'Node':
        if not head:
            return None
        tmp = head
        while tmp:
            n = tmp.next
            tmp.next = Node(tmp.val, n)
            tmp = n
        tmp = head
        while tmp:
            if tmp.random:
                tmp.next.random = tmp.random.next
            tmp = tmp.next.next
        tmp = head
        res = head.next
        while tmp:
            t = tmp.next
            tmp.next = t.next
            tmp = tmp.next
            if tmp:
                t.next = tmp.next
        return res
