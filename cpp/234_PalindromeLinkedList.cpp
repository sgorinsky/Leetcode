class Solution {
public:
    int half = 0;
    bool isPalindrome(ListNode* head) {
        ListNode* reverse = reverse_half(head, 1);
        while (half > 0) {
            if (head->val != reverse->val) {
                return false;
            }
            head = head->next, reverse = reverse->next;
            --half;
        }
        return true;

    }
    
    ListNode* reverse_half(ListNode* head, int count) {
        if (head == NULL || head->next == NULL) {
            half = count / 2;
            return head;
        }
        
        ListNode* before = reverse_half(head->next, count + 1);
        if (count > half) {
            head->next->next = head;
            head->next = NULL;
        };
        
        return before;
    }
};
