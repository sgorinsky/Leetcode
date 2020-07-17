# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def widthOfBinaryTree(self, root: TreeNode) -> int:
        if not root:
            return 0
        levels, self.greatest_width = {}, 1
        def traverseTree(node, level, place):
            if not node:
                return self.greatest_width
            
            if level in levels:
                levels[level] = [min(levels[level][0], place), max(levels[level][1], place)]
            else:
                levels[level] = [place, place]
            
            self.greatest_width = max(abs(levels[level][1] - levels[level][0])+1, self.greatest_width)
            
            if node.left:
                traverseTree(node.left, level+1, place*2-1)
            
            if node.right:
                traverseTree(node.right, level+1, place*2)
            
            return self.greatest_width
        
        return traverseTree(root, 0, 1)
