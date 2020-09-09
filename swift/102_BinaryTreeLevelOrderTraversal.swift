class Solution {
    func levelOrder(_ root: TreeNode?) -> [[Int]] {
        if root == nil { return [] }
        
        var levels: [[Int]] = [[Int]]()
        var q = [root]
        var lvl: Int = 0
        
        while !q.isEmpty {
            levels.append([])
            var length: Int = q.count
            
            for _ in 0..<length {
                let node = q.removeFirst()
                levels[lvl].append(node!.val)
                
                if let left = node?.left { q.append(left) }
                if let right = node?.right { q.append(right) }
            }
            lvl += 1
        }
        return levels
    }
}
