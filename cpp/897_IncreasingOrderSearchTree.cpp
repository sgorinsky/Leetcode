class Solution {
public:
    TreeNode* curr;
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* ans = new TreeNode(0);
        curr = ans;
        inorder(root);
        return ans->right;
    }
    
    void inorder(TreeNode* root) {
        if (!root) return;
        
        inorder(root->left);
        root->left = NULL;
        curr->right = root;
        curr = root;
        inorder(root->right);
    }
};

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
    TreeNode* increasingBST(TreeNode* root) {
        if (!root) return root;
        vector<TreeNode*> stack;
        vector<TreeNode*> results;
        while (root || !stack.empty()) {
            while (root) {
                stack.push_back(root);
                root = root->left;
            }
            root = stack.back();
            stack.pop_back();
            results.push_back(root);
            root = root->right;
        }
        for (int i = 0; i < results.size(); ++i) {
            TreeNode* curr = results[i];
            if (i < results.size() - 1) curr->right = results[i + 1];
            curr->left = NULL;
        }
        return results[0];
    }
};
