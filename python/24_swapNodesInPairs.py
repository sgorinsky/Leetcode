class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        if not head or not head.next: return head
        
        prev, curr = head, head.next
        head = head.next
        while prev and prev.next:
            after = curr.next
            prev.next, curr.next = after.next if after and after.next else after, prev
            curr, prev = prev.next, after
        
        return head

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        if not head or not head.next:
            return head
        current = head
        temp = head.next
        current.next = self.swapPairs(temp.next)
        temp.next = current
        return temp
