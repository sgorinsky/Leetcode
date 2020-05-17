# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def oddEvenList(self, head: ListNode) -> ListNode:
        if not head:
            return None
        
        odds, evens, end = head, head.next if head else None, head.next

        while odds and odds.next:
            odds.next = odds.next.next if odds and odds.next else None
            evens.next = evens.next.next if evens and evens.next else None
            odds, evens = odds.next if odds.next else odds, evens.next
        
        odds.next = end
            
        return head
            
