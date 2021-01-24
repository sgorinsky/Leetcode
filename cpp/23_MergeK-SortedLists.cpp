class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto compare = [](pair<int, int> a, pair<int, int> b) {
          return a.first > b.first;  
        };
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compare)> pq(compare);
        int k = lists.size();
        for (int i = 0; i < k; ++i) {
            if (lists[i])
                pq.push({lists[i]->val, i});
        }
        
        ListNode* sentinel = new ListNode(0);
        ListNode* curr = sentinel;
        while (!pq.empty()) {
            pair<int, int> cand = pq.top();
            pq.pop();
            int val = cand.first, idx = cand.second;
            curr->next = new ListNode(val);
            curr = curr->next;
            if (lists[idx]->next) {
                lists[idx] = lists[idx]->next;
                pq.push({lists[idx]->val, idx});
            }
        }
        return sentinel->next;
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* sentinel = new ListNode(0);
        ListNode* curr = sentinel;
        pair<ListNode*, int> curr_min = {new ListNode(INT_MAX), 0};
        while (curr_min.second != -1) {
            curr_min = {new ListNode(INT_MAX), -1};
            for (int i = 0; i < lists.size(); ++i) {
                if (lists[i] && lists[i]->val < curr_min.first->val) {
                    curr_min = {lists[i], i};
                }
            }
            if (curr_min.second != -1) {
                curr->next = new ListNode(curr_min.first->val);
                curr = curr->next;
                lists[curr_min.second] = lists[curr_min.second]->next;
            }
        }
        return sentinel->next;
    }
};
