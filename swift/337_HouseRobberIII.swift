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
    func rob(_ root: TreeNode?) -> Int {
        func helper(_ root: TreeNode?) -> [Int] {
            if root == nil { 
                return [0, 0]
            }
            
            var left = helper(root?.left)
            var right = helper(root?.right)
            
            var rob = left[1] + right[1] + root!.val
            var notRob = max(left[0], left[1]) + max(right[0], right[1])
            
            return [rob, notRob]
        }
        
        var result = helper(root)
        return max(result[0], result[1])
    }
}
