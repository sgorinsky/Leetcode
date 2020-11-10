# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    
    def maxAncestorDiff(self, root: TreeNode) -> int:
        def helper(node, low, high):
            if not node:
                return high - low
            low, high = min(low, node.val) , max(high, node.val)
            return max(helper(node.left, low, high), helper(node.right, low, high))
        return helper(root, float('inf'), float('-inf'))
