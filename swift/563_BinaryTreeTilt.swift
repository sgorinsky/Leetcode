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
    func findTilt(_ root: TreeNode?) -> Int {
        var tilt = 0
        func getFullSum(_ node: TreeNode?) -> Int {
            if node == nil { return 0 }
            var left = getFullSum(node?.left)
            var right = getFullSum(node?.right)
            
            tilt += abs(left - right)
            return left + right + node!.val
        }
        
        getFullSum(root)
        return tilt
    }
}
