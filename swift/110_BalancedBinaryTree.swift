class Solution {
    func isBalanced(_ root: TreeNode?) -> Bool {
        func checkBranches(_ node: TreeNode?, _ depth: Int) -> Int {
            if node == nil { return depth }
            
            var left = 0, right = 0
            if balanced {
                left = checkBranches(node?.left, depth + 1)
                right = checkBranches(node?.right, depth + 1)
            }
            
            if (abs(left - right) > 1) {
                balanced = false
            }
            
            return max(left, right)
        }
        
        var balanced = true
        checkBranches(root, 0)
        return balanced
    }
}
