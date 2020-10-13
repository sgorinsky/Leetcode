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
    public ListNode sortList(ListNode head) {
        int length = 1;
        ListNode curr = head;
        while (curr != null) {
            curr = curr.next;
            length++;
        }
        return splitAndMerge(head, length);
    }
    
    public ListNode splitAndMerge(ListNode head, int length) {
        if (head == null || length == 1) return head;
        
        int half = length / 2, idx = 0;
        ListNode curr = head, prev = null;
        while (curr != null && idx < half) {
            prev = curr;
            curr = curr.next;
            idx++;
        }
        
        if (prev != null) prev.next = null;
        head = splitAndMerge(head, half);
        curr = splitAndMerge(curr, half % 2 == 1 ? half + 1 : half);
        
        return mergeTwoLists(head, curr);
    }
    
    public ListNode mergeTwoLists(ListNode firstList, ListNode secondList) {
        if (firstList == null || secondList == null) return firstList != null ? firstList : secondList;
        else if (firstList.val > secondList.val) return mergeTwoLists(secondList, firstList);
        
        firstList.next = mergeTwoLists(firstList.next, secondList);
        return firstList;
    }
    
}
