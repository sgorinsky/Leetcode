class Solution {
public:
    int rob(TreeNode* root) {
        vector<int> res = helper(root, 0, 0);
        return max(res[0], res[1]);
    }
    
    vector<int> helper(TreeNode* root, int rob, int not_rob) {
        if (!root) return {0, 0};
        
        vector<int> left = helper(root->left, rob, not_rob);
        vector<int> right = helper(root->right, rob, not_rob);
        
        rob = left[1] + right[1] + root->val;
        not_rob = max(left[0], left[1]) + max(right[0], right[1]);
        
        return {rob, not_rob};
    }
};
