class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        if (head == null || k == 0) return head;
        
        ListNode curr = head, prev = null;
        int length = 0;
        while (curr != null) {
            length++;
            prev = curr;
            curr = curr.next;
        }
        
        int shift = k % length;
        if (shift == 0) return head;
        
        prev.next = head;
        curr = head;
        while (length - 1 > shift) {
            curr = curr.next;
            length--;
        }
        
        ListNode newHead = curr.next;
        curr.next = null;
        return newHead;
    }
}

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
