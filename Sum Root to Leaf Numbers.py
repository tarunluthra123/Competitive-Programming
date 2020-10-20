# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def sumNumbers(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        self.ans = 0
        def rec(root,s):
            if not root:
                return
            if root.left==root.right:
                self.ans += int(s + str(root.val))
                return
            rec(root.left,s+str(root.val))
            rec(root.right,s+str(root.val))
        rec(root,"")
        return self.ans