class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        
        ListNode* curr = head->next;
        ListNode* prev = head;
        head = curr;
        while (prev && prev->next) {
            ListNode* after = curr->next;
            
            curr->next = prev;
            prev->next = after && after->next ? after->next : after;
            
            prev = after;
            curr = prev ? prev->next : NULL;
        }
        return head;
    }
};
