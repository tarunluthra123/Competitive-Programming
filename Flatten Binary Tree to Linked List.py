# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


class Solution:
    def flatten(self, root: TreeNode) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        def rec(root):
            if not root:
                return None, None
            if (not root.left) and (not root.right):
                return root, root
            if (not root.left):
                right = rec(root.right)
                root.right = right[0]
                return root, right[1]
            if (not root.right):
                left = rec(root.left)
                root.right = left[0]
                return root, left[1]
            left = rec(root.left)
            right = rec(root.right)
            root.right = left[0]
            left[1].right = right[0]
            return root, right[1]

        def nullify(root):
            while root:
                root.left = None
                root = root.right
        rec(root)
        nullify(root)
