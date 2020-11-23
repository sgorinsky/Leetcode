/**
 * Definition for a Node.
 * public class Node {
 *     public var val: Int
 *     public var left: Node?
 *     public var right: Node?
 *     public init(_ val: Int) {
 *         self.val = val
 *         self.left = nil
 *         self.right = nil
 *     }
 * }
 */

class Solution {
    func treeToDoublyList(_ root: Node?) -> Node? {
        func helper(_ node: Node?) {
            if let currentNode = node {
                helper(currentNode.left)
                if last == nil {
                    first = node
                } else {
                    currentNode.left = last
                    last?.right = currentNode
                }
                last = currentNode
                helper(currentNode.right)
            }
        }
        
        var first: Node?, last: Node?
        helper(root)
        first?.left = last
        last?.right = first
        return first
    }
}
