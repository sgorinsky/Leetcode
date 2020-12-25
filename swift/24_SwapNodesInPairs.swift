class Solution {
    func swapPairs(_ head: ListNode?) -> ListNode? {
        if head == nil || head?.next == nil { return head }
        
        var prev: ListNode? = head
        var curr: ListNode? = head?.next
        
        prev?.next = swapPairs(curr?.next)
        curr?.next = prev
        
        return curr
    }
}
