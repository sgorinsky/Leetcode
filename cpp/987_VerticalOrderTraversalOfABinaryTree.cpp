class Solution {
public:
    // priority_queue<int, vector<int>, greater<int>>
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        
        unordered_map<int, vector<int>> levels;
        int left = 0, right = 0;
        deque<pair<int, TreeNode*>> q = {pair<int, TreeNode*>{0, root}};
        while (!q.empty()) {
            int sz = q.size();
            unordered_map<int, priority_queue<int, vector<int>, greater<int>>> verticals = {};
            int small = INT_MAX, large = INT_MIN;
            for (int i = 0; i < sz; ++i) {
                pair<int, TreeNode*> lvl_node = q.front();
                q.pop_front();
                
                int lvl = lvl_node.first;
                TreeNode* node = lvl_node.second;
                
                left = min(left, lvl);
                right = max(right, lvl);
                
                small = min(small, lvl);
                large = max(large, lvl);
                
                if (node->left) q.push_back({lvl - 1, node->left});
                if (node->right) q.push_back({lvl + 1, node->right});
                
                verticals[lvl].push(node->val);
            }
            
            for (int i = small; i <= large; ++i) {
                while (verticals.find(i) != verticals.end() && !verticals[i].empty()) {
                    levels[i].push_back(verticals[i].top());
                    verticals[i].pop();
                }
            }
        }
        
        for (int i = left; i <= right; ++i) 
            res.push_back(levels[i]);
        
        return res;
    }
};
