class Solution {
public:
    vector<bool> path_to_target; // true: left; false: right
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        vector<bool> path;
        find_path(original, target, path);
        for (int i = 0; i < path_to_target.size(); ++i)
            cloned = path_to_target[i] ? cloned->left : cloned->right;
        
        return cloned;
    }
    
    void find_path(TreeNode* original, TreeNode* target, vector<bool>& path) {
        if (target == original) {
            path_to_target = path;
            return;
        } else if (!original || !path_to_target.empty()) {
            return;
        }
        
        path.push_back(true);
        find_path(original->left, target, path);
        path.pop_back();
        
        path.push_back(false);
        find_path(original->right, target, path);
        path.pop_back();
        
    }
};
