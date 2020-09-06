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
    vector<int> first;
    vector<int> second;
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        inorder_dfs(root1, first);
        inorder_dfs(root2, second);
        
        return combine(first, second);
    }
    
    void inorder_dfs(TreeNode* node, vector<int> &arr) {
        if (!node) 
            return;
        
        if (node->left)
            inorder_dfs(node->left, arr);
        
        arr.push_back(node->val);
        
        if (node->right)
            inorder_dfs(node->right, arr);
    }
    
    vector<int> combine(vector<int> &a, vector<int> &b) {
        int left = 0, right = 0;
        vector<int> res;
        while (left < a.size() || right < b.size()) {
            if (left < a.size() && right < b.size()) {
                if (a[left] < b[right])
                    res.push_back(a[left++]);
                else 
                    res.push_back(b[right++]);
            } else if (right < b.size()) {
                res.push_back(b[right++]);
            } else {
                res.push_back(a[left++]);
            }
        }
        return res;
    }
};
