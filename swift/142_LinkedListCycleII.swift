class Solution {
    func detectCycle(_ head: ListNode?) -> ListNode? {
        var slow: ListNode? = head, fast: ListNode? = head
        while fast != nil && fast?.next != nil {
            slow = slow?.next
            fast = fast?.next?.next
            if slow === fast {
                break
            }
        }
        
        if fast == nil || fast?.next == nil {
            return nil
        }
        
        slow = head
        while slow !== fast {
            slow = slow?.next
            fast = fast?.next
        }
        return slow
    }
}
