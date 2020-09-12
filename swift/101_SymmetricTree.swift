class Solution {
    func isSymmetric(_ root: TreeNode?) -> Bool {
        return mirror(root, root)
    }
    
    func mirror(_ t1: TreeNode?, _ t2: TreeNode?) -> Bool {
        if t1 == nil && t2 == nil { return true }
        else if t1 == nil || t2 == nil { return false }
        
        return t1!.val == t2!.val && mirror(t1?.left, t2?.right) && mirror(t1?.right, t2?.left)
    }
}
