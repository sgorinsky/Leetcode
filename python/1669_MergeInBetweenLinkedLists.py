# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeInBetween(self, list1: ListNode, a: int, b: int, list2: ListNode) -> ListNode:
        i = 1
        curr = list1
        while i < a:
            i += 1
            curr = curr.next
            
        temp = curr.next
        curr.next = list2
        head = list1 if a > 0 else list2
        
        while i < b:
            i += 1
            temp = temp.next
        
        second = list2
        while second.next:
            second = second.next
            
        second.next = temp.next
        return head
        
