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
        int first_length = length(l1);
        int second_length = length(l2);
        if (first_length < second_length) {
            for (int i = 0; i < second_length - first_length; ++i) {
                ListNode* newHead = new ListNode(0);
                newHead->next = l1;
                l1 = newHead;
            }
        } else {
            for (int i = 0; i < first_length - second_length; ++i) {
                ListNode* newHead = new ListNode(0);
                newHead->next = l2;
                l2 = newHead;
            }
        }
        
        int carry = modifyListNodes(l1, l2);
        if (carry == 1) {
            ListNode* newHead = new ListNode(1);
            newHead->next = l1;
            l1 = newHead;
        }
        return l1;
    }
    
    int length(ListNode* lst) {
        int l = 0;
        ListNode* curr = lst;
        while (curr) {
            curr = curr->next;
            l++;
        }
        return l;
    }
    
    int modifyListNodes(ListNode* l1, ListNode* l2) {
        if (!l1->next && !l2->next) {
            int total = (l1->val + l2->val);
            l1->val = total % 10;
            return total / 10;
        } else if (!l2->next) {
            return modifyListNodes(l1->next, l2);
        }
        
        int carry = modifyListNodes(l1->next, l2->next);
        
        int total = l1->val + l2->val + carry;
        l1->val = total % 10;
        return total / 10;
    }
};
