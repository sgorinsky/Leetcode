class Solution:
    def rangeSumBST(self, root: TreeNode, low: int, high: int) -> int:
        if not root: return 0
        
        return self.rangeSumBST(root.left, low, high) + self.rangeSumBST(root.right, low, high) + (root.val if root.val >= low and root.val <= high else 0)
