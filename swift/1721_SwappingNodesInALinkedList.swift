class Solution {
    func swapNodes(_ head: ListNode?, _ k: Int) -> ListNode? {
        var front = head, end = head, curr = head
        var i = 1
        while curr != nil {
            if i == k {
                front = curr
            } else if i > k {
                end = end?.next
            }
            i += 1
            curr = curr?.next
        }
        
        var tempVal = front!.val
        front!.val = end!.val
        end!.val = tempVal
        
        return head
    }
}
