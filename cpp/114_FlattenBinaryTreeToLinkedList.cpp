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
    void flatten(TreeNode* root) {
        flattenTree(root);
    }
    
    TreeNode* flattenTree(TreeNode* node) {
        if (node == nullptr) {
            return nullptr;
        } else if (node->right == nullptr and node->left == nullptr) {
            return node;
        }
        
        TreeNode* left = flattenTree(node->left);
        TreeNode* right = flattenTree(node->right);
        
        if (left != nullptr) {
            left->right = node->right;
            node->right = node->left;
            node->left = nullptr;
        }
        
        return right == nullptr ? left : right;
            
    }
};
