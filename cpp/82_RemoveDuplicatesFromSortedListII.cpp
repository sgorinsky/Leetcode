class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* prev = new ListNode(0);
        prev->next = head;
        ListNode* dummy = prev;
        ListNode* curr = head;
        while (curr && curr->next) {
            if (curr->val == curr->next->val) {
                prev->next = removeDup(curr->next);
                curr = prev->next;
            } else {
                prev = curr;
                curr = curr->next;
            }
        }
        return dummy->next;
    }
    
    ListNode* removeDup(ListNode* head) {
        if (!head) return head;
        ListNode* curr = head->next;
        while (curr && curr->val == head->val) 
            curr = curr->next;
        return curr;
    }
};
