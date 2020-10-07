class Solution {
    func rotateRight(_ head: ListNode?, _ k: Int) -> ListNode? {
        if head == nil || k == 0 { return head }
        var curr: ListNode? = head, prev: ListNode? = nil
        var length = 0
        
        while curr != nil {
            prev = curr
            curr = curr?.next
            length += 1
        }
        
        var shift = k % length
        if shift == 0 { return head }
        
        prev?.next = head
        curr = head
        while length - 1 > shift {
            curr = curr?.next
            length -= 1
        }
        
        var newHead = curr?.next
        curr?.next = nil
        return newHead
    }
}

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public var val: Int
 *     public var next: ListNode?
 *     public init() { self.val = 0; self.next = nil; }
 *     public init(_ val: Int) { self.val = val; self.next = nil; }
 *     public init(_ val: Int, _ next: ListNode?) { self.val = val; self.next = next; }
 * }
 */
class Solution {
    func rotateRight(_ head: ListNode?, _ k: Int) -> ListNode? {
        if head == nil || head?.next == nil || k == 0 { return head }
        
        var curr: ListNode? = head
        var length: Int = 0
        while curr != nil {
            curr = curr?.next
            length += 1
        }
        
        if k % length == 0 { return head }
        var newHeadIdx = length - k % length
        var newHead: ListNode?
        
        curr = head
        var i: Int = 0
        while i < length-1 {
            if i == newHeadIdx-1 {
                var temp: ListNode? = curr
                curr = curr?.next
                temp?.next = nil
                newHead = curr
                i += 1
                continue
            }
            curr = curr?.next
            i += 1
        }
        curr?.next = head
        return newHead
    }
}
