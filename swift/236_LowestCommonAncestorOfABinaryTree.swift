class Solution {
    func lowestCommonAncestor(_ root: TreeNode?, _ p: TreeNode?, _ q: TreeNode?) -> TreeNode? {
        var LCA: TreeNode?
        func traverseTree(_ node: TreeNode?) -> Bool {
            if node == nil {
                return false
            }
            
            let curr = node as TreeNode?
            
            let left = traverseTree(curr?.left) ? 1 : 0
            let right = traverseTree(curr?.right) ? 1 : 0
            let mid = (curr === p || curr === q) ? 1 : 0
            
            if mid + left + right >= 2 {
                LCA = curr
            }
            
            return mid + left + right > 0
        }
        traverseTree(root)
        return LCA
    }
}
