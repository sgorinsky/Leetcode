class Solution {
    public final TreeNode getTargetCopy(final TreeNode original, final TreeNode cloned, final TreeNode target) {
        return dfs(original, cloned, target);
    }
    
    public TreeNode dfs(TreeNode original, TreeNode cloned, TreeNode target) {
        if (original == null) {
            return null;
        } else if (original == target) {
            return cloned;
        }
        
        TreeNode left = dfs(original.left, cloned.left, target);
        TreeNode right = dfs(original.right, cloned.right, target);
        
        return left != null ? left : right;
    }
}
