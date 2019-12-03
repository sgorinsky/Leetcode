class Solution:
    longest = 0
    def maxDepth(self, root: TreeNode) -> int:
        def traverse(tree, long):
            if not tree:
                return None
            if long > self.longest:
                self.longest = long
            if tree.left:
                traverse(tree.left, long+1)          
            if tree.right:
                traverse(tree.right, long+1)
