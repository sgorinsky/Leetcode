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
    public int maxAncestorDiff(TreeNode root) {
        return findMaxDiff(root, Integer.MAX_VALUE, Integer.MIN_VALUE);
    }
    
    public int findMaxDiff(TreeNode root, int low, int high) {
        if (root == null) return high - low;
        
        high = Math.max(high, root.val);
        low = Math.min(low, root.val);
        
        return Math.max(findMaxDiff(root.left, low, high), findMaxDiff(root.right, low, high));
    }
}
