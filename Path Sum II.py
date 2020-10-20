# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


class Solution(object):
    def pathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: List[List[int]]
        """
        res = []

        def rec(root, sum, path):
            if not root:
                # print(path)
                return
            if sum == root.val and (not root.left) and (not root.right):
                res.append(path+[root.val])
                return
            rec(root.left, sum-root.val, path+[root.val])
            rec(root.right, sum-root.val, path+[root.val])

        rec(root, sum, [])
        return res
