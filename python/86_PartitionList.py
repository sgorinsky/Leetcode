# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def partition(self, head: ListNode, x: int) -> ListNode:
        if not head:
            return None
        
        nodes_lt, idx_lt = {}, 0 # less than
        nodes_ge, idx_ge = {0: None}, 0 # greater than or equal
        
        curr = head
        while curr:
            if curr.val < x:
                nodes_lt[idx_lt] = curr
                idx_lt += 1
            else:
                nodes_ge[idx_ge] = curr
                idx_ge += 1
            
            curr = curr.next
        
        for i in range(1, idx_lt):
            nodes_lt[i-1].next = nodes_lt[i]
        if idx_lt > 0: nodes_lt[idx_lt-1].next = nodes_ge[0]
        
        for i in range(1, idx_ge):
            nodes_ge[i-1].next = nodes_ge[i]
        if idx_ge > 0: nodes_ge[idx_ge-1].next = None
        
        return nodes_lt[0] if idx_lt > 0 else nodes_ge[0]
