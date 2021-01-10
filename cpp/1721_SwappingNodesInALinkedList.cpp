class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        if (!head) return head;
        
        int i = 1;
        ListNode* curr = head;
        ListNode* temp;
        while (curr) {
            if (i++ == k) {
                temp = curr;
            }
            curr = curr->next;
        }
        
        int size = i;
        i = 1;
        curr = head;
        while (curr) {
            if (size - k == i++) {
                int tmp = temp->val;
                temp->val = curr->val;
                curr->val = tmp;
            }
            curr = curr->next;
        }
        return head;
    }
};
