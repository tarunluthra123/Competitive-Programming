# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def binaryTreePaths(self, root):
        """
        :type root: TreeNode
        :rtype: List[str]
        """
        res = []

        def rec(root,l=[]):
            if not root:
                return
            if root.left == root.right:
                res.append(l+[str(root.val)])
                return
            rec(root.left,l+[str(root.val)])
            rec(root.right,l+[str(root.val)])

        rec(root)
        for i in range(len(res)):
            res[i] = "->".join(res[i])

        return res
