# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrderBottom(self, root: TreeNode) -> List[List[int]]:
        if not root:
            return []
        levels = {}
        self.deepest_level = 0
        def traverseTree(node, lvl):
            if not node:
                return None
            self.deepest_level = max(self.deepest_level, lvl)
            levels[lvl] = levels[lvl] + [node.val] if lvl in levels else [node.val]
            
            return traverseTree(node.left, lvl+1) or traverseTree(node.right, lvl+1)
        
        traverseTree(root, 0)
        return [levels[lvl] for lvl in range(self.deepest_level,-1,-1)] 

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrderBottom(self, root: TreeNode) -> List[List[int]]:
        self.levels = 0
        def countLevels(node, level):
            if not node:
                return self.levels
            
            if level > self.levels:
                self.levels = level
            
            if node.left:
                countLevels(node.left, level+1)
            if node.right:
                countLevels(node.right, level+1)
            return self.levels
        
        deepest_level = countLevels(root, 1)
        res = [[] for _ in range(deepest_level)]
        
        def helper(node, level):
            if not node:
                return None
            
            res[len(res)-level] += [node.val]
            if node.left:
                helper(node.left, level+1)
            if node.right:
                helper(node.right, level+1)
                
            return res
            
        return helper(root, 1)
