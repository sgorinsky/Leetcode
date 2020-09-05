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
    func preorderTraversal(_ root: TreeNode?) -> [Int] {
        if root == nil { return [] }
        // bfs
        var stack: [TreeNode?] = [root]
        var result: [Int] = [Int]()
        var node: TreeNode?
        
        while !stack.isEmpty {
            node = stack.popLast()!
            result.append(node!.val)
            
            if node?.right != nil {
                stack.append(node?.right)
            }
            if node?.left != nil {
                stack.append(node?.left)
            }
        }
        return result
    }
}
