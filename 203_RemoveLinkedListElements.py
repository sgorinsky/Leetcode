# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeElements(self, head: ListNode, val: int) -> ListNode:
        while head and head.val == val:
            head = head.next
        curr = head
        
        while curr and curr.next:
            next_node = curr.next
            while next_node and next_node.val == val: next_node = next_node.next
            curr.next = next_node
            curr = curr.next
            
        return head
