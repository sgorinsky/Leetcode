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
    public int closestValue(TreeNode root, double target) {
        double dist = Double.MAX_VALUE;
        int closestNode = -1;
        while (root != null) {
            if (abs(target-root.val) < dist) {
                dist = abs(target-root.val);
                closestNode = root.val;
            }
            root = target > root.val ? root.right : root.left;
        }
        return closestNode;
    }
    
    public double abs(double num) {
        return num < 0 ? -num : num;
    }
}
