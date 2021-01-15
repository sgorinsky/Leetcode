"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children if children is not None else []
"""

class Solution:
    def findRoot(self, tree: List['Node']) -> 'Node':
        p = 0
        for node in tree:
            p ^= node.val
            for child in node.children:
                p ^= child.val
        
        for node in tree:
            if p == node.val:
                return node
        
        return tree[0]
