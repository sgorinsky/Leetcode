# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isCousins(self, root: TreeNode, x: int, y: int) -> bool:
        def findDepth(node, target, parent = float('inf'), depth = 0):
            if not node:
                return [parent, -1]
            elif node.val == target:
                return [parent, depth]
            
            right = findDepth(node.right, target, node.val, depth+1) if node.right else [parent, -1]
            left = findDepth(node.left, target, node.val, depth+1) if node.left else [parent, -1]
            
            return right if right[1] > left[1] else left
        
        X = findDepth(root, x)
        Y = findDepth(root, y)
        return X[1] == Y[1] if x == y or (X[1] != -1 and Y[1] != -1 and X[0] != Y[0]) else False
