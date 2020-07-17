class Solution:
    highest = 0
    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        def helper(node):
            if not node: return 0
            
            left = helper(node.left)
            right = helper(node.right)
            
            self.highest = max(self.highest, left+right)
            return max(left, right) + 1
        helper(root)
        return self.highest
