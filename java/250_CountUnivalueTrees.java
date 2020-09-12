public class Solution {
    int count;
    boolean all(TreeNode root, int val) {
        if (root == null)
            return true;
        // bitwise | ensures both sides are traversed (|| would not if first evaluates to true)
        if (!all(root.left, root.val) | !all(root.right, root.val))
            return false;
        count++;
        return root.val == val;
    }
    
    public int countUnivalSubtrees(TreeNode root) {
        count = 0;
        all(root, 0);
        return count;
    }
}
