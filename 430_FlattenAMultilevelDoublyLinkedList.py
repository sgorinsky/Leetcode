"""
# Definition for a Node.
class Node:
    def __init__(self, val, prev, next, child):
        self.val = val
        self.prev = prev
        self.next = next
        self.child = child
"""

class Solution:
    def flatten(self, head: 'Node') -> 'Node':
        curr, prev = head, None
        while curr:
            if curr.child:
                temp, curr.next, curr.child = curr.next, self.flatten(curr.child), None
                curr.next.prev = curr
                while curr.next:
                    curr = curr.next
                curr.next = temp
                    
            curr, prev = curr.next, curr
            if curr:
                curr.prev = prev
                
        return head
    
