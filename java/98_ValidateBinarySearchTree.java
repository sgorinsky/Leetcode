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
    public boolean isValidBST(TreeNode root) {
        if (root == null) return true;
        return validateBST(root, null, null);
    }
    
    public boolean validateBST(TreeNode root, TreeNode lesserGrandparent, TreeNode greaterGrandparent) {
        if (root == null) return true;
        else if ((lesserGrandparent != null && lesserGrandparent.val >= root.val) ||
            (greaterGrandparent != null && greaterGrandparent.val <= root.val))
            return false;
        
        return validateBST(root.left, lesserGrandparent, root) && validateBST(root.right, root, greaterGrandparent);
    }
}
