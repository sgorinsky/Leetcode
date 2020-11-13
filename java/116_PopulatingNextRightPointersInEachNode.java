class Solution {
    public Node connect(Node root) {
        if (root == null) return root;
        Queue<Node> q = new LinkedList<Node>() {{
            add(root);
        }};
        while (!q.isEmpty()) {
            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                Node curr = q.poll();
                if (curr.left != null) q.add(curr.left);
                if (curr.right != null) q.add(curr.right);
                if (i < sz - 1) curr.next = q.peek();
            }
        }
        return root;
    }
}

/*
// Definition for a Node.
class Node {
    public int val;
    public Node left;
    public Node right;
    public Node next;

    public Node() {}
    
    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, Node _left, Node _right, Node _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/

class Solution {
    public Node connect(Node root) {
        if (root == null)
            return null;
        
        Deque<Node> q = new ArrayDeque<Node>(){{
                addFirst(root);
        }};
        while (!q.isEmpty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                Node node = q.pollFirst();
                if (node.left != null)
                    q.addLast(node.left);
                if (node.right != null)
                    q.addLast(node.right);
                
                node.next = i == size - 1 ? null : q.peekFirst();
            }
        }
        return root;
    }
}
