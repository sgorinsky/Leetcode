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
    int deepestLevel;
    HashMap<Integer, List<Integer>> levels;
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        if (root == null) return new ArrayList<List<Integer>>();
        levels = new HashMap<Integer, List<Integer>>();
        deepestLevel = 0;
        traverseTree(root, 0);
        
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        for (int i = 0; i <= deepestLevel; ++i) {
            if (i % 2 == 0) {
                res.add(levels.get(i));
            } else {
                List<Integer> backwards = new ArrayList<Integer>();
                for (int j = levels.get(i).size()-1; j >= 0; --j) {
                    backwards.add(levels.get(i).get(j));
                }
                res.add(backwards);
            } 
        }
        return res;
    }
    public boolean traverseTree(TreeNode node, int lvl) {
        if (node == null) return false;
        
        if (lvl > deepestLevel) deepestLevel = lvl;
        if (levels.containsKey(lvl) != true) {
            levels.put(lvl, new ArrayList<Integer>(Arrays.asList(node.val)));
        } else {
            levels.get(lvl).add(node.val);
        }
        
        return traverseTree(node.left, lvl+1) || traverseTree(node.right, lvl+1);
        
    }
}
