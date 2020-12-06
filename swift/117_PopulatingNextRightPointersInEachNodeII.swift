/**
 * Definition for a Node.
 * public class Node {
 *     public var val: Int
 *     public var left: Node?
 *     public var right: Node?
 *	   public var next: Node?
 *     public init(_ val: Int) {
 *         self.val = val
 *         self.left = nil
 *         self.right = nil
 *         self.next = nil
 *     }
 * }
 */

class Solution {
    func connect(_ root: Node?) -> Node? {
        func processChild(_ currentChildNode: Node?) {
            var child = currentChildNode
            if child != nil {
                if prev != nil {
                    prev?.next = child
                } else {
                    leftmost = child
                }
                prev = child
            }
        }
        
        var prev: Node? = nil, leftmost: Node? = root
        while leftmost != nil {
            var curr: Node? = leftmost
            leftmost = nil
            prev = nil
            while curr != nil {
                processChild(curr?.left)
                processChild(curr?.right)
                curr = curr?.next
            }
        }
        return root
    }
}
