# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def middleNode(self, head: ListNode) -> ListNode:
        nodes = {}
        curr, count = head, 0
        while curr:
            nodes[count], curr = curr, curr.next
            count += 1
        return nodes[count//2]
