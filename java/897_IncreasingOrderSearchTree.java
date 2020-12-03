class Solution {
    TreeNode curr;
    public TreeNode increasingBST(TreeNode root) {
        curr = new TreeNode(0);
        TreeNode ans = curr;
        inorder(root);
        return ans.right;
    }
    
    public void inorder(TreeNode root) {
        if (root == null) return;
        
        inorder(root.left);
        curr.right = root;
        curr = root;
        root.left = null;
        inorder(root.right);
    }
}
