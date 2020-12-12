class Solution {
public:
    int greatest_depth = 0;
    TreeNode* deepest_subtree;
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if (!root) return root;
        helper(root, 0);
        return deepest_subtree;
    }
    
    int helper(TreeNode* root, int depth) {
        greatest_depth = max(greatest_depth, depth);
        if (!root) return depth;
        
        int left = helper(root->left, depth + 1), right = helper(root->right, depth + 1);
        
        if (left == right && left == greatest_depth) deepest_subtree = root;
        return max(left, right);
    }
};
