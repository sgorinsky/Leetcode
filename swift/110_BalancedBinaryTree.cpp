class Solution {
public:
    bool balance = true;
    bool isBalanced(TreeNode* root) {
        dfs(root, 0);
        return balance;
    }
    
    int dfs(TreeNode* root, int depth) {
        if (!root) return depth;
        
        int left, right;
        if (balance) {
            left = dfs(root->left, depth + 1);
            right = dfs(root->right, depth + 1);
        }
        if (abs(left - right) > 1) balance = false;
        return max(left, right);
    }
};
