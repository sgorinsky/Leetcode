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
    func generateTrees(_ n: Int) -> [TreeNode?] {
        func generate(_ start: Int, _ end: Int) -> [TreeNode?] {
            if start > end { return [nil] }
            
            var allTrees = [TreeNode?]()
            for i in start...end {
                var leftTrees = generate(start, i - 1)
                var rightTrees = generate(i + 1, end)
                
                for leftTree in leftTrees {
                    for rightTree in rightTrees {
                        var newTree = TreeNode(i)
                        newTree.left = leftTree
                        newTree.right = rightTree
                        allTrees.append(newTree)
                    }
                }
            }
            return allTrees
        }
        return n > 0 ? generate(1, n) : []
    }
}
