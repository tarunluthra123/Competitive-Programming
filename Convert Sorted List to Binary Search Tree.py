# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def sortedListToBST(self, head):
        """
        :type head: ListNode
        :rtype: TreeNode
        """
        d = {}
        c = 0
        while head:
            d[c] = head.val
            head,c = head.next,c+1
        
        def build(left,right):
            if left>right:
                return None
            mid = left+right>>1
            root = TreeNode(d[mid])
            root.left = build(left,mid-1)
            root.right = build(mid+1,right)
            return root
        
        return build(0,c-1)
            
        
        