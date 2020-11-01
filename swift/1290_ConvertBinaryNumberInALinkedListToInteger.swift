class Solution {
    func getDecimalValue(_ head: ListNode?) -> Int {
        var curr: ListNode? = head
        var n = 0
        while curr != nil {
            n <<= 1
            n += curr!.val
            curr = curr?.next
        }
        return n
    }
}
