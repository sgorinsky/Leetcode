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
    func deleteNode(_ node: TreeNode?, _ key: Int) -> TreeNode? {
        var root = node
        if root == nil { return nil }
        
        if key < root!.val {
            root?.left = deleteNode(root?.left, key)
        } else if key > root!.val {
            root?.right = deleteNode(root?.right, key)
        } else {
            if root?.right == nil && root?.left == nil {
                root = nil
            } else if root?.right != nil {
                root!.val = successor(root)
                root?.right = deleteNode(root?.right, root!.val)
            } else {
                root!.val = predecessor(root)
                root?.left = deleteNode(root?.left, root!.val)
            }
        }
        return root
    }
    
    func successor(_ root: TreeNode?) -> Int {
        var node = root
        node = node?.right
        while node?.left != nil {
            node = node?.left
        }
        return node!.val
    }
    
    func predecessor(_ root: TreeNode?) -> Int {
        var node = root
        node = node?.left
        while node?.right != nil {
            node = node?.right
        }
        return node!.val
    }
}
