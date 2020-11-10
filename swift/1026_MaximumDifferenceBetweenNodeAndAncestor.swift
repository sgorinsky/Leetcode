/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public var val: Int
 *     public var left: TreeNode?
 *     public var right: TreeNode?
 *     public init() { self.val = 0; self.left = nil; self.right = nil; }
 *     public init(_ val: Int) { self.val = val; self.left = nil; self.right = nil; }
 *     public init(_ val: Int, _ left: TreeNode?, _ right: TreeNode?) {
 *         self.val = val
 *         self.left = left
 *         self.right = right
 *     }
 * }
 */
class Solution {
    func maxAncestorDiff(_ root: TreeNode?) -> Int {
        func helper(_ node: TreeNode?, _ lowestValAmongRelatives: Int, _ highestValAmongRelatives: Int) -> Int {
            if node == nil { 
                return highestValAmongRelatives - lowestValAmongRelatives
            }
            
            var low = min(lowestValAmongRelatives, node!.val)
            var high = max(highestValAmongRelatives, node!.val)
            
            return max(helper(node?.left, low, high), helper(node?.right, low, high))
        }
        return helper(root, Int.max, Int.min)
    }
}
