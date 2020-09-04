/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head)
            return head;
        
        Node* curr = head;
        Node* node;
        while (curr) {
            node = new Node(curr->val);
            node->next = curr->next;
            curr->next = node;
            curr = node->next;
        }

        curr = head;
        Node* copy;
        while (curr) {
            copy = curr->next;
            copy->random = curr->random != NULL ? curr->random->next : NULL;
            curr = copy->next;
        }
        
        curr = head;
        copy = head->next;
        Node* new_head = copy;
        while (curr) {
            curr->next = copy->next;
            curr = curr->next;
            copy->next = curr != NULL ? curr->next : NULL;
            copy = copy->next;
        }
        return new_head;
    }
    
    void printNodes(Node* node) {
        Node* curr = node;
        cout << "Print nodes" << endl;
        while (curr) {
            cout << "val: " << curr->val << ", rand: " << (curr->random != NULL ? curr->random->val : NULL) << ", mem: " << curr << endl;
            curr = curr->next;
        }
        
    }
};
