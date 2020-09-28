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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        reverse(preorder.begin(), preorder.end());
        reverse(inorder.begin(), inorder.end());

        return build(preorder, inorder, INT_MIN);
    }
    
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int stop) {
        if (preorder.empty() || inorder[inorder.size()-1] == stop)
            return NULL;
        
        TreeNode* root = new TreeNode(preorder.back());
        preorder.pop_back();
        
        root->left = build(preorder, inorder, root->val);
        inorder.pop_back();
        root->right = build(preorder, inorder, stop);
        return root;
    }
};
