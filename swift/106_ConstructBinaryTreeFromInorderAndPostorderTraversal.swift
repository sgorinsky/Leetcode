class Solution {
    func buildTree(_ inorderArray: [Int], _ postorderArray: [Int]) -> TreeNode? {
        var inorder = inorderArray, postorder = postorderArray
        func build(_ stop: Int) -> TreeNode? {
            if !postorder.isEmpty && inorder[inorder.endIndex-1] != stop {
                var root = TreeNode(postorder.removeLast()) as TreeNode?
                root?.right = build(root!.val)
                inorder.removeLast()
                root?.left = build(stop)
                return root
            }
            return nil
        }
        return build(Int.max)
    }
}
