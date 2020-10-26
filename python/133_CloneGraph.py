"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

class Solution:
    def cloneGraph(self, node: 'Node') -> 'Node':
        if not node: return node
        
        clone = Node(node.val)
        node_stack, clone_stack = [node], [clone]
        clone_map = {node: clone}
        
        while node_stack:
            curr_node = node_stack.pop()
            curr_clone = clone_stack.pop()
            for nei in curr_node.neighbors:
                if nei not in clone_map:
                    nei_clone = Node(nei.val)
                    clone_map[nei] = nei_clone
                    node_stack.append(nei)
                    clone_stack.append(nei_clone)
                curr_clone.neighbors.append(clone_map[nei])
        return clone
