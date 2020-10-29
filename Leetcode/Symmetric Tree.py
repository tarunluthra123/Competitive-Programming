# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        
        def isMirror(left,right):
            if (left is None) or (right is None):
                return left is right
            if left.val == right.val:
              outPair = isMirror(left.left, right.right)
              inPair = isMirror(left.right, right.left)
              return outPair and inPair
            return False
            
            
        if not root:
            return True
        return isMirror(root.left, root.right)