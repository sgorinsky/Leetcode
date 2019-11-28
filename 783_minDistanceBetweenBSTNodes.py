# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    smallest = 1000000
    prior = -100000
    def minDiffInBST(self, root: TreeNode) -> int:
        if root.left:
            self.minDiffInBST(root.left)
        current_diff = root.val-self.prior
        if self.smallest > current_diff:
            self.smallest = current_diff
        self.prior = root.val
        if root.right:
            self.minDiffInBST(root.right)
        return self.smallest
