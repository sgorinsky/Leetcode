class Solution {
    func reverseList(_ head: ListNode?) -> ListNode? {
        var curr: ListNode? = head, prev: ListNode? = nil
        while curr != nil && curr?.next != nil {
            var next = curr?.next
            curr?.next = prev
            prev = curr
            curr = next
        }
        curr?.next = prev
        return curr
    }
}

class Solution {
    func reverseList(_ head: ListNode?) -> ListNode? {
        if head == nil || head?.next == nil { return head }
        
        var newHead: ListNode? = reverseList(head?.next)
        head?.next?.next = head
        head?.next = nil
        
        return newHead
    }
}
