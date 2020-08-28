/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int a_size = 0, b_size = 0;
        ListNode* curr_a = headA;
        ListNode* curr_b = headB;
        
        while (curr_a || curr_b) {
            if (curr_a) {
                curr_a = curr_a->next;
                ++a_size;
            }
            if (curr_b) {
                curr_b = curr_b->next;
                ++b_size;
            }
        }
        
        curr_a = headA, curr_b = headB;
        for (int i = 0; i < abs(b_size-a_size); ++i) {
            if (b_size > a_size) {
                curr_b = curr_b->next;
            } else {
                curr_a = curr_a->next;
            }
        }
        
        while (curr_a && curr_b && curr_a != curr_b)
            curr_a = curr_a->next, curr_b = curr_b->next;
        
        return curr_a == curr_b ? curr_a : NULL;
    }
};
