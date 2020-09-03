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
    public ListNode rotateRight(ListNode head, int k) {
        if (k == 0 || head == null || head.next == null)
            return head;
        
        int N = 0;
        ListNode curr = head;
        ListNode end = head;
        while (curr != null) {
            if (curr.next == null)
                end = curr;
            curr = curr.next;
            ++N;
        }
        
        if (k % N == 0)
            return head;
        
        curr = head;
        ListNode newHead = head;
        int newHeadIdx = N - k % N;
        int i = 0;
        while (i < N-1) {
            if (i == newHeadIdx-1) {
                ListNode temp = curr;
                curr = curr.next;
                temp.next = null;
                newHead = curr;
                break;
            }
            ++i;
            curr = curr.next;
        }
        end.next = head;
        return newHead;
    }
}
