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
    int low = INT_MAX, high = INT_MIN;
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;
        
        deque<vector<int>> verticals;
        deque<pair<int, TreeNode*>> q = {{0, root}};
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                pair<int, TreeNode*> front = q.front();
                q.pop_front();
                
                int offset = front.first;
                TreeNode* curr = front.second;
                
                if (offset < low || offset > high)  {
                    if (offset < 0) verticals.push_front({});
                    else verticals.push_back({});
                }
                
                low = min(offset, low), high = max(offset, high);
                verticals[abs(low) + offset].push_back(curr->val);
                
                if (curr->left) q.push_back({offset - 1, curr->left});
                if (curr->right) q.push_back({offset + 1, curr->right});
            }
        }
        for (vector<int>& v : verticals) result.push_back(v);
        return result;
    }
};
