class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* curr = list1;
        int i = 1;
        while (i < a) {
            curr = curr->next;
            i++;
        }
        
        ListNode* temp = curr->next;
        ListNode* head = list1;
        if (a > 0) curr->next = list2;
        else head = list2;
        
        while (i < b) {
            temp = temp->next;
            i++;
        }
        
        ListNode* second = list2;
        while (second->next) {
            second = second->next;
        }
        
        second->next = temp->next;
        return head;
    }
};
