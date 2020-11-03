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
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next) return head;
        
        ListNode* insert = head->next;
        ListNode* prev = head;
        while (insert) {
            ListNode* curr = head;
            ListNode* currPrev = NULL;
            while (curr != insert) {
                if (insert->val < curr->val) {
                    if (!currPrev) {
                        currPrev = insert;
                        head = currPrev;
                    } else {
                        currPrev->next = insert;
                    }
                    prev->next = insert->next;
                    insert->next = curr;
                    break;
                }
                currPrev = curr;
                curr = curr->next;
            }
            if (curr == insert) {
                prev = insert;
                insert = insert->next;
            } else {
                insert = prev->next;
            }
        }
        return head;
    }
};
