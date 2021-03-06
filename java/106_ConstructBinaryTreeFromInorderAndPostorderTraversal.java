class Solution {
    int i, p;
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        i = inorder.length-1;
        p = postorder.length-1;
        return build(Integer.MIN_VALUE, inorder, postorder);
    }
    
    public TreeNode build(int stop, int[] inorder, int[] postorder) {
        if (p < 0 || inorder[i] == stop)
            return null;
        
        TreeNode root = new TreeNode(postorder[p--]);
        root.right = build(root.val, inorder, postorder);
        
        i--;
        root.left = build(stop, inorder, postorder);
        return root;
    }
}

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
    public TreeNode buildTree(int[] inorderArray, int[] postorderArray) {
        Stack<Integer> inorder = new Stack<Integer>();
        Stack<Integer> postorder = new Stack<Integer>();
        for (int i = 0; i < inorderArray.length; ++i) {
            inorder.push(inorderArray[i]);
            postorder.push(postorderArray[i]);
        }
        return build(inorder, postorder, Integer.MIN_VALUE);
    }
    
    public TreeNode build(Stack<Integer> inorder, Stack<Integer> postorder, int stop) {
        if (postorder.empty() || inorder.peek() == stop)
            return null;
        
        TreeNode root = new TreeNode(postorder.pop());
        root.right = build(inorder, postorder, root.val);
        inorder.pop();
        root.left = build(inorder, postorder, stop);
        return root;
    }
}
