/*
// Definition for a Node.
class Node {
    public int val;
    public Node next;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, Node _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
    public Node insert(Node head, int insertVal) {
        if (head == null) {
            Node node = new Node(insertVal);
            node.next = node;
            return node;
        }
        Node curr = head;
        while (curr != null) {
            int currVal = curr.val, nextVal = curr.next.val;
            if (currVal == nextVal) {
                if (insertVal == currVal) {
                    insertNext(curr, curr.next, insertVal);
                    return head;
                }
                Node start = curr;
                while (currVal == nextVal && start != curr.next) {
                    curr = curr.next;
                    currVal = curr.val;
                    nextVal = curr.next.val;
                }
                if (curr.next == start) {
                    insertNext(curr, curr.next, insertVal);
                    return head;
                }
            }
            
            if (currVal < nextVal) {
                if (currVal <= insertVal && insertVal <= nextVal) {
                    insertNext(curr, curr.next, insertVal);
                    return head;
                }
            } else if (currVal > nextVal) {
                if (currVal <= insertVal || nextVal >= insertVal) {
                    insertNext(curr, curr.next, insertVal);
                    return head;
                }
            }
            curr = curr.next;
        }
        return head;
    }
    
    public Node insertNext(Node curr, Node next, int insertVal) {
        Node node = new Node(insertVal);
        node.next = next;
        curr.next = node;
        return node;
    }
}
