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
    ListNode* plusOne(ListNode* head) {
        ListNode* reversed = reverseLinkedList(head);
        ListNode* curr = reversed;
        
        int remainder = (curr->val + 1) / 10;
        curr->val = (curr->val + 1) % 10;
        while (curr->next && remainder == 1) {
            curr = curr->next;
            remainder = (curr->val + 1) / 10;
            curr->val = (curr->val + 1) % 10;
        }
        if (remainder == 1) curr->next = new ListNode(1);
        return reverseLinkedList(reversed);
    }
    
    ListNode* reverseLinkedList(ListNode* head) {
        ListNode* prev = NULL;
        while (head) {
            ListNode* temp = head;
            ListNode* next = head->next;
            head->next = prev;
            head = next;
            prev = temp;
        }
        return prev;
    }
};
