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
    int deepest_level;
    unordered_map<int, vector<int>> levels;
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (!root) return {};
        
        deepest_level = 0;
        traverseTree(root, 0);
        
        vector<vector<int>> result;
        for (int i = deepest_level; i >= 0; --i) {
            result.push_back(levels[i]);
        }
        return result;
    }
    
    bool traverseTree(TreeNode* node, int lvl) {
        if (!node) return false;
        
        if (lvl > deepest_level) deepest_level = lvl;
        
        if (levels.find(lvl) != levels.end()) {
            levels[lvl].push_back(node->val);
        } else {
            levels[lvl] = vector<int>{node->val};
        }
        
        return traverseTree(node->left, lvl+1) || traverseTree(node->right, lvl+1);
    }
};
