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
    vector<int> levels;
    vector<int> largestValues(TreeNode* root) {
        this->levels = {};
        traverseTree(root, 0);
        return levels;
    }
    
    bool traverseTree(TreeNode* node, int lvl) {
        if (!node) return false;
        
        if (lvl < levels.size()) {
            levels[lvl] = levels[lvl] < node->val ? node->val : levels[lvl];
        } else {
            levels.push_back(node->val);
        }
        
        return traverseTree(node->left, lvl+1) || traverseTree(node->right, lvl+1);
    }
};
