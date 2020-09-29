class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        string p_path = traverse(root, p, ""), q_path = traverse(root, q, "");
        
        int i = 0, min_length = min(p_path.length(), q_path.length());
        while (i < min_length && p_path[i] == q_path[i])
            root = p_path[i++] == 'L' ? root->left : root->right;
        
        return root;
    }
    
    string traverse(TreeNode* root, TreeNode* target, string path) {
        if (!root)
            return "";
        else if (root == target)
            return path;
        
        return traverse(root->left, target, path + "L") + traverse(root->right, target, path + "R");
    }
};
