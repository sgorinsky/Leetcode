# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    hasPath = False
    def hasPathSum(self, tree: TreeNode, targetSum: int) -> bool:
        if not tree:
            return False
        self.hasPath = False
        def helper(root, current_sum):
            current_sum += root.val
            if not (root.left or root.right):
                if current_sum == targetSum:
                    self.hasPath = True
                return self.hasPath
            
            if root.left and not self.hasPath:
                helper(root.left, current_sum)
            if root.right and not self.hasPath:
                helper(root.right, current_sum)
            
            return self.hasPath
        return helper(tree, 0)
