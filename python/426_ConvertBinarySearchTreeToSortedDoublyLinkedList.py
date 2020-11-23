"""
# Definition for a Node.
class Node:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
"""

class Solution:
    def treeToDoublyList(self, root: 'Node') -> 'Node':
        if not root: return None
        def helper(node):
            if not node: return 
            
            helper(node.left)
            nodes.append(node)
            helper(node.right)
        
        nodes = []
        helper(root)
        for i, node in enumerate(nodes):
            node.left = nodes[(i - 1) % len(nodes)]
            node.right = nodes[(i + 1) % len(nodes)]
        
        return nodes[0]
        
