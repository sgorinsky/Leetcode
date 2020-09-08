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
    vector<int> inorderTraversal(TreeNode* root) {
        if (!root)
            return {};
        
        vector<int> res;
        vector<TreeNode*> stack;
        
        while (root || !stack.empty()) {
            while (root) {
                stack.push_back(root);
                root = root->left;
            }
            root = stack.back();
            stack.pop_back();
            res.push_back(root->val);
            root = root->right;
        }
        return res;
    }
};
