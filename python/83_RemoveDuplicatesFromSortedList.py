# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        if not head or not head.next:
            return head
        else:
            next_node = self.deleteDuplicates(head.next)
            if next_node.val == head.val:
                head.next = head.next.next
        return head
