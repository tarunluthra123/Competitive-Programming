# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
import queue
class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        if not root:
            return []
        res = []
        q = queue.Queue()
        q.put(root)
        q.put(None)
        p = []
        while not q.empty():
            t = q.get()
            if t is None:
                res.append(p)
                p = []
                if not q.empty():
                    q.put(None)
                q.task_done()
                continue
            p += [t.val]
            if t.left:
                q.put(t.left)
            if t.right:
                q.put(t.right)
            q.task_done()
        return res