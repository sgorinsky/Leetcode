class Solution {
    func invertTree(_ root: TreeNode?) -> TreeNode? {
        guard let node = root as? TreeNode? else { return nil }
        
        var tempNode: TreeNode? = node?.left
        node?.left = invertTree(node?.right)
        node?.right = invertTree(tempNode)
        return node
    }
}
