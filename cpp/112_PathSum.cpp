class Solution {
public:
    int val;
    bool hasPathSum(TreeNode* root, int sum) {
        val = sum;
        return addPath(root, 0);
    }
    
    bool addPath(TreeNode* root, int curr) {
        if (!root) return false;
        curr += root->val;
        
        if (!root->left && !root->right) return curr == val;
        return addPath(root->left, curr) || addPath(root->right, curr);
    }
};
