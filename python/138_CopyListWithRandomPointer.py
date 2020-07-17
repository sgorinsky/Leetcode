"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""
class Solution:
    def copyRandomList(self, head: 'Node') -> 'Node':
        if not head:
            return None
        
        curr, nodes = head, {}
        while curr:
            nodes[curr] = Node(curr.val, None, None)
            curr = curr.next
        
        curr = head
        while curr:
            if curr.next != None:
                nodes[curr].next = nodes[curr.next]
            if curr.random != None:
                nodes[curr].random = nodes[curr.random]
            curr = curr.next
        return nodes[head]
        
        
