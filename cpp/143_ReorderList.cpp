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
    void reorderList(ListNode* head) {
        unordered_map<int, ListNode*> nodes = {};
        ListNode* curr = head;
        int idx = 0;
        
        while (curr != nullptr) {
            nodes[idx++] = curr;
            curr = curr->next;
        }
        
        int end = idx-1, start = 0;
        while (start <= end) {
            nodes[start++]->next = start < end ? nodes[end] : nullptr;
            nodes[end--]->next = start < end ? nodes[start] : nullptr;
        }
        
    }
};
