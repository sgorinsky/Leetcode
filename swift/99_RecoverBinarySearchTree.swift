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
    func recoverTree(_ node: TreeNode?) {
        var root = node
        var stack = [TreeNode?]()
        var x: TreeNode?, y: TreeNode?, prev: TreeNode?
        
        while root != nil || !stack.isEmpty {
            while root != nil {
                stack.append(root)
                root = root?.left
            }
            root = stack.removeLast()
            if prev != nil && prev!.val > root!.val {
                y = root
                if x == nil {
                    x = prev
                } else {
                    break
                }
            }
            prev = root
            root = root?.right
        }
        var tempVal = x!.val
        x!.val = y!.val
        y!.val = tempVal
    }
}
