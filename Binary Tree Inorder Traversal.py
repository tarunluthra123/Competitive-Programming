# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        self.res = []
        self.inorder(root)
        return self.res
    
    def inorder(self, root):
        if not root:
            return
        self.inorder(root.left)
        self.res.append(root.val)
        self.inorder(root.right)