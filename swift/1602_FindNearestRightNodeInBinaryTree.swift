class Solution {
    func findNearestRightNode(_ root: TreeNode?, _ u: TreeNode?) -> TreeNode? {
        var q = [root]
        while !q.isEmpty {
            var nextNodes = [TreeNode?]()
            var sz = q.count
            for i in 0..<sz {
                var node = q[i]
                if node === u {
                    return i < q.count - 1 ? q[i + 1] : nil
                }
                if node?.left != nil {
                    nextNodes.append(node?.left)
                }
                if node?.right != nil {
                    nextNodes.append(node?.right)
                }
            }
            q = nextNodes
        }
        return nil
        
    }
}
