# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reorderList(self, head: ListNode) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        if not head:
            return
        
        slow, fast = head, head
        while fast and fast.next :
            slow, fast = slow.next, fast.next.next
        
        prev = None
        while slow:
            slow.next, slow, prev = prev, slow.next, slow
        
        left, right = head, prev
        while right.next:
            left.next, right.next, left, right = right, left.next, left.next, right.next
