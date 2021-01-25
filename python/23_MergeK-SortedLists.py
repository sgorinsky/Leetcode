# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        def merge(a, b):
            if not (a and b):
                return a or b
            elif a.val > b.val:
                return merge(b, a)
            
            a.next = merge(a.next, b)
            return a
        
        def split_merge(start, end):
            if start >= end:
                return lists[start]
            
            mid = start + (end - start) // 2
            left, right = split_merge(start, mid), split_merge(mid + 1, end)
            
            return merge(left, right)
        
        if not lists:
            return None
        
        return split_merge(0, len(lists) - 1)
