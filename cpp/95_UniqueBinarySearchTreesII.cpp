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
    vector<TreeNode*> generateTrees(int n) {
        return n > 0 ? generate(1, n) : vector<TreeNode*>{};
    }
    
    vector<TreeNode*> generate(int start, int end) {
        if (start > end)  return {NULL};

        vector<TreeNode*> all_trees;
        for (int i = start; i <= end; ++i) {
            vector<TreeNode*> left_trees = generate(start, i-1);
            vector<TreeNode*> right_trees = generate(i+1, end);

            for (TreeNode* left_tree : left_trees) {
                for (TreeNode* right_tree : right_trees) {
                    TreeNode* curr = new TreeNode(i);
                    curr->left = left_tree;
                    curr->right = right_tree;
                    all_trees.push_back(curr);
                }
            }
        }
        return all_trees;
    }
}
