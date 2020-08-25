class Solution {
    public int sumOfLeftLeaves(TreeNode root) {
        int totalSum = 0;
        TreeNode curr = root;
        while (curr!= null) {
            if (curr.left == null) {
                curr = curr.right;
            } else {
                TreeNode prev = curr.left;
                if (prev.right == null && prev.left == null) {
                    totalSum += prev.val;
                }
                
                while (prev.right != curr && prev.right != null) {
                    prev = prev.right;
                }
                
                if (prev.right == curr) {
                    prev.right = null;
                    curr = curr.right;
                } else {
                    prev.right = curr;
                    curr = curr.left;
                }
            }
        }
        return totalSum;
    }
}
        
