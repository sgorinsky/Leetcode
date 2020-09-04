/**
 * Definition for a Node.
 * public class Node {
 *     public var val: Int
 *     public var next: Node?
 *     public var random: Node?
 *     public init(_ val: Int) {
 *         self.val = val
 *         self.next = nil
 *    	   self.random = nil
 *     }
 * }
 */

class Solution {
    func copyRandomList(_ head: Node?) -> Node? {
        if head == nil { return head }
        var curr: Node? = head
        var node: Node?
        
        while curr != nil {
            node = Node(curr!.val)
            node?.next = curr?.next
            curr?.next = node
            curr = node?.next
        }
        
        curr = head
        var copy: Node? = head?.next
        while copy != nil {
            copy?.random = curr?.random?.next
            curr = copy?.next
            copy = curr?.next
        }
        
        curr = head
        copy = head?.next
        var newHead = copy
        while curr != nil {
            curr?.next = copy?.next
            curr = curr?.next
            copy?.next = curr?.next
            copy = copy?.next
        }
        return newHead
    }
}
