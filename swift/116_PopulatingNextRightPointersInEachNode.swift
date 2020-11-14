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
        if root == nil {
            return root
        }
        
        var leftmostNode: Node? = root
        while leftmostNode?.left != nil {
            var head: Node? = leftmostNode
            while head != nil {
                head?.left?.next = head?.right
                
                if head?.next != nil {
                    head?.right?.next = head?.next?.left
                }
                
                head = head?.next
            }
            leftmostNode = leftmostNode?.left
        }
        return root
    }
}
