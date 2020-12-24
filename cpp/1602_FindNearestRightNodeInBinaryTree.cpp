class Solution {
public:
    TreeNode* findNearestRightNode(TreeNode* root, TreeNode* u) {
        deque<TreeNode*> q = {root};
        while (!q.empty()) {
            int sz = q.size();
            deque<TreeNode*> next_level;
            for (int i = 0; i < sz; ++i) {
                TreeNode* node = q.front();
                q.pop_front();
                if (node->val == u->val) return q.empty() ? NULL : q.front();
                if (node->left) next_level.push_back(node->left);
                if (node->right) next_level.push_back(node->right);
            }
            while (!next_level.empty()) {
                q.push_back(next_level.front());
                next_level.pop_front();
            }
        }
        return NULL;
    }
};
