# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    
    def closestValue(self, root: TreeNode, target: float) -> int:
        self.distance = [float('inf'), 0]
        def search(node):
            if not node: 
                return self.distance[1]
            
            if abs(target-node.val) < self.distance[0]:
                self.distance[0] = abs(target-node.val)
                self.distance[1] = node.val
            if target > node.val:
                return search(node.right)
            else:
                return search(node.left)
            
        return search(root)
