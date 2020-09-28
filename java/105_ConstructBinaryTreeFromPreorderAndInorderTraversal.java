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
    public TreeNode buildTree(int[] preorderArray, int[] inorderArray) {
        Deque<Integer> preorder = new ArrayDeque<Integer>();
        Deque<Integer> inorder = new ArrayDeque<Integer>();
        for (int i = 0; i < inorderArray.length; ++i) {
            preorder.addFirst(preorderArray[i]);
            inorder.addFirst(inorderArray[i]);
        }
        return build(preorder, inorder, Integer.MIN_VALUE);
    }
    
    public TreeNode build(Deque<Integer> preorder, Deque<Integer> inorder, int stop) {
        if (preorder.isEmpty() || inorder.getLast() == stop)
            return null;
        TreeNode root = new TreeNode(preorder.removeLast());
        root.left = build(preorder, inorder, root.val);
        inorder.removeLast();
        root.right = build(preorder, inorder, stop);
        return root;
    }
}
