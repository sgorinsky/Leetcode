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
    var levels: [Int : [Int]] = [Int : [Int]]()
    var highestLevel: Int = 0
    func rightSideView(_ root: TreeNode?) -> [Int] {
        if root == nil {
            return []
        }
        
        var res: [Int] = [Int]()
        levelOrderTraversal(root)
        for i in 0...highestLevel {
            var currArray: [Int] = levels[i]!
            var endIdx = currArray.index(currArray.endIndex, offsetBy: -1)
            res.append(currArray[endIdx])
        }
        return res
    }
    
    func levelOrderTraversal(_ root: TreeNode?, _ lvl: Int = 0) -> Bool {
        guard let node = root else {
            return false
        }
        
        if lvl > highestLevel {
            highestLevel = lvl
        }
        
        if (levels[lvl] != nil) {
            levels[lvl]?.append(node.val)
        } else {
            levels[lvl] = [node.val]
        }
        
        return levelOrderTraversal(node.left, lvl+1) || levelOrderTraversal(node.right, lvl+1)
        
    }
}
