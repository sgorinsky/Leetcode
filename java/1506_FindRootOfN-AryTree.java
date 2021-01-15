/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    
    public Node() {
        children = new ArrayList<Node>();
    }
    
    public Node(int _val) {
        val = _val;
        children = new ArrayList<Node>();
    }
    
    public Node(int _val,ArrayList<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    public Node findRoot(List<Node> tree) {
        int parent = 0;
        for (Node node : tree) {
            parent ^= node.val;
            for (Node child : node.children) {
                parent ^= child.val;
            }
        }
        
        for (Node node : tree) {
            if (node.val == parent)
                return node;
        }
        
        return tree.get(0);
    }
}
