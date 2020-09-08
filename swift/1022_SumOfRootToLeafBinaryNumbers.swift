class Solution {
    func sumRootToLeaf(_ node: TreeNode?) -> Int {
        var root = node
        var total = 0;
        var stack: [(TreeNode?, Int)] = [(root, 0)]
        var curr: Int
        
        while !stack.isEmpty {
            var pair = stack.popLast()!
            root = pair.0
            curr = pair.1
            
            if root != nil {
                curr = (curr << 1) | root!.val
                if root?.left == nil && root?.right == nil {
                    total += curr
                } else {
                    if (root?.left != nil) { stack.append((root?.left, curr)) }
                    if (root?.right != nil) { stack.append((root?.right, curr)) }
                }
            }
        }
        return total
    }
}
