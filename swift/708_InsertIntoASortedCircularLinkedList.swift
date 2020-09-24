/**
 * Definition for a Node.
 * public class Node {
 *     public var val: Int
 *     public var next: Node?
 *     public init(_ val: Int) {
 *         self.val = val
 *         self.next = nil
 *     }
 * }
 */

class Solution {
    func insert(_ head: Node?, _ insertVal: Int) -> Node? {
        if head == nil {
            var newHead: Node? = Node(insertVal)
            newHead?.next = newHead
            return newHead
        }
        
        func insertNode(_ currentNode: Node?, _ nextNode: Node?) -> Node? {
            var curr = currentNode, next = nextNode
            var newNode: Node? = Node(insertVal)
            curr?.next = newNode
            newNode?.next = next
            return head
        }

        var curr = head
        while curr != nil {
            var currVal = curr?.val as! Int
            var nextVal = curr?.next?.val as! Int
            if currVal == nextVal {
                var start: Node? = curr
                while curr?.next !== start && currVal == nextVal {
                    curr = curr?.next
                    currVal = curr?.val as! Int
                    nextVal = curr?.next?.val as! Int
                }
                if currVal == nextVal || insertVal == currVal {
                    return insertNode(curr, curr?.next)
                }
            }
            if currVal < nextVal {
                if insertVal >= currVal && insertVal <= nextVal {
                    return insertNode(curr, curr?.next)
                }
            } else if currVal > nextVal {
                if insertVal >= currVal || insertVal <= nextVal {
                    return insertNode(curr, curr?.next)
                }
            }
            curr = curr?.next
        }
        return head
    }
}
