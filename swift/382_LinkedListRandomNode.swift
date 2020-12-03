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

    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    let head: ListNode?
    init(_ head: ListNode?) {
        self.head = head;
    }
    
    /** Returns a random node's value. */
    func getRandom() -> Int {
        var n = 1.0
        var curr = head, ans = head
        while curr != nil {
            if Double.random(in: 0...1) < 1.0 / n {
                ans = curr
            }
            n += 1
            curr = curr?.next
        }
        return ans!.val
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * let obj = Solution(head)
 * let ret_1: Int = obj.getRandom()
 */
