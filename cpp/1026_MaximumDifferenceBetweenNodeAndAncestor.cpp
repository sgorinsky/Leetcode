/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        if (!root) return 0;
        return helper(root, INT_MAX, INT_MIN);
    }
    
    int helper(TreeNode* root, int small, int big) {
        if (!root) return big - small;
        
        small = min(small, root->val), big = max(big, root->val);
        return max(helper(root->left, small, big), helper(root->right, small, big));
    }
};
