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
    func reorderList(_ head: ListNode?) {
        var nodes: Dictionary<Int, ListNode> = [Int: ListNode]()
        var curr = head
        var idx = 0
        
        while curr != nil {
            nodes[idx] = curr
            idx += 1
            curr = curr?.next
        }
        
        var start: Int = 0, end: Int = idx - 1
        while start <= end {
            nodes[start]?.next = start < end ? nodes[end]! : nil
            start += 1
            nodes[end]?.next = start < end ? nodes[start]! : nil
            end -= 1
        }
    }
}
