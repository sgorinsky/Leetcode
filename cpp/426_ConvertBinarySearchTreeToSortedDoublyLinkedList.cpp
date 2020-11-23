/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
public:
    vector<Node*> nodes;
    Node* treeToDoublyList(Node* root) {
        if (!root) return root;
        createListOfNodes(root);
        for (int i = 0; i < nodes.size(); ++i) {
            nodes[i]->left = nodes[(nodes.size() + (i - 1)) % nodes.size()];
            nodes[i]->right = nodes[(i + 1) % nodes.size()];
        }
        return nodes[0];
    }
    
    void createListOfNodes(Node* root) {
        if (!root) return;
        createListOfNodes(root->left);
        nodes.push_back(root);
        createListOfNodes(root->right);
    }
};
