# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def recoverTree(self, root: TreeNode) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        self.first, self.second, self.prev = None, None, TreeNode(-(1<<32))
        self.inorder(root)
        self.first.val, self.second.val = self.second.val, self.first.val
        
        
    def inorder(self, root):
        if not root:
            return
        
        self.inorder(root.left)
        
        if (self.first is None) and (self.prev.val >= root.val):
            self.first = self.prev
        
        if (self.first) and (self.prev.val >= root.val):
            self.second = root
        
        self.prev = root
        
        self.inorder(root.right)