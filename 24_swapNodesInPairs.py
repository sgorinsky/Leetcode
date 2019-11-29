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
