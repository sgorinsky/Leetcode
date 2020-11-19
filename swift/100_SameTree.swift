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
    func isSameTree(_ p: TreeNode?, _ q: TreeNode?) -> Bool {
        var pNodes: [TreeNode?] = [p], qNodes: [TreeNode?] = [q]
        
        while !pNodes.isEmpty && !qNodes.isEmpty {
            var p = pNodes.removeLast()
            var q = qNodes.removeLast()
            
            if p == nil && q == nil { continue }
            else if p == nil || q == nil || (p!.val != q!.val) { return false }
            
            pNodes.append(p?.left)
            pNodes.append(p?.right)
            
            qNodes.append(q?.left)
            qNodes.append(q?.right)
        }
        
        return true
    }
}
