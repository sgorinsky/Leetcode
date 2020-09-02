/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    bool check_cyclic(Node* node) {
        Node* slow = node;
        Node* fast = node;
        while (fast && fast->next) {
            slow = slow->next, fast = fast->next->next;
            if (slow == fast)
                return true;
        }
        return false;
    }
    
    Node* start_at_min(Node* node) {
        Node* curr = node;
        Node* min_node = curr;
        
        while (curr) {
            min_node = curr->val < min_node->val ? curr : min_node;
            curr = curr->next;
            if (curr == min_node)
                return curr;
        }
        return NULL;
    }
    Node* insert(Node* head, int insertVal) {
        if (head == NULL) {
            head = new Node(insertVal);
            head->next = head;
            return head;
        }
        
        Node* curr = start_at_min(head);
        head = curr;
        while (curr) {
            Node* next = curr->next;
            if ((next->val >= insertVal && insertVal >= curr->val) ||
                next->val < curr->val ||
                next == head) {
                Node* new_node = new Node(insertVal);
                curr->next = new_node;
                new_node->next = next;
                break;
            }
            curr = curr->next;
        }
        return head;
    }
};
