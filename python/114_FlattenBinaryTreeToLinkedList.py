# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def flatten(self, root: TreeNode) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        if not root:
            return None
        if not root.left and not root.right:
            return root
        
        left, right = self.flatten(root.left), self.flatten(root.right)
        
        if left:
            left.right = root.right
            root.left, root.right = None, root.left
        
        return right if right else left

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def flatten(self, root: TreeNode) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        if not root:
            return None
        
        left = self.flatten(root.left) if root.left else None
        right = self.flatten(root.right) if root.right else None
        if left:
            root.left, root.right = None, left
            curr = left
            while curr.right:
                curr = curr.right
            curr.right = right
            
        return root
