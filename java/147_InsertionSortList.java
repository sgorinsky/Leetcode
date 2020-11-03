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
    public ListNode insertionSortList(ListNode head) {
        if (head == null || head.next == null) return head;
        
        ListNode newHead = null;
        ListNode curr = head, next = head.next;
        while (curr != null) {
            ListNode checker = newHead, prevChecker = null;
            next = curr.next;
            if (checker  == null) {
                newHead = curr;
                curr.next = null;
            } else {
                while (checker != null) {
                    if (curr.val < checker.val) {
                        if (prevChecker == null) {
                            prevChecker = curr;
                            curr.next = newHead;
                            newHead = curr;
                        } else {
                            prevChecker.next = curr;
                            curr.next = checker;
                        }
                        break;
                    }
                    prevChecker = checker;
                    checker = checker.next;
                }
                if (checker == null) {
                    prevChecker.next = curr;
                    curr.next = null;
                }
            }
            curr = next;
        }
        return newHead;
    }
}
