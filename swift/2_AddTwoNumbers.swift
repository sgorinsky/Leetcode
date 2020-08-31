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
