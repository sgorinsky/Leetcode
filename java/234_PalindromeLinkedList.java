class Solution {
    ListNode front;
    public boolean isPalindrome(ListNode head) {
        front = head;
        return checkRecursively(head);
    }
    
    public boolean checkRecursively(ListNode curr) {
        if (curr != null) {
            if (!checkRecursively(curr.next))
                return false;
            if (curr.val != front.val)
                return false;
            front = front.next;
        }
        return true;
    }
}
