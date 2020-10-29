# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


class Solution:
    def preorderTraversal(self, root: TreeNode) -> List[int]:
        self.res = []

        def rec(root):
            if not root:
                return
            self.res += [root.val]
            rec(root.left)
            rec(root.right)
        rec(root)
        return self.res
