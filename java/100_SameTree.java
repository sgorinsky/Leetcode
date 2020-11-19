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
    public boolean isSameTree(TreeNode pNode, TreeNode qNode) {
        Queue<TreeNode> pNodes = new LinkedList<TreeNode>(){{ add(pNode); }};
        Queue<TreeNode> qNodes = new LinkedList<TreeNode>(){{ add(qNode); }};
        
        while (!pNodes.isEmpty() && !qNodes.isEmpty()) {
            TreeNode p = pNodes.poll();
            TreeNode q = qNodes.poll();
            
            if (p == null && q == null) { continue; }
            else if (p == null || q == null || p.val != q.val) { return false; }
            
            pNodes.add(p.left);
            pNodes.add(p.right);
            
            qNodes.add(q.left);
            qNodes.add(q.right);
        }
        
        return true;
    }
}
