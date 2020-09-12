class Solution {
    func countUnivalSubtrees(_ root: TreeNode?) -> Int {
        if root == nil { return 0 }
        
        var count: Int = 0
        
        func checkSubtree(_ node: TreeNode?, _ parentVal: Int) -> Bool {
            if node == nil { return true }
            
            var left: Bool = checkSubtree(node?.left, node!.val)
            var right: Bool = checkSubtree(node?.right, node!.val)
            
            if !left || !right { return false }
            
            count += 1
            return node!.val == parentVal
        }
        
        checkSubtree(root, root!.val)
        return count
    }
}
