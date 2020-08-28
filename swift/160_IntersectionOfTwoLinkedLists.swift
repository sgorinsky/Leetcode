/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public var val: Int
 *     public var next: ListNode?
 *     public init(_ val: Int) {
 *         self.val = val
 *         self.next = nil
 *     }
 * }
 */

class Solution {
    func getIntersectionNode(_ headA: ListNode?, _ headB: ListNode?) -> ListNode? {
        var currA: ListNode? = headA, currB: ListNode? = headB
        var sizeA: Int = 0, sizeB: Int = 0
        
        while currA != nil || currB != nil {
            if currA != nil {
                currA = currA?.next
                sizeA += 1
            }
            if currB != nil {
                currB = currB?.next
                sizeB += 1
            }
        }
        
        currA = headA
        currB = headB
        for _ in 0..<abs(sizeA-sizeB) {
            if sizeA > sizeB {
                currA = currA?.next
            } else {
                currB = currB?.next
            }
        }
        
        while currA !== currB {
            currA = currA?.next
            currB = currB?.next
        }
        return currA
    }
}
