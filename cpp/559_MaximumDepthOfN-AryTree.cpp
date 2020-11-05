/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        if (!root) return 0;
        
        deque<Node*> q;
        q.push_front(root);
        
        int height = 0;
        while (!q.empty()) {
            int sz = q.size();
            height++;
            for (int i = 0; i < sz; ++i) {
                Node* curr = q.front();
                q.pop_front();
                for (Node* child : curr->children) {
                    q.push_back(child);
                }
            }  
        }
        return height;
    }
};
