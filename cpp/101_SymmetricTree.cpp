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
    bool isSymmetric(TreeNode* root) {
        if (!root) 
            return true;
        
        deque<TreeNode*> lefts = {root};
        deque<TreeNode*> rights = {root};
        while (!lefts.empty()) {
            int length = lefts.size();
            
            for (int i = 0; i < length; ++i) {
                TreeNode* l = lefts.front();
                TreeNode* r = rights.front();
                
                lefts.pop_front();
                rights.pop_front();
                
                if (l->val != r->val)
                    return false;
                
                if (l->left && r->right) {
                    lefts.push_back(l->left);
                    rights.push_back(r->right);
                } else if (l->left || r->right) {
                    return false;
                }
                
                if (l->right && r->left){
                    lefts.push_back(l->right);
                    rights.push_back(r->left);
                } else if (l->right || r->left) {
                    return false;
                }
            }
        }
        return true;
    }
};
