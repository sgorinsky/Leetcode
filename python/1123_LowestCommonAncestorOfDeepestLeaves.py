class Solution:
    def lcaDeepestLeaves(self, root: TreeNode) -> TreeNode:
        def helper(node, depth):
            nonlocal max_depth, lca
            max_depth = max(depth, max_depth)
            
            if not node: return depth
            
            left, right = helper(node.left, depth + 1), helper(node.right, depth + 1)
            if left == right and left == max_depth: lca = node
            return max(left, right)
        
        max_depth, lca = 0, root
        helper(root, 0)
        return lca
