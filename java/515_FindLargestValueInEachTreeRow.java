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
    List<Integer> levels;
    public List<Integer> largestValues(TreeNode root) {
        levels = new ArrayList<Integer>();
        traverseTree(root, 0);
        return levels;
    }
    public boolean traverseTree(TreeNode node, int lvl) {
        if (node == null) return false;
        
        if (lvl < levels.size()) {
            levels.set(lvl, levels.get(lvl) < node.val ? node.val : levels.get(lvl));
        } else {
            levels.add(node.val);
        }
        
        return traverseTree(node.left, lvl+1) || traverseTree(node.right, lvl+1);
    }
}
