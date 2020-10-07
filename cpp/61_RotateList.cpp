class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || k == 0) return head;
        
        int length = 0;
        ListNode* curr = head;
        ListNode* prev = NULL;
        
        // get length
        while (curr) {
            prev = curr;
            curr = curr->next;
            length++;
        }
        
        int shift = k % length;
        if (shift == 0) return head;
        
        prev->next = head; // end->next references head
        curr = head;
        
        // traverse list to new end
        while (length - 1 > shift) {
            curr = curr->next;
            length--;
        }
        
        ListNode* new_head = curr->next; // set new head
        curr->next = NULL; // set new end
        return new_head;
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0)
            return head;
        
        unordered_map<int, ListNode*> nodes = {};
        ListNode* curr = head;
        int i = 0;
        while (curr != NULL) {
            nodes[i++] = curr;
            curr = curr->next;
        }
        
        if (k % i == 0)
            return head;
        
        nodes[i-1]->next = head;
        nodes[i - k%i - 1]->next = NULL;
        return nodes[i - k%i];
        
    }
};
