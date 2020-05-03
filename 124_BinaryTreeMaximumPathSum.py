# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxPathSum(self, root: TreeNode) -> int:
        self.high = -float('inf')
        def helper(node):
            if not node:
                return 0
            
            left = max(helper(node.left), 0)
            right = max(helper(node.right), 0)
            
            total = node.val + left + right
            if total > self.high: 
                self.high = total
            
            return max([right, left, 0]) + node.val
        
        helper(root)
        return self.high
