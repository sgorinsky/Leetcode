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
