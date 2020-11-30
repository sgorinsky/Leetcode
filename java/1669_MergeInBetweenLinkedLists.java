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
    public ListNode mergeInBetween(ListNode list1, int a, int b, ListNode list2) {
        int i = 1;
        ListNode curr = list1;
        while (i < a) {
            curr = curr.next;
            i++;
        }
        
        ListNode temp = curr.next;
        ListNode head = list1;
        if (a > 0) curr.next = list2;
        else head = list2;
        
        while (i < b) {
            temp = temp.next;
            i++;
        }
        
        ListNode second = list2;
        while (second.next != null) {
            second = second.next;
        }
        
        second.next = temp.next;
        return head;
    }
}
