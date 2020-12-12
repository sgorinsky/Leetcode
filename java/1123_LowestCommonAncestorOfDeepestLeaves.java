class Solution {
    TreeNode deepestSubtree;
    int deepestDepth = 0;
    public TreeNode lcaDeepestLeaves(TreeNode root) {
        deepestSubtree = root;
        helper(root, 0);
        return deepestSubtree;
    }
    
    public int helper(TreeNode root, int depth) {
        deepestDepth = Math.max(deepestDepth, depth);
        if (root == null) return depth;
        
        int left = helper(root.left, depth + 1), right = helper(root.right, depth + 1);
        if (left == right && left == deepestDepth) deepestSubtree = root;
        return Math.max(left, right);
    }
}
