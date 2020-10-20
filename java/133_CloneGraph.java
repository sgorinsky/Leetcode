class Solution {
    public Node cloneGraph(Node node) {
        if (node == null) return null;
        
        Node clone = new Node(node.val);
        
        HashMap<Node, Node> clonedNodesMap = new HashMap<Node, Node>();
        clonedNodesMap.put(node, clone);
        
        Queue<Node> q = new LinkedList<Node>();
        q.add(node);
        while (!q.isEmpty()) {
            Node curr = q.poll();
            Node clonedCurr = clonedNodesMap.get(curr);
            
            for (Node nei : curr.neighbors) {
                if (clonedNodesMap.get(nei) == null) {
                    Node clonedNeighbor = new Node(nei.val);
                    clonedNodesMap.put(nei, clonedNeighbor);
                    clonedCurr.neighbors.add(clonedNeighbor);
                    q.add(nei);
                } else {
                    clonedCurr.neighbors.add(clonedNodesMap.get(nei));
                }
            }
        }
        return clone;
    }
}

/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> neighbors;
    
    public Node() {
        val = 0;
        neighbors = new ArrayList<Node>();
    }
    
    public Node(int _val) {
        val = _val;
        neighbors = new ArrayList<Node>();
    }
    
    public Node(int _val, ArrayList<Node> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
}
*/

class Solution {
    HashMap<Node, Node> clonedNodesMap;
    public Node cloneGraph(Node node) {
        if (node == null) return null;
        
        Node clone = new Node(node.val);
        clonedNodesMap = new HashMap<Node, Node>();
        clonedNodesMap.put(node, clone);
        
        return dfs(node, clone);
    }
    
    public Node dfs(Node node, Node clone) {
        for (Node nei : node.neighbors) {
            if (clonedNodesMap.get(nei) == null) {
                Node clonedNeighbor = new Node(nei.val);
                clonedNodesMap.put(nei, clonedNeighbor);
                clone.neighbors.add(clonedNeighbor);
                dfs(nei, clonedNeighbor);
            } else {
                clone.neighbors.add(clonedNodesMap.get(nei));
            }
        }
        return clone;
    }
}
