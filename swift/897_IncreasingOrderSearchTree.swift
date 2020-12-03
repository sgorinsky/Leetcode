class Solution {
    func increasingBST(_ node: TreeNode?) -> TreeNode? {
        var root: TreeNode? = node
        var stack = [TreeNode?]()
        var head: TreeNode? = nil, curr: TreeNode? = nil
        while root != nil || !stack.isEmpty {
            while root != nil {
                stack.append(root)
                root = root?.left
            }
            root = stack.removeLast()
            if head == nil {
                curr = root
                head = root
            } else if curr != nil {
                curr?.right = root
                curr = root
            }
            curr?.left = nil
            root = root?.right
        }
        return head
    }
}
