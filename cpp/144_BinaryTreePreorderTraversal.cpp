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
    vector<int> preorderTraversal(TreeNode* root) {
        // morris traversal
        TreeNode* node = root;
        vector<int> result;
        while (node) {
            if (!node->left) {
                result.push_back(node->val);
                node = node->right;
            } else {
                TreeNode* predecessor = node->left;
                while (predecessor->right && predecessor->right != node)
                    predecessor = predecessor->right;
                
                if (!predecessor->right) {
                    result.push_back(node->val);
                    predecessor->right = node;
                    node = node->left;
                } else {
                    predecessor->right = NULL;
                    node = node->right;
                }
            }
        }
        return result;
    }
};
