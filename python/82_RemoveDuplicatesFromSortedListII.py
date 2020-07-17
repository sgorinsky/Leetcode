# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        if not head:
            return head
         
        while self.is_duplicate_part(head):
            head = self.traverse_duplicate_part(head)
        
        current, prev = head, head
        while current:
            if self.is_duplicate_part(current):
                current = self.traverse_duplicate_part(current)
                prev.next = current
            else:
                current, prev = current.next, current
        return head
    
    def is_duplicate_part(self, head: ListNode) -> bool:
        if not head or not head.next:
            return False
        return head.val == head.next.val
    
    def traverse_duplicate_part(self, head: ListNode) -> ListNode:
        current = head.next
        while current and head.val == current.val:
            current = current.next
        return current
