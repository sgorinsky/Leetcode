class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        head = curr = prev = l1
        remainder = 0
        while l1 or l2:
            total = remainder
            if l1:
                total += l1.val
                l1 = l1.next
            if l2:
                total += l2.val
                l2 = l2.next
            remainder, curr.val = total // 10, total % 10
            curr.next, prev = l1 if l1 else l2, curr
            curr = curr.next
        prev.next = ListNode(1) if remainder else None
        return head

class ListNode:
	def __init__(self,x):
		self.val = x
		self.next = None

def addTwoNumbers(l1: ListNode, l2: ListNode) -> ListNode:
        s1 = ''
        s2 = ''
        while l1 != None:
            s1 = str(l1.val) + s1
            l1 = l1.next
        
        while l2 != None:
            s2 = str(l2.val) + s2
            l2 = l2.next
        
        if s1 == '':
            s1 += '0'
        if s2 == '':
            s2 += '0'
        both = str(int(s1) + int(s2))
        
        length = len(both)
        start = ListNode(None)
        current = ListNode(int(both[-1]))
        start.next = current
        start = start.next
        
        for i in range(-2, -length-1, -1):
            current.next = ListNode(int(both[i]))
            current = current.next
        return start
