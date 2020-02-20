# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def rotateRight(self, head: ListNode, k: int) -> ListNode:
        if not head:
            return head
        d = {}
        curr, length = head, 0
        while curr:
            d[length], length, curr = curr, length + 1, curr.next
        
        if k%length == 0:
            return head
        
        d[length-1].next, d[length-(k%length)-1].next = d[0], None
        return d[length-(k%length)]
