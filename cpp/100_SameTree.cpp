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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<TreeNode*> p_nodes = {p};
        vector<TreeNode*> q_nodes = {q};
        
        while (!p_nodes.empty() && !q_nodes.empty()) {
            p = p_nodes.back();
            p_nodes.pop_back();
            
            q = q_nodes.back();
            q_nodes.pop_back();
            
            if (!p && !q) { continue; }
            else if (!p || !q || p->val != q->val) { return false; }
            
            p_nodes.push_back(p->left);
            p_nodes.push_back(p->right);
            
            q_nodes.push_back(q->left);
            q_nodes.push_back(q->right);
        }
        return true;
    }
};
