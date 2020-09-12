class Solution {
    int val;
    public boolean hasPathSum(TreeNode root, int sum) {
        val = sum;
        return addLeaves(root, 0);
    }
    
    public boolean addLeaves(TreeNode root, int currSum) {
        if (root == null)
            return false;
        currSum += root.val;
        if (root.left == null && root.right == null)
            return currSum == val;
        return addLeaves(root.left, currSum) || addLeaves(root.right, currSum);
    }
}
