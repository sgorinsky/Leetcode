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
    unordered_map<int, vector<int>> levels;
    int deepest_level;
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};
        
        deepest_level = 0;
        traverseTree(root, 0);
        vector<vector<int>> res;
        
        for (int i = 0; i < deepest_level+1; ++i) {
            if (i % 2 == 0) {
                res.push_back(levels[i]);
            } else {
                vector<int> backwards;
                for (int j = levels[i].size()-1; j >= 0; --j) {
                    backwards.push_back(levels[i][j]);
                }
                res.push_back(backwards);
            }
        } 
        return res;
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
