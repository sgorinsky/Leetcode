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
    public List<TreeNode> generateTrees(int n) {
        return n > 0 ? generate(1, n) : new ArrayList<TreeNode>();
    }
    
    public List<TreeNode> generate(int start, int end) {
        if (start > end) return new ArrayList<TreeNode>() {{ add(null); }};
        
        List<TreeNode> allTrees = new ArrayList<TreeNode>();
        
        for (int i = start; i <= end; ++i) {
            List<TreeNode> leftTrees = generate(start, i - 1);
            List<TreeNode> rightTrees = generate(i + 1, end);
            
            for (TreeNode leftTree : leftTrees) {
                for (TreeNode rightTree : rightTrees) {
                    TreeNode curr = new TreeNode(i);
                    curr.left = leftTree;
                    curr.right = rightTree;
                    allTrees.add(curr);
                }
            }
        }
        return allTrees;
    }
}
