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
    public List<Integer> preorderTraversal(TreeNode root) {
        // morris preorder
        TreeNode node = root;
        List<Integer> result = new ArrayList<Integer>();
        
        while (node != null) {
            if (node.left == null) {
                result.add(node.val);
                node = node.right;
            } else {
                TreeNode p = node.left;
                while (p.right != null && p.right != node)
                    p = p.right;
                
                if (p.right == null) {
                    p.right = node;
                    result.add(node.val);
                    node = node.left;
                } else {
                    p.right = null;
                    node = node.right;
                }
            }
        }
        return result;
    }
}
