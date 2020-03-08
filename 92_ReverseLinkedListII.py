# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseBetween(self, head: ListNode, m: int, n: int) -> ListNode:
        curr, count, prev = head, 1, None
        
        while curr:
            if count == m:
                before, first = prev, curr
                while curr and m <= count <= n:
                    curr.next, prev, curr = prev, curr, curr.next
                    count += 1
                if before: before.next, first.next = prev, curr
                elif curr: head, first.next = prev, curr
                else: return prev
            if curr:
                count += 1
                prev, curr = curr, curr.next
        return head
            
