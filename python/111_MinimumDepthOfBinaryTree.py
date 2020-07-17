# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    min_depth = float('inf')
    def minDepth(self, root: TreeNode) -> int:
        self.min_depth = float('inf')
        def helper(node, depth):
            if not node:
                return 0
            elif not (node.left or node.right):
                if depth < self.min_depth: self.min_depth = depth
                return self.min_depth
           
            helper(node.left, depth+1)
            helper(node.right, depth+1)
            
            return self.min_depth
        
        return helper(root, 1)
