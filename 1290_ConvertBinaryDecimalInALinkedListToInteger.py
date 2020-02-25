# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getDecimalValue(self, head: ListNode) -> int:
        if not head: return 0
        
        node_vals = []
        while head:
            node_vals = [head.val] + node_vals
            head = head.next
        
        total = 0
        for i in range(len(node_vals)): total += ((2**i) * node_vals[i])
        
        return total
