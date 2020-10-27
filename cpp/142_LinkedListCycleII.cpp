class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* tortoise = head;
        ListNode* hare = head;
        do {
            if (!hare || !hare->next) return NULL;
            tortoise = tortoise->next;
            hare = hare->next->next;
        } while (tortoise != hare);
        
        tortoise = head;
        while (tortoise != hare) {
            tortoise = tortoise->next;
            hare = hare->next;
        }
        return hare;
    }
};

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
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> nodes;
        ListNode *curr = head;
        
        while (curr) {
            if (nodes.find(curr) != nodes.end())
                return curr;
            nodes.insert(curr);
            curr = curr->next;
        }
        return NULL;
    }
};
