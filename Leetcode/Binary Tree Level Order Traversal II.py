# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
import Queue
class Solution(object):
    def levelOrderBottom(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        if not root:
            return []
        q = Queue.Queue()
        q.put(root)
        q.put(None)
        res,p = [],[]
        while not q.empty():
            t = q.get()
            if not t:
                if not q.empty():
                    q.put(None)
                res.append(p)
                p = []
            else:
                p.append(t.val)
                if t.left:
                    q.put(t.left)
                if t.right:
                    q.put(t.right)
                
            q.task_done()
        res.reverse()
        return res