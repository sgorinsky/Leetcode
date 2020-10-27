public class Solution {
    public ListNode detectCycle(ListNode head) {
        ListNode tortoise = head, hare = head;
        do {
            if (hare == null || hare.next == null) return null;
            tortoise = tortoise.next;
            hare = hare.next.next;
        } while (tortoise != hare);
        
        tortoise = head;
        while (tortoise != hare) {
            hare = hare.next;
            tortoise = tortoise.next;
        }
        return hare;
    }
}

/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode detectCycle(ListNode head) {
        ListNode slow = head;
        ListNode fast = head;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
            if (fast == slow) {
                break;
            }
        }
        if (fast == null || fast.next == null) {
            return null;
        }
        slow = head;
        while (slow != fast) {
            slow = slow.next;
            fast = fast.next;
        }
        
        return slow;
    }
}
