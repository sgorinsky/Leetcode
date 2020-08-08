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
    int count = 0;
    int target = 0;
    unordered_map<int, int> h;
    int pathSum(TreeNode* root, int sum) {
        h = {};
        target = sum;
        traverseTree(root, 0);
        return count;
    }
    
    void traverseTree(TreeNode* node, int curr) {
        if (node == nullptr) return;
        
        curr += node->val;
            
        if (curr == target) ++count;
        count += h[curr - target];
        h[curr]++;
        
        traverseTree(node->left, curr);
        traverseTree(node->right, curr);
        
        h[curr]--;
    }
};
