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
    public List<Integer> rightSideView(TreeNode root) {
        List<Integer> res = new ArrayList<Integer>();
        if (root == null) return res;
        
        ArrayDeque<TreeNode> queue = new ArrayDeque() {{ offer(root); }};
        
        while (!queue.isEmpty()) {
            int levelLength = queue.size();
            
            for (int i = 0; i < levelLength; ++i) {
                TreeNode node = queue.poll();
                if (i == levelLength - 1)
                    res.add(node.val);
                
                if (node.left != null)
                    queue.offer(node.left);
                
                if (node.right != null)
                    queue.offer(node.right);
            }
        }
        return res;
    }
}

class Solution {
    List<Integer> res;
    public List<Integer> rightSideView(TreeNode root) {
        res = new ArrayList<Integer>();
        if (root == null) return res;
        
        dfs(root, 0);
        return res;
        
    }
    
    public void dfs(TreeNode node, int level) {
        if (level == res.size())
            res.add(node.val);
        
        if (node.right != null)
            dfs(node.right, level+1);
        
        if(node.left != null)
            dfs(node.left, level+1);
    }
}
