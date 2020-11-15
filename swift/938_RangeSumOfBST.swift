class Solution {
    func rangeSumBST(_ root: TreeNode?, _ low: Int, _ high: Int) -> Int {
        if root == nil { return 0 }
        
        var rootValue = root!.val
        return (rootValue >= low && rootValue <= high ? rootValue : 0) + 
            rangeSumBST(root?.left, low, high) + rangeSumBST(root?.right, low, high)
    }
}
