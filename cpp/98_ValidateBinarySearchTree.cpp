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
    bool isValidBST(TreeNode* root) {
        if (!root || (!root->left && !root->right)) return true;
        return validate_bst(root, NULL, NULL);
    }
    
    bool validate_bst(TreeNode* root, TreeNode* lesser_grandparent, TreeNode* greater_grandparent) {
        if (!root) return true;
        else if ((lesser_grandparent && root->val <= lesser_grandparent->val) || (greater_grandparent && root->val >= greater_grandparent->val)) return false;
        
        return validate_bst(root->left, lesser_grandparent, root) && validate_bst(root->right, root, greater_grandparent);
    }
};
