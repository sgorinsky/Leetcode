# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        
        self.paths = {}
        def helper(node, path):
            if not node:
                return node
            
            if node == p:
                self.paths[p.val] = path
            elif node == q:
                self.paths[q.val] = path
            
            if node.left:
                helper(node.left, path+'L')
            if node.right:
                helper(node.right, path+'R')
                
        helper(root, '')
        left_path, right_path = self.paths[p.val], self.paths[q.val]
        
        depth = 0
        shorter = left_path if len(left_path) < len(right_path) else right_path
        while depth < len(shorter) and left_path[depth] == right_path[depth]:
            depth += 1
        
        idx = 0
        while idx < depth:
            root = root.left if shorter[idx] == 'L' else root.right
            idx += 1
            
        return root
