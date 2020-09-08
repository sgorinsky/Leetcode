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
    int sum;
    int sumRootToLeaf(TreeNode* root) {
        sum = 0;
        return traverse(root, 0);
    }
    
    int traverse(TreeNode* root, int total) {
        total = (total << 1) | root->val;
        
        if (root->left) {
            traverse(root->left, total);
        }
        if (root->right) {
            traverse(root->right, total);
        }
        
        if (!root->left && !root->right) {
            sum += total;
            return sum;
        }
        return sum;
    }
};
