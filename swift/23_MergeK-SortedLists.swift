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
    func mergeKLists(_ lists: [ListNode?]) -> ListNode? {
        func mergeTwoLists(_ first: ListNode?, _ second: ListNode?) -> ListNode? {
            if first == nil || second == nil {
                return first == nil ? second : first
            } else if first!.val > second!.val {
                return mergeTwoLists(second, first)
            }
            
            first?.next = mergeTwoLists(first?.next, second)
            return first
        }
        
        func splitAndMergeLists(_ start: Int, _ end: Int) -> ListNode? {
            if start >= end {
                return lists[start]
            }
            
            var mid = start + (end - start) / 2
            var left = splitAndMergeLists(start, mid)
            var right = splitAndMergeLists(mid + 1, end)
            
            return mergeTwoLists(left, right)
        }
        
        if lists.isEmpty {
            return nil
        }
        
        return splitAndMergeLists(0, lists.count - 1)
    }
}
