class Solution {
    public ListNode swapNodes(ListNode head, int k) {
        int idx = 0;
        ListNode curr = head, temp = curr;
        while (curr != null) {
            if (++idx == k)
                temp = curr;
            curr = curr.next;
        }
        
        int sz = idx;
        curr = head;
        for (int i = 0; i < sz - k; ++i) curr = curr.next;
        
        int currVal = curr.val;
        curr.val = temp.val;
        temp.val = currVal;
        
        return head;
    }
}
