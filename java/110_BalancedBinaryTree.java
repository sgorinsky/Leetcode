class Solution {
    boolean balanced = true;
    public boolean isBalanced(TreeNode root) {
        dfs(root, 0);
        return balanced;
    }
    
    public int dfs(TreeNode root, int depth) {
        if (root == null) return depth;
        
        int left = 0, right = 0;
        if (balanced) {
            left = dfs(root.left, depth + 1);
            right = dfs(root.right, depth + 1);
        }
        
        if (Math.abs(left - right) > 1) balanced = false;
        return Math.max(left, right);
    }
}
