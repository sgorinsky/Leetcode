class Solution:
    def countUnivalSubtrees(self, root: TreeNode) -> int:
        self.count = 0
        
        def helper(node):
            if not node:
                return True
            elif not node.left and not node.right:
                self.count += 1
                return True
            
            left, right = helper(node.left), helper(node.right)
            if left and right:
                if not node.left or not node.right:
                    if (node.left and node.left.val == node.val) or (node.right and node.right.val == node.val):
                        self.count += 1
                        return True
                    return False
                else:
                    if node.left.val == node.right.val == node.val:
                        self.count += 1
                        return True
            return False
        
        helper(root)
        return self.count
