class Solution:
    def inorderTraversal(self, node: TreeNode) -> List[int]:
        if not node:
            return []
        
        stack, res = [node], []
        visited = set()
        
        while stack:
            while node.left and node not in visited:
                stack.append(node.left)
                node = node.left
            
            node = stack.pop()
            visited.add(node)
            res.append(node.val)
            
            if node.right:
                stack.append(node.right)
                node = node.right

        return res

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
