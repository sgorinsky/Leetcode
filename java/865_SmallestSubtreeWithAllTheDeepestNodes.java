/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    int deepestDepth = 0;
    TreeNode deepestSubtree;
    public TreeNode subtreeWithAllDeepest(TreeNode root) {
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
