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
    int closestValue(TreeNode* root, double target) {
        int closest_node = -1;
        double distance = DBL_MAX;
        
        while (root) {
            if (abs(target-root->val) < distance) {
                closest_node = root->val;
                distance = abs(target-root->val);
            }
            root = target >= root->val ? root->right : root->left;
        }
        return closest_node;
    }
};
