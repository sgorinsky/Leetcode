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
    func getAllElements(_ r1: TreeNode?, _ r2: TreeNode?) -> [Int] {
        var root1: TreeNode? = r1, root2: TreeNode? = r2
        var stack1: [TreeNode?] = [TreeNode?]()
        var stack2: [TreeNode?] = [TreeNode?]()
        var res: [Int] = [Int]()
        
        while !stack1.isEmpty || !stack2.isEmpty || root1 != nil || root2 != nil {
            // left branches in stack
            while root1 != nil {
                stack1.append(root1)
                root1 = root1?.left
            }
            
            while root2 != nil {
                stack2.append(root2)
                root2 = root2?.left
            }
            
            if stack2.isEmpty || !stack1.isEmpty && stack1[stack1.endIndex-1]!.val <= stack2[stack2.endIndex - 1]!.val {
                root1 = stack1.popLast()!
                res.append(root1!.val)
                root1 = root1?.right
            } else {
                root2 = stack2.popLast()!
                res.append(root2!.val)
                root2 = root2?.right
            }
        }
        return res
    }
}
