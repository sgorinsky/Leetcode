class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = l1;
        ListNode* curr = l1;
        ListNode* prev = NULL;
        int remainder = 0;
        while (l1 || l2) {
            int sum = remainder;
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            int digit = sum % 10;
            remainder = sum / 10;
            
            curr->val = digit;
            curr->next = l1 ? l1 : l2;
            prev = curr;
            curr = curr->next;
        }
        if (remainder == 1) {
            ListNode* end = new ListNode(remainder);
            prev->next = end;
        }
        return head;
    }
};

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return add_lists(l1, l2, false);
    }
    
    ListNode* add_lists(ListNode* l1, ListNode* l2, bool carry) {
        if (!l1 && !l2) {
            if (carry)
                l1 = new ListNode(1);
            return l1;
        } else if (!l1) {
            return add_lists(l2, l1, carry);
        } else if (!l2) {
            int v = l1->val + (carry ? 1 : 0);
            l1->val = v % 10;
            if (v >= 10) {
                l1->next = add_lists(l1->next, l2, true);
            }
            return l1;
        }
        
        int sum = l1->val + l2->val + (carry ? 1 : 0);
        l1->val = sum % 10;
        l1->next = add_lists(l1->next, l2->next, sum >= 10);
        
        return l1;
    }
};
