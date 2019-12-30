# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    isTrue = True
    def isSameTree(self, p: TreeNode, q: TreeNode) -> bool:
        if not p and not q:
            return True
        elif not p or not q:
            return False
        
        if p.val != q.val:
            return False
        
        if p.left or q.left and self.isTrue:
            self.isTrue = self.isSameTree(p.left, q.left)
        
        if p.right or q.right and self.isTrue:
            self.isTrue = self.isSameTree(p.right, q.right)
            
        return self.isTrue
