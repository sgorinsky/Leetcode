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
    func sortList(_ head: ListNode?) -> ListNode? {
        // get initial length
        var length = 0
        var curr = head
        while curr != nil {
            curr = curr?.next
            length += 1
        }
        
        return splitAndMergeLists(head, length)
    }
    
    func splitAndMergeLists(_ head: ListNode?, _ length: Int) -> ListNode? {
            if head == nil || length == 1 { return head }
            var curr = head, prev: ListNode? = nil
            var half = length / 2, index = 0
            while curr != nil && index < half {
                prev = curr
                curr = curr?.next
                index += 1
            }

            if prev != nil { prev?.next = nil }
            var node = splitAndMergeLists(head, half)
            curr = splitAndMergeLists(curr, half % 2 == 1 ? half + 1 : half)
            return mergeTwoLists(node, curr)
        }
        
        func mergeTwoLists(_ smallerHead: ListNode?, _ biggerHead: ListNode?) -> ListNode? {
            if smallerHead == nil || biggerHead == nil { return smallerHead != nil ? smallerHead : biggerHead }
            else if smallerHead!.val > biggerHead!.val { return mergeTwoLists(biggerHead, smallerHead) }
            
            var smaller = smallerHead
            smaller?.next = mergeTwoLists(smaller?.next, biggerHead)
            return smaller
        }
}
