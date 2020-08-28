class Solution {
    func reverseList(_ head: ListNode?) -> ListNode? {
        if head == nil || head?.next == nil { return head }
        
        var newHead: ListNode? = reverseList(head?.next)
        head?.next?.next = head
        head?.next = nil
        
        return newHead
    }
}
