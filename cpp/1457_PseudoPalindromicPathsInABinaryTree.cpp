class Solution {
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        unordered_map<int, int> path;
        return traverse(root, path, 0);
    }
    
    int traverse(TreeNode* root, unordered_map<int, int>& path, int length) {
        if (!root) {
            return 0;
        } 
        
        if (path.find(root->val) == path.end()) path[root->val] = 1;
        else path[root->val] += 1;
        
        int sum;
        if (!root->left && !root->right) {
            sum = palindrome(path, length + 1) ? 1 : 0;
        } else {
            sum = traverse(root->left, path, length + 1) + traverse(root->right, path, length + 1);
        }
        path[root->val] -= 1;
        return sum;
    }
    
    bool palindrome(unordered_map<int, int>& path, int length) {
        int count = length % 2;
        // cout << "PATH" << endl;
        for (auto entry : path) {
            int v = entry.second;
            // cout << "n: " << entry.first << ", count: " << v << endl;
            if (entry.second % 2 && --count < 0) {
                return false;
            }
        }
        // cout << "TRUE" << endl;
        return true;
    }
};
