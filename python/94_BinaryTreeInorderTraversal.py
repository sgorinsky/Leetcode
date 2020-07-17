# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def inorderTraversal(self, node: TreeNode) -> List[int]:
        tree = []
        def closureTraversal(root):
            if not root:
                return tree
            if root.left:
                closureTraversal(root.left)
            tree.append(root.val)
            if root.right:
                closureTraversal(root.right)
            return tree
        return closureTraversal(node)
