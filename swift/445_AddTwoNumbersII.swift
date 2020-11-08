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
    func addTwoNumbers(_ l1: ListNode?, _ l2: ListNode?) -> ListNode? {
        if l1 == nil || l2 == nil {
            return l1 == nil ? l2 : l1
        }
        var firstArray = [Int](), secondArray = [Int]()
        var firstCurr = l1, secondCurr = l2
        
        while firstCurr != nil || secondCurr != nil {
            if firstCurr != nil {
                firstArray.append(firstCurr!.val)
                firstCurr = firstCurr?.next
            }
            
            if secondCurr != nil {
                secondArray.append(secondCurr!.val)
                secondCurr = secondCurr?.next
            }
        }
        
        var carry = 0
        if firstArray.count < secondArray.count {
            var temp = secondArray
            secondArray = firstArray
            firstArray = temp
        }
        
        var firstIdx = firstArray.count - 1, secondIdx = secondArray.count - 1
        while firstIdx >= 0 || secondIdx >= 0 {
            var total = firstArray[firstIdx] + (secondIdx >= 0 ? secondArray[secondIdx] : 0) + carry
            firstArray[firstIdx] = total % 10
            carry = total / 10
            firstIdx -= 1
            secondIdx -= 1
        }
        
        var head: ListNode?
        if carry == 1 {
            head = ListNode(1)
            firstIdx = 0
        } else {
            head = ListNode(firstArray[0])
            firstIdx = 1
        }
        
        var curr = head
        while firstIdx < firstArray.count {
            var next: ListNode? = ListNode(firstArray[firstIdx])
            curr?.next = next
            curr = curr?.next
            firstIdx += 1
        }
        return head
    }
}
