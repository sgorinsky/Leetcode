# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def zigzagLevelOrder(self, root: TreeNode) -> List[List[int]]:
        if not root: return []
        levels = {}
        self.deepestLevel = 0
        def traverseTree(node, lvl):
            if not node:
                return False
            
            if lvl > self.deepestLevel: self.deepestLevel = lvl
            
            levels[lvl] = [node.val] if lvl not in levels else levels[lvl] + [node.val]
            return traverseTree(node.left, lvl+1) or traverseTree(node.right, lvl+1)
        
        traverseTree(root, 0)
        return [levels[lvl] if lvl%2 == 0 else levels[lvl][::-1] for lvl in range(self.deepestLevel+1) ]
