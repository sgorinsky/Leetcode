# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def deepestLeavesSum(self, root: TreeNode) -> int:
        self.deepest = 0
        deepestLevel = self.findDeepestLevel(root, 1)
        def helper(node, level):
            if not node:
                return 0
            elif level == deepestLevel:
                return node.val
            
            return helper(node.left, level+1) + helper(node.right, level+1)
        
        return helper(root, 1)
    
    def findDeepestLevel(self, node, level):
        if level > self.deepest:
            self.deepest = level
        if node.left:
            self.findDeepestLevel(node.left, level+1)
        if node.right:
            self.findDeepestLevel(node.right, level+1)
            
        return self.deepest
    
