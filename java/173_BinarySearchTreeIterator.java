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
class BSTIterator {
    Stack<TreeNode> nodes;
    public BSTIterator(TreeNode root) {
        nodes = new Stack<TreeNode>();
        addLefts(root);
    }
    
    private void addLefts(TreeNode root) {
        while (root != null) {
            nodes.add(root);
            root = root.left;
        }
    }
    
    public int next() {
        if (nodes.isEmpty()) return -1;
        TreeNode curr = nodes.pop();
        addLefts(curr.right);
        return curr.val;
    }
    
    public boolean hasNext() {
        return !nodes.isEmpty();
    }
}

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator obj = new BSTIterator(root);
 * int param_1 = obj.next();
 * boolean param_2 = obj.hasNext();
 */
