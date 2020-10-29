# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def minDepth(self, root):
        if not root:
            return 0
        def rec(root):
            if not root:
                return 1<<31
            if (not root.left) and (not root.right):
                return 1
            return min(rec(root.left),rec(root.right)) +1
        return rec(root)