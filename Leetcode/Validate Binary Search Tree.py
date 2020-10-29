# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidBST(self, root: TreeNode, minVal = -(1<<32), maxVal = (1<<32)) -> bool:
        if not root:
            return True
        return (minVal < root.val < maxVal) and self.isValidBST(root.left, minVal, root.val) and self.isValidBST(root.right, root.val, maxVal)
        