class Solution:
    def swapNodes(self, head: ListNode, k: int) -> ListNode:
        curr = front = temp = head
        i = 1
        while curr:
            if i == k:
                temp = curr
            elif i > k:
                front = front.next
            curr = curr.next
            i += 1
        
        temp.val, front.val = front.val, temp.val
        return head
