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
