class Solution {
    func insertIntoBST(_ node: TreeNode?, _ val: Int) -> TreeNode? {
        if node == nil { return TreeNode(val) }
        else if val < (node?.val)! { node?.left = insertIntoBST(node?.left, val) }
        else { node?.right = insertIntoBST(node?.right, val) }
        return node
    }
}
