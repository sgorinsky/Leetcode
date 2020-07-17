class Solution:
    count, forward = 0, 0
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        if not head:
            return head
        else:
            self.forward += 1
            self.removeNthFromEnd(head.next, n)
            self.count += 1
            if self.count == n+1:
                head.next = head.next.next if head.next else None
            elif n == self.forward:
                head = head.next
            return head
