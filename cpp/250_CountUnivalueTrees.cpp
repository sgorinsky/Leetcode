class Solution {
public:
    int count;
    int countUnivalSubtrees(TreeNode* root) {
        if (!root) return 0;
        
        count = 0;
        countNodes(root, root->val);
        return count;
    }
    
    pair<int, bool> countNodes(TreeNode* root, int parent) {
        if (!root)
            return {parent, true};
        else if (!root->left && !root->right) {
            ++count;
            return {root->val, true};
        }
        
        pair<int, bool> left = countNodes(root->left, root->val);
        pair<int, bool> right = countNodes(root->right, root->val);
        
        if (left.second && right.second &&
            root->val == left.first && root->val == right.first) {
            ++count;
            return {root->val, true};
        } 
        return {root->val, false};
    }
};
