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
    func plusOne(_ node: ListNode?) -> ListNode? {
        var head: ListNode? = node
        var sentinel: ListNode? = ListNode(0)
        sentinel?.next = head
        var notNine: ListNode? = sentinel
        
        while head != nil {
            if head!.val != 9 {
                notNine = head
            }
            head = head?.next
        }
        
        notNine!.val += 1
        notNine = notNine?.next
        while notNine != nil {
            notNine!.val = 0
            notNine = notNine?.next
        }
        
        return sentinel!.val == 1 ? sentinel : sentinel?.next
    }
}
