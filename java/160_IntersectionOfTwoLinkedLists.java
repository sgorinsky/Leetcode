/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        ListNode currA = headA;
        ListNode currB = headB;
        
        int sizeA = 0, sizeB = 0;
        while (currA != null || currB != null) {
            if (currA != null) {
                currA = currA.next;
                ++sizeA;
            }
            if (currB != null) {
                currB = currB.next;
                ++sizeB;
            }
        }
        
        currA = headA;
        currB = headB;
        
        for (int i = 0; i < Math.abs(sizeA - sizeB); ++i) {
            if (sizeA > sizeB)
                currA = currA.next;
            else
                currB = currB.next;
        }
        
        while (currA != currB) {
            currA = currA.next;
            currB = currB.next;
        }
        return currA;
    }
}
