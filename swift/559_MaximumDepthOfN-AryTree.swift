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
    func maxDepth(_ root: Node?) -> Int {
        if root == nil { return 0 }
        func dfs(_ node: Node?, _ height: Int) -> Int {
            var depth = Int.min
            for child in node!.children {
                depth = max(depth, dfs(child, height + 1))
            }
            return max(depth, height)
        }
        return dfs(root, 1)
    }
}
