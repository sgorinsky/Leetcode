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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(inorder, postorder, INT_MAX);
    }
    
    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int stop) {
        if (postorder.empty() || inorder[inorder.size()-1] == stop)
            return NULL;
        
        TreeNode* root = new TreeNode(postorder.back());
        postorder.pop_back();
        
        root->right = build(inorder, postorder, root->val);
        inorder.pop_back();
        root->left = build(inorder, postorder, stop);
        return root;
    }
};
