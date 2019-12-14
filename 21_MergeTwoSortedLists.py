class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        if l1 == None and l2 == None:
            return None
        elif l1 == None:
            return l2
        elif l2 == None:
            return l1
        
            
        if l1.val > l2.val:
            head = ListNode(l2.val)
            l2 = l2.next
        else:
            head = ListNode(l1.val)
            l1 = l1.next
        head.next = None
        current = head
        
        while l1 != None or l2 != None:
            if l1 == None and l2 == None:
                current.next = None
            elif l1 == None:
                current.next = ListNode(l2.val)
                l2 = l2.next
            elif l2 == None:
                current.next = ListNode(l1.val)
                l1 = l1.next
            elif l1.val > l2.val:
                current.next = ListNode(l2.val)
                l2 = l2.next
            else:
                current.next = ListNode(l1.val)
                l1 = l1.next
            current = current.next
            
        return head


class Solution:
    # recursively traversing and merging l2 into l1
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        if l1 and l2:
            if l1.val > l2.val:
                l1, l2 = l2, l1
            l1.next = self.mergeTwoLists(l1.next, l2)
        return l1 or l2
