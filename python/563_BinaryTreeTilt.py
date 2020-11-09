class Solution:
    def findTilt(self, root: TreeNode) -> int:
        def sumTree(node):
            if not node: return 0
            
            left = sumTree(node.left)
            right = sumTree(node.right)
            
            self.tilt += abs(left - right)
            
            return left + right + node.val
        
        self.tilt = 0
        sumTree(root)
        return self.tilt
