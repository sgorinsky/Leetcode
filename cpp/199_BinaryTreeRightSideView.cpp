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
    int highestLevel = 0;
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) return vector<int>{};
        vector<int> res = {};
        levelOrderTraversal(root);
        for (int i = 0; i <= highestLevel; ++i) {
            res.push_back(levels[i][levels[i].size()-1]);
        }
        return res;
    }
    
    bool levelOrderTraversal(TreeNode* node, int lvl = 0) {
        if (node == nullptr) return false;
        
        highestLevel = max(lvl, highestLevel);
        if (levels.find(lvl) == levels.end()) {
            levels[lvl] = {node->val};
        } else {
            levels[lvl].push_back(node->val);
        }
        
        return levelOrderTraversal(node->left, lvl+1) || levelOrderTraversal(node->right, lvl+1);
        
        
    }
};
