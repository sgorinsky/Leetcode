// O(1) space
class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return NULL;
        Node* left = root;
        while (left) {
            Node* curr = left;
            while (curr) {
                // cout << curr->val << endl;
                if (curr->left) {
                    if (curr->right) {
                        curr->left->next = curr->right;
                        // cout << "here" << endl;
                        // cout << curr->left->val << curr->left->next->val << endl;
                    } else {
                        Node* temp = curr->next;
                        while (temp && !(temp->left || temp->right)) temp = temp->next;
                        if (temp) curr->left->next = temp->left ? temp->left : temp->right;
                    }
                }
                if (curr->right) {
                    Node* temp = curr->next;
                    while (temp && !(temp->left || temp->right)) temp = temp->next;
                    if (temp) curr->right->next = temp->left ? temp->left : temp->right;
                }
                curr = curr->next;
            }
            // cout << "left: " << left->val << endl;
            left = left->left ? left->left : left->right;
            while (left && !left->left && !left->right) left = left->next;
        }
        return root;
    }
};

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
             	
		node->next = i == size - 1 ? NULL : q.front();   
            }
        }
        return root;
    }
};
