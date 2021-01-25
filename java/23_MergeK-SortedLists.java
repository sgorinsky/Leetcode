class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        PriorityQueue<int[]> pq = new PriorityQueue<int[]>((a, b) -> a[0] - b[0]);
        ListNode sentinel = new ListNode(0);
        ListNode curr = sentinel;
        
        for (int i = 0; i < lists.length; ++i) {
            if (lists[i] != null)
                pq.add(new int[]{lists[i].val, i});
        }
        
        while (!pq.isEmpty()) {
            int[] pair = pq.poll();
            int val = pair[0], i = pair[1];
            curr.next = new ListNode(val);
            curr = curr.next;
            if (lists[i].next != null) {
                lists[i] = lists[i].next;
                pq.add(new int[]{lists[i].val, i});
            }
        }
        return sentinel.next;
    }
}

class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        if (lists.length == 0) 
            return null;
        
        return splitAndMerge(lists, 0, lists.length - 1);
    }
    
    public ListNode splitAndMerge(ListNode[] lists, int start, int end) {
        if (start >= end)
            return lists[start];
        
        int mid = start + (end - start) / 2;
        ListNode left = splitAndMerge(lists, start, mid);
        ListNode right = splitAndMerge(lists, mid + 1, end);
        
        return merge(left, right);
    }
    
    public ListNode merge(ListNode a, ListNode b) {
        if (a == null || b == null)
            return a == null ? b : a;
        else if (a.val > b.val)
            return merge(b, a);
        
        a.next = merge(a.next, b);
        return a;
    }
}

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
    public ListNode mergeKLists(ListNode[] lists) {
        if (lists.length == 0) 
            return null;
        
        ListNode curr = lists[0];
        for (int i = 1; i < lists.length; ++i)
            curr = merge(curr, lists[i]);
        
        return curr;
    }
    
    public ListNode merge(ListNode a, ListNode b) {
        if (a == null || b == null)
            return a == null ? b : a;
        else if (a.val > b.val)
            return merge(b, a);
        
        a.next = merge(a.next, b);
        return a;
    }
}
