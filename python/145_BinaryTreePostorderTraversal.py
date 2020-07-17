# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def postorderTraversal(self, root: TreeNode) -> List[int]:
        tree = []
        def closureTraversal(node):
            if not node:
                return tree
            if node.left:
                closureTraversal(node.left)
            if node.right:
                closureTraversal(node.right)
            tree.append(node.val)
            return tree
        return closureTraversal(root)
