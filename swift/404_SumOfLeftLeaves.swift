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
    var total: Int = 0
    func sumOfLeftLeaves(_ node: TreeNode?) -> Int {
        func helper(_ root: TreeNode?, _ isLeft: Bool) -> Int {
            if root == nil {
                return total
            } else if (root?.left == nil && root?.right == nil) {
                if isLeft {
                    total += root!.val
                }
                return total
            }
            
            if root?.left != nil {
                helper(root?.left, true)
            }
            
            if root?.right != nil {
                helper(root?.right, false)
            }
            
            return total
        }
        return helper(node, false)
    }
}
