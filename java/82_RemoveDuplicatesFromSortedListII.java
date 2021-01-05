class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        ListNode sentinel = new ListNode(0), prev = sentinel, curr = head;
        sentinel.next = head;
        while (curr != null && curr.next != null) {
            if (curr.val == curr.next.val) {
                ListNode tmp = curr.next;
                while (tmp != null && tmp.val == curr.val) tmp = tmp.next;
                
                prev.next = tmp;
                curr = prev.next;
            } else {
                prev = curr;
                curr = curr.next;
            }
        }
        return sentinel.next;
    }
}
