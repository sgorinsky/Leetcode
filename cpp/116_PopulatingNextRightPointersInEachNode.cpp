class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return root;
        
        deque<Node*> q = {root};
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                Node* curr = q.front();
                q.pop_front();
                if (curr->left) q.push_back(curr->left);
                if (curr->right) q.push_back(curr->right);
                
                if (i < sz - 1) curr->next = q.front();
            }
        }
        return root;
    }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (!root)
            return NULL;
        deque<Node*> q = {root};
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                Node* node = q.front();
                q.pop_front();
                
                if (node->left)
                    q.push_back(node->left);
                if (node->right)
                    q.push_back(node->right);
                
                if (i == size - 1 || q.empty())
                    node->next = NULL;
                else
                    node->next = q.front();
            }
        }
        return root;
    }
};
