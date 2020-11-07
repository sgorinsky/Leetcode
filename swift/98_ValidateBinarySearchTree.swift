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
    func isValidBST(_ root: TreeNode?) -> Bool {
        func validateRootWithChildren(_ node: TreeNode?, _ lesserParent: TreeNode?, _ greaterParent: TreeNode?) -> Bool {
            if node!.val <= lesserParent!.val || node!.val >= greaterParent!.val { return false }
            
            var left = true
            if node?.left != nil {
                if node!.left!.val < node!.val {
                    left = validateRootWithChildren(node?.left, lesserParent, node)
                } else {
                    return false
                }
            }
            
            var right = true
            if node?.right != nil {
                if node!.right!.val > node!.val {
                    right = validateRootWithChildren(node?.right, node, greaterParent)
                } else {
                    return false
                }
            }
            return left && right
        }
        return root != nil ? validateRootWithChildren(root, TreeNode(Int.min), TreeNode(Int.max)) : true
    }
}
