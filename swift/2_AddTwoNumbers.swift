class Solution {
    func addTwoNumbers(_ l1: ListNode?, _ l2: ListNode?) -> ListNode? {
        var firstList = l1, secondList = l2
        var head = l1, curr = l1, prev = l1
        var remainder = 0
        while firstList != nil || secondList != nil {
            var sum = remainder
            if firstList != nil {
                sum += firstList!.val
                firstList = firstList?.next
            }
            if secondList != nil {
                sum += secondList!.val
                secondList = secondList?.next
            }
            curr!.val = sum % 10
            remainder = sum / 10
            curr?.next = firstList != nil ? firstList : secondList
            prev = curr
            curr = curr?.next
        }
        prev?.next = remainder == 1 ? ListNode(1) : nil
        return head
    }
}

class Solution {
    func addTwoNumbers(_ l1: ListNode?, _ l2: ListNode?) -> ListNode? {
        return addNodes(l1, l2, false)
    }
    
    func addNodes(_ l1: ListNode?, _ l2: ListNode?, _ carry: Bool) -> ListNode? {
        if l1 == nil && l2 == nil {
            return carry ? ListNode(1) : nil;
        } else if l1 == nil {
            return addNodes(l2, l1, carry)
        }
        
        var sum: Int = (l1?.val ?? 0) + (l2?.val ?? 0) + (carry ? 1 : 0)
        l1?.val = sum % 10
        l1?.next = addNodes(l1?.next, l2?.next, sum >= 10)
        return l1
    }
}
