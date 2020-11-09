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
    int tilt = 0;
    int mutateTilt(TreeNode* root) {
        if (!root) return 0;
        
        int left = mutateTilt(root->left);
        int right = mutateTilt(root->right);
        
        tilt += abs(left - right);
        
        return left + right + root->val;
    }
    
    int findTilt(TreeNode* root) {
        tilt = 0;
        mutateTilt(root);
        return tilt;
    }
};
