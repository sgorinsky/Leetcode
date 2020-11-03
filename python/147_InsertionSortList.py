# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def insertionSortList(self, head: ListNode) -> ListNode:
        pseudo_head, curr = ListNode(), head
        while curr:
            prev_node, next_node = pseudo_head, pseudo_head.next
            while next_node:
                if curr.val < next_node.val:
                    break
                prev_node, next_node = next_node, next_node.next
            
            curr.next, prev_node.next, curr = next_node, curr, curr.next
        return pseudo_head.next
