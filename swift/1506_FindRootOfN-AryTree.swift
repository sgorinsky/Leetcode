/**
 * Definition for a Node.
 * public class Node {
 *     public var val: Int
 *     public var children: [Node]
 *     public init(_ val: Int) {
 *         self.val = val
 *         self.children = []
 *     }
 * }
 */

class Solution {
    func findRoot(_ tree: [Node]) -> Node? {
        var xorResult = 0
        for node in tree {
            xorResult ^= node.val
            for child in node.children {
                xorResult ^= child.val
            }
        }
        
        for node in tree {
            if xorResult == node.val {
                return node
            }
        }
        
        return tree[0]
    }
}
