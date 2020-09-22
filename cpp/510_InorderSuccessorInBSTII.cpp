/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* inorderSuccessor(Node* node) {
        if (!node) return NULL;

        int val = node->val;
        Node* curr = node->parent;
        Node* cand = NULL;
        while (curr) {
            if (curr->val > val) {
                cand = curr;
                break;
            }
            curr = curr->parent;
        }
        
        curr = node->right;
        while (curr) {
            if (curr->val > val && (cand == NULL || curr->val < cand->val)) cand = curr;
            curr = curr->left;
        }
        return cand;
    }
};
