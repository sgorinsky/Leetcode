class Solution {
    public int maxDepth(TreeNode root) {
        int level = 0;
        if (root == null) return level;
        
        Queue<TreeNode> q = new LinkedList<TreeNode>();
        q.add(root);
        
        while (!q.isEmpty()) {
            int length = q.size();
            
            for (int i = 0; i < length; ++i) {
                root = q.remove();
                if (root.left != null) q.add(root.left);
                if (root.right != null) q.add(root.right);
            }
            ++level;
        }
        return level;
    }
}
