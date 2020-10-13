# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def sortList(self, head: ListNode) -> ListNode:
        # find length of original list
        length, curr = 1, head
        while curr:
            length += 1
            curr = curr.next
        
        return self.split(head, length)
    
    def mergeSort(self, a, b):
        if not (a and b):
            return a or b
        elif a.val > b.val:
            return self.mergeSort(b, a);
        
        a.next = self.mergeSort(a.next, b)
        return a
            
    def split(self, head, length):
        half = length // 2
        right_half = half + half % 2
        if not (head and head.next) or half == 0: return head
        
        prev, curr, i = None, head, 0
        while curr and i < half:
            prev, curr = curr, curr.next
            i += 1
        
        if prev: prev.next = None
        head, curr = self.split(head, half), self.split(curr, right_half)
        return self.mergeSort(head, curr)
