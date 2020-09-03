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
