# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def countNodes(self, root: TreeNode) -> int:
        def traverse(node):
            if not node:
                return 0
            
            return 1 + traverse(node.left) + traverse(node.right)
        
        return traverse(root)

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def countNodes(self, root: TreeNode) -> int:
        self.count = 0
        def traverse(node):
            if not node:
                return node
            
            self.count += 1
            return traverse(node.left) or traverse(node.right)
        
        traverse(root)
        return self.count
