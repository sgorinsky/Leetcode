class Solution {

    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    ListNode head;
    public Solution(ListNode head) {
        this.head = head;
    }
    
    /** Returns a random node's value. */
    public int getRandom() {
        ListNode curr = head;
        int changingSz = 1, chosen = 0;
        while (curr != null) {
            if (Math.random() < 1.0 / changingSz++) chosen = curr.val;
            curr = curr.next;
        }
        return chosen;
    }
}
