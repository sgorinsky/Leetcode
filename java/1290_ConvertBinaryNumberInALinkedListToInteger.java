 */
class Solution {
    public int getDecimalValue(ListNode head) {
        ListNode curr = head;
        int n = 0;
        while (curr != null) {
            n <<= 1;
            n += curr.val;
            curr = curr.next;
        }
        return n;
    }
}
