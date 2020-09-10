class Solution {
    func maxDepth(_ root: TreeNode?) -> Int {
        if root == nil { return 0 }
        
        var q: [TreeNode?] = [root]
        var level: Int = 0
        
        while !q.isEmpty {
            var qSize: Int = q.count
            for i in 0..<qSize {
                var node: TreeNode? = q.removeFirst()
                if let left = node?.left { q.append(left) }
                if let right = node?.right { q.append(right) }
            }
            level += 1
        }
        return level
    }
}
