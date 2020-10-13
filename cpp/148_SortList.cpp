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
    ListNode* sortList(ListNode* head) {
        int length = 1;
        ListNode* curr = head;
        while (curr) {
            curr = curr->next;
            length++;
        }
        return split(head, length);
        
    }
    
    ListNode* merge_sort(ListNode* a, ListNode* b) {
        if (!a || !b) return a ? a : b;
        else if (a->val > b->val) return merge_sort(b, a);

        a->next = merge_sort(a->next, b);
        return a;
    }
    
    ListNode* split(ListNode* head, int length) {
        if (!head || !head->next || length == 1) return head;
        
        int half = length / 2, i = 0;
        ListNode* prev = NULL;
        ListNode* curr = head;
        while (curr && i < half) {
            prev = curr;
            curr = curr->next;
            i++;
        }
        
        if (prev) prev->next = NULL;
        head = split(head, half), curr = split(curr, half % 2 == 1 ? half + 1 : half);
        return merge_sort(head, curr);
    }
    
};
