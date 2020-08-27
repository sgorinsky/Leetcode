class Node {
    int val;
    Node next;
    
    public Node(int v) {
        val = v;
        next = null;
    }
}

class MyLinkedList {
    
    Node head;
    int size;
    /** Initialize your data structure here. */
    public MyLinkedList() {
        head = null;
        size = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    public void printNodes() {
        Node curr = head;
        System.out.println("Size of list: " + size);
        System.out.println("Printing nodes...");
        while (curr != null) {
            System.out.println(curr.val);
            curr = curr.next;
        }
    }
    public int get(int index) {
        if (index == 0) {
            return head != null ? head.val : -1;
        } else if (index >= 0 &&  index < size) {
            Node curr = head;
            int i = 0;
            while (curr != null) {
                if (index == i++) {
                    return curr.val;
                }
                curr = curr.next;
            }
        }
        return -1;
    }
    
    public Node getNode(int index) {
        if (index == 0) {
            return head != null ? head : null;
        } else if (index >= 0 &&  index < size) {
            Node curr = head;
            int i = 0;
            while (curr != null) {
                if (index == i++) {
                    return curr;
                }
                curr = curr.next;
            }
        }
        return null;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    public void addAtHead(int val) {
        if (size == 0) {
            head = new Node(val);
        } else {
            Node newHead = new Node(val);
            newHead.next = head;
            head = newHead;
        }
        ++size;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    public void addAtTail(int val) {
        if (size <= 0) {
            head = new Node(val);
        } else {
            Node last = new Node(val);
            Node curr = head;
            while (curr != null) {
                if (curr.next == null) {
                    curr.next = last;
                    break;
                }
                curr = curr.next;
            }
        }
        ++size;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    public void addAtIndex(int index, int val) {
        if (index < 0 || index > size) {
            return;
        } else if (index == 0) {
            addAtHead(val);
        } else if (index == size) {
            addAtTail(val);
        } else {
            Node prev = getNode(index-1);
            Node next = prev.next;
            Node newNode = new Node(val);
            prev.next = newNode;
            newNode.next = next;
            ++size;
        }
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    public void deleteAtIndex(int index) {
        if (index < 0 || index >= size) {
            return;
        } else if (index == 0 && head != null) {
            head = head.next;
        } else {
            Node prev = getNode(index-1);
            if (index == size-1) {
                prev.next = null;
            } else {
                prev.next = prev.next.next;
            }
        }
        --size;
    }
}

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */
