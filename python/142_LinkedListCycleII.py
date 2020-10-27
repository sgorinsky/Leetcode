# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def detectCycle(self, head: ListNode) -> ListNode:
        tortoise, hare = head, head
        while hare and hare.next:
            tortoise, hare = tortoise.next, hare.next.next
            if tortoise == hare: 
                break
        
        if not hare or not hare.next: 
            return None
        
        tortoise = head
        while hare and hare.next and tortoise != hare:
            tortoise, hare = tortoise.next, hare.next
        return hare
            
