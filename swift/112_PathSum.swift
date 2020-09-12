class Solution {
    func hasPathSum(_ node: TreeNode?, _ sum: Int) -> Bool {
        func traverseTree(_ root: TreeNode?, _ curr: Int) -> Bool {
            if root == nil { return false }
            
            var currSum = curr
            currSum += root!.val
            
            if root?.left == nil && root?.right == nil { return currSum == sum }
            
            return traverseTree(root?.left, currSum) || traverseTree(root?.right, currSum)
        }
        return traverseTree(node, 0)
    }
}
