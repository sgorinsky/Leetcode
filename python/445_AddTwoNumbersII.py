# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        def helper(a, b):
            if not a.next and not b.next:
                total = a.val + b.val
                a.val = total % 10
                return total // 10
            
            carry = helper(a.next, b.next)
            total = a.val + b.val + carry
            
            a.val = total % 10
            return total // 10
        
        def get_length(head):
            curr = head
            l = 0
            while curr:
                curr = curr.next
                l += 1
            return l
        
        first_length = get_length(l1)
        second_length = get_length(l2)
        
        if second_length > first_length:
            for i in range(second_length - first_length):
                curr = ListNode(0)
                curr.next = l1
                l1 = curr
        else:
            for i in range(first_length - second_length):
                curr = ListNode(0)
                curr.next = l2
                l2 = curr
        
        carry = helper(l1, l2)
        if carry == 1:
            curr = ListNode(carry)
            curr.next = l1
            l1 = curr
        
        return l1
            
