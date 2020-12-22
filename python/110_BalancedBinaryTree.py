class Solution:
    def isBalanced(self, root: TreeNode) -> bool:
        def dfs(node, depth):
            nonlocal balanced
            if not node or not balanced:
                return depth
            
            left, right = dfs(node.left, depth + 1), dfs(node.right, depth + 1)
            if abs(left - right) > 1:
                balanced = False
            
            return max(left, right)
        
        balanced = True
        dfs(root, 0)
        return balanced
