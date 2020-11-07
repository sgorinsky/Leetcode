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
        
        if ((lesser_grandparent && root->val <= lesser_grandparent->val) || (greater_grandparent && root->val >= greater_grandparent->val)) {
            return false;
        }
        
        bool left = true;
        if (root->left) {
            if (root->val > root->left->val) {
                left = validate_bst(root->left, lesser_grandparent, root);
            } else  {
                 return false;
            }
        }
        
        bool right = true;
        if (root->right) {
            if (root->val < root->right->val) {
                right = validate_bst(root->right, root, greater_grandparent);
            } else {
                return false;
            }
        }
        
        return left && right;
    }
};
