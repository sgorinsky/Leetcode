class Solution {
    public int pseudoPalindromicPaths (TreeNode root) {
        int[] numCounts = new int[9];
        return findPseudoPalindromes(root, numCounts, 0);
    }
    
    public int findPseudoPalindromes(TreeNode root, int[] numCounts, int length) {
        if (root == null) return 0;
        
        numCounts[root.val - 1] += 1;
        int sum;
        if (root.left == null && root.right == null) {
            sum = isPseudoPalindrome(numCounts, length + 1);
        } else {
            sum = findPseudoPalindromes(root.left, numCounts, length + 1) + findPseudoPalindromes(root.right, numCounts, length + 1);
        }
        
        numCounts[root.val - 1] -= 1;
        return sum;
    }
    
    public int isPseudoPalindrome(int[] numCounts, int length) {
        int count = length % 2;
        for (int n : numCounts) {
            if (n % 2 == 1 && --count < 0)
                return 0;
        }
        return 1;
    }
}
