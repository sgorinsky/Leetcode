class Solution {
    func buildTree(_ preorderList: [Int], _ inorderList: [Int]) -> TreeNode? {
        var preorder = preorderList, inorder = inorderList
        preorder.reverse()
        inorder.reverse()
        
        func build(_ stop: Int) -> TreeNode? {
            if !preorder.isEmpty && inorder[inorder.endIndex-1] != stop {
                var root = TreeNode(preorder.removeLast()) as TreeNode?
                root?.left = build(root!.val)
                inorder.removeLast() 
                root?.right = build(stop)
                return root
            }
            return nil
        }
        return build(Int.max)
    }
}
