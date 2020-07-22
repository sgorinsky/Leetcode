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
    HashMap<Integer, List<Integer>> levels;
    int deepestLevel;
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        if (root == null) return new ArrayList<List<Integer>>();
        
        levels = new HashMap<Integer, List<Integer>>();
        traverseTree(root, 0);
        
        List<List<Integer>> levelList = new ArrayList<List<Integer>>();
        for (int i = deepestLevel; i >= 0; --i) {
            levelList.add(levels.get(i));
        }
        return levelList;
        
    }
    
    public boolean traverseTree(TreeNode node, int lvl) {
        if (node == null) return false;
        
        deepestLevel = lvl > deepestLevel ? lvl : deepestLevel;
        
        // HashMap.containsKey returns null if doesn't contain key and you can only compare null != true
        if (levels.containsKey(lvl) != true) {
            levels.put(lvl, new ArrayList<Integer>(Arrays.asList(node.val)));
        } else {
            levels.get(lvl).add(node.val);
        }
        return traverseTree(node.left, lvl+1) || traverseTree(node.right, lvl+1);
    }
}
