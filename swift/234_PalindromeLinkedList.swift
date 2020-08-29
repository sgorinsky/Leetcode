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
    var front: ListNode?
    func isPalindrome(_ head: ListNode?) -> Bool {
        front = head
        return checkRecursively(head)
    }
    
    func checkRecursively(_ curr: ListNode?) -> Bool {
        if curr != nil {
            if !checkRecursively(curr?.next) { return false }
            if curr?.val != front?.val { return false }
            front = front?.next
        }
        return true
    }
}
