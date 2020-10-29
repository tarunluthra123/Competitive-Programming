# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def isBalanced(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        def check(root):
            if not root:
                return 0,True
            l = check(root.left)
            r = check(root.right)
            h = max(l[0],r[0])+1
            balance = l[1] and r[1] and abs(l[0]-r[0])<=1
            return h,balance
        return check(root)[1]