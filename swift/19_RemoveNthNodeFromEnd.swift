class Solution {
    func removeNthFromEnd(_ head: ListNode?, _ n: Int) -> ListNode? {
        var size: Int = 0
        var curr: ListNode? = head
        // get size
        while curr != nil {
            curr = curr?.next
            size += 1
        }
        
        if n >= size {
            return head?.next
        }
        
        curr = head
        var end: Int = size - n
        var prev: ListNode? = head
        
        while end > 0 {
            prev = curr
            curr = curr?.next
            end -= 1
        }
        
        prev?.next = curr?.next
        return head
        
    }
}
