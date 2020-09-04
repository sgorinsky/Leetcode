/*
// Definition for a Node.
class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}
*/

class Solution {
    public Node copyRandomList(Node head) {
        if (head == null) return head;
        Node curr = head;
        Node node;
        
        // create new nodes and interleave list
        while (curr != null) {
            node = new Node(curr.val);
            node.next = curr.next;
            curr.next = node;
            curr = node.next;
        }
        
        // have cloned node random pointers reference cloned nodes
        curr = head;
        Node copy;
        while (curr != null) {
            copy = curr.next;
            copy.random = curr.random != null ? curr.random.next : null;
            curr = copy.next;
            copy = curr != null ? curr.next : null;
        }
        
        curr = head;
        copy = head.next;
        Node newHead = copy;
        while (curr != null) {
            curr.next = copy.next;
            curr = curr.next;
            copy.next = curr != null ? curr.next : null;
            copy = copy.next;
        }
        return newHead;
    }
}
