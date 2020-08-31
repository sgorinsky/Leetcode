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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        return addNodes(l1, l2, false);
    }
    public ListNode addNodes(ListNode l1, ListNode l2, boolean carry) {
        if (l1 == null && l2 == null) {
            return carry ? new ListNode(1) : null;
        } else if (l1 == null) {
            return addNodes(l2, l1, carry);
        }
        
        int sum = l1.val + (l2 == null ? 0 : l2.val) + (carry ? 1 : 0);
        l1.val = sum % 10;
        l1.next = addNodes(l1.next, l2 == null ? l2 : l2.next, sum >= 10);
        return l1;
    }
}
