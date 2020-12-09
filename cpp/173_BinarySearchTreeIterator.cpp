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
class BSTIterator {
public:
    vector<int> nodes;
    int head = 0;
    BSTIterator(TreeNode* root) {
        populate_inorder(root);
    }
    
    void populate_inorder(TreeNode* root){
        if (!root) return;
        populate_inorder(root->left);
        nodes.push_back(root->val);
        populate_inorder(root->right);
    }
    
    int next() {
        if (hasNext()) return nodes[head++];
        return -1;
    }
    
    bool hasNext() {
        return head < nodes.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
