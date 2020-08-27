class ListNode {
    var val: Int!
    var next: ListNode?;
    
    init(_ val: Int) {
        self.val = val
        self.next = nil
    }
}

class MyLinkedList {
    var size: Int
    var head: ListNode?
    
    /** Initialize your data structure here. */
    init() {
        head = nil
        size = 0
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    func getNode(_ index: Int) -> ListNode? {
        if index >= 0 && index < size {
            var curr = head
            var i: Int = 0
            while (curr != nil) {
                if (index == i) {
                    return curr!
                }
                i += 1
                curr = curr?.next
            }
        }
        return nil
    }
    
    func get(_ index: Int) -> Int {
        var node = getNode(index)
        if node == nil {
            return -1
        }
        return (node?.val)!
    }
    
    
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    func addAtHead(_ val: Int) {
        if size == 0 {
            head = ListNode(val)
        } else {
            var newHead = ListNode(val)
            newHead.next = head
            head = newHead
        }
        size += 1
    }
    
    /** Append a node of value val to the last element of the linked list. */
    func addAtTail(_ val: Int) {
        if size > 0 {
            var node = getNode(size-1)
            node?.next = ListNode(val)
        } else {
            head = ListNode(val)
        }
        size += 1
        
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    func addAtIndex(_ index: Int, _ val: Int) {
        if index < 0 || index > size {
            return
        } else if index == 0 {
            addAtHead(val)
        } else if index == size {
            addAtTail(val)
        } else {
            var prev: ListNode! = getNode(index-1)
            var newNode: ListNode! = ListNode(val)
            var next = prev?.next
            
            prev?.next = newNode
            newNode?.next = next
            
            size += 1
        }
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    func deleteAtIndex(_ index: Int) {
        if index < 0 || index >= size {
            return
        } else if index == 0 {
            head = head?.next
        } else {
            var prev: ListNode! = getNode(index-1)
            if index == size-1 {
                prev.next = nil
            } else {
                prev.next = prev?.next?.next
            }
        }
        size -= 1
    }
}

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * let obj = MyLinkedList()
 * let ret_1: Int = obj.get(index)
 * obj.addAtHead(val)
 * obj.addAtTail(val)
 * obj.addAtIndex(index, val)
 * obj.deleteAtIndex(index)
 */
