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
    func mergeInBetween(_ list1: ListNode?, _ a: Int, _ b: Int, _ list2: ListNode?) -> ListNode? {
        var idx = 1
        var curr = list1
        
        while idx < a {
            curr = curr?.next
            idx += 1
        }
        
        var temp = curr?.next
        var head = list1
        if a > 0 { curr?.next = list2 }
        else { head = list2 }
        
        while idx < b {
            temp = temp?.next
            idx += 1
        }
        
        var second = list2
        while second?.next != nil {
            second = second?.next
        }
        
        second?.next = temp?.next
        return head
    }
}
