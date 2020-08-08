# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pathSum(self, root: TreeNode, target: int) -> int:
        self.count = 0
        h = {}
        def preorder(node, curr):
            if not node:
                return self.count
            
            curr += node.val
            if curr == target:
                self.count += 1
            
            if curr-target in h:
                self.count += h[curr-target]
            h[curr] = 1 if curr not in h else h[curr]+1
            
            preorder(node.left, curr)
            preorder(node.right, curr)
            
            h[curr] -= 1
            return self.count
        
        return preorder(root, 0)
