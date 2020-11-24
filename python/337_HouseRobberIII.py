# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rob(self, root: TreeNode) -> int:
        def helper(root, rob, not_rob):
            if not root: return [0, 0]
            
            left = helper(root.left, rob, not_rob)
            right = helper(root.right, rob, not_rob)
            
            rob = left[1] + right[1] + root.val
            not_rob = max(left[0], left[1]) + max(right[0], right[1])
            
            return [rob, not_rob]
        
        return max(helper(root, 0, 0))
