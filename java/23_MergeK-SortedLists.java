/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        if (lists.length == 0) 
            return null;
        
        ListNode curr = lists[0];
        for (int i = 1; i < lists.length; ++i)
            curr = merge(curr, lists[i]);
        
        return curr;
    }
    
    public ListNode merge(ListNode a, ListNode b) {
        if (a == null || b == null)
            return a == null ? b : a;
        else if (a.val > b.val)
            return merge(b, a);
        
        a.next = merge(a.next, b);
        return a;
    }
}
