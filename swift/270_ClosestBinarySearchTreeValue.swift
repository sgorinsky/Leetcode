class Solution {
    func closestValue(_ root: TreeNode?, _ target: Double) -> Int {
        var node = root
        var closestNode: TreeNode? = node
        var closestDifference = Double(Int.max)
        while node != nil {
            var currentDifference = abs(Double(node!.val) - target)
            if currentDifference < closestDifference {
                closestDifference = currentDifference
                closestNode = node
            }
            node = Double(node!.val) > target ? node?.left : node?.right
        }
        return closestNode!.val
    }
}

class Solution {
    func closestValue(_ root: TreeNode?, _ target: Double) -> Int {
        func traverse(_ node: TreeNode?) {
            guard let node = node else { return }
            
            var currentDifference = abs(Double(node.val) - target)
            if difference > currentDifference {
                closestNode = node
                difference = currentDifference
            }
            traverse(node.left)
            traverse(node.right)
        }
        if root == nil { return 0 }
        var difference = Double(Int.max)
        var closestNode = root
        traverse(root)
        return closestNode?.val ?? 0
    }
}
