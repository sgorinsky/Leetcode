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
    Node* findRoot(vector<Node*> tree) {
        // construct parents from children
        unordered_map<Node*, Node*> parents;
        for (Node* node : tree) {
            for (Node* child : node->children)
                parents[child] = node;
        }
        
        Node* node = tree[0];
        while (parents.find(node) != parents.end())
            node = parents[node];
        
        return node;
    }
};
