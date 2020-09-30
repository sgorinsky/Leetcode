class Solution {
    TreeNode LCA;
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        traverseTree(root, p, q);
        return LCA;
    }
    
    public boolean traverseTree(TreeNode curr, TreeNode p, TreeNode q) {
        if (curr == null)
            return false;
        
        int left = traverseTree(curr.left, p, q) ? 1 : 0;
        int right = traverseTree(curr.right, p, q) ? 1 : 0;
        int mid = curr == p || curr == q ? 1 : 0;
        
        if (left + mid + right >= 2)
            LCA = curr;
        
        return mid + left + right > 0;
    }
}
