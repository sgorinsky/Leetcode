class Solution {
    public ListNode swapPairs(ListNode head) {
        if (head == null || head.next == null) return head;
        ListNode prev = head, curr = head.next;
        head = head.next;
        
        while (prev != null && prev.next != null) {
            ListNode after = curr.next;
            
            curr.next = prev;
            prev.next = after != null && after.next != null ? after.next : after;
            
            curr = prev.next;
            prev = after;
        }
        return head;
    }
}
