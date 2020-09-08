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
    public int sumRootToLeaf(TreeNode root) {
        int total = 0, curr = 0;
        int steps = 0;
        TreeNode pre;
        
        while (root != null) {
            if (root.left == null) {
                curr = (curr << 1) | root.val;
                if (root.right == null)
                    total += curr;
                root = root.right;
            } else {
                pre = root.left;
                steps = 1;
                while (pre.right != null && pre.right != root) {
                    pre = pre.right;
                    ++steps;
                }
                
                if (pre.right == null) {
                    curr = (curr << 1) | root.val;
                    pre.right = root;
                    root = root.left;
                } else {
                    if (pre.left == null)
                        total += curr;
                
                    for (int i = 0; i < steps; ++i)
                        curr >>= 1;

                    pre.right = null;
                    root = root.right;
                }
            }
        }
        return total;
    }
}
