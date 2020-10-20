# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def buildTree(self, inorder, postorder):
        """
        :type inorder: List[int]
        :type postorder: List[int]
        :rtype: TreeNode
        """
        map_inorder = {}
        for i, val in enumerate(inorder): 
            map_inorder[val] = i
            
        def build(low, high):
            if low > high: 
                return None
            x = TreeNode(postorder.pop())
            mid = map_inorder[x.val]
            x.right = build(mid+1, high)
            x.left = build(low, mid-1)
            return x
        
        return build(0, len(inorder)-1)