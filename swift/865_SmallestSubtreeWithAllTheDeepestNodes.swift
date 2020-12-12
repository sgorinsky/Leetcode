class Solution {
    func subtreeWithAllDeepest(_ root: TreeNode?) -> TreeNode? {
        func helper(_ node: TreeNode?, _ depth: Int) -> Int {
            greatestDepth = max(depth, greatestDepth)
            if node == nil { return depth }
            
            var left = helper(node?.left, depth + 1)
            var right = helper(node?.right, depth + 1)
            
            if left == right && left == greatestDepth { ancestor = node }
            return max(left, right)
        }
        
        var ancestor = root
        var greatestDepth = 0
        helper(root, 0)
        return ancestor
    }
}
