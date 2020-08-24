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
    int total = 0;
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root)
            return total;
        
        return sum_traversal(root, false);
        
    }
    
    int sum_traversal(TreeNode* root, bool is_left) {
        if (root == nullptr) {
            return total;
        } else if (root->left == nullptr && root->right == nullptr) {
            if (is_left) {
                total += root->val;
            }
            return total;
        }
        
        if (root->left)
            sum_traversal(root->left, true);
        
        if (root->right)
            sum_traversal(root->right, false);
        
        return total;
    }
};
