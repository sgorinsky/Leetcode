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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root)
            return {};
        
        vector<vector<int>> result;
        deque<pair<TreeNode*, int>> q = {{root, 0}};
        pair<TreeNode*, int> node_pair;
        int level;
        
        while (!q.empty()) {
            node_pair = q.front();
            q.pop_front();
            
            root = node_pair.first;
            level = node_pair.second;
            
            if (level+1 > result.size())
                result.push_back({});
            
            result[level].push_back(root->val);
            
            if (root->left)
                q.push_back({root->left, level+1});
            if (root->right)
                q.push_back({root->right, level+1});
        }
        return result;
    }
};
