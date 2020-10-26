class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return node;
        
        Node* clone = new Node(node->val);
        vector<Node*> stack = {node}, clones = {clone};
        unordered_map<Node*, Node*> visited;
        
        while (!stack.empty()) {
            Node* curr = stack.back();
            Node* currClone = clones.back();
            visited[curr] = currClone;
            
            stack.pop_back();
            clones.pop_back();
            for (Node* nei : curr->neighbors) {
                if (visited.find(nei) == visited.end()) {
                    Node* neiClone = new Node(nei->val);
                    currClone->neighbors.push_back(neiClone);
                    stack.push_back(nei);
                    visited[nei] = neiClone;
                    clones.push_back(neiClone);
                } else {
                    currClone->neighbors.push_back(visited[nei]);
                }
            }
        }
        return clone;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return NULL;
        
        unordered_map<Node*, Node*> node_clones;
        Node* clone = new Node(node->val);
        node_clones[node] = clone;
        
        queue<Node*> q;
        q.push(node);
        while (!q.empty()) {
            Node* curr = q.front();
            Node* curr_clone = node_clones[curr];
            q.pop();
            
            for (Node* nei : curr->neighbors) {
                if (node_clones.find(nei) == node_clones.end()) {
                    Node* clone_nei = new Node(nei->val);
                    node_clones[nei] = clone_nei;
                    curr_clone->neighbors.push_back(clone_nei);
                    q.push(nei);
                } else {
                    curr_clone->neighbors.push_back(node_clones[nei]);
                }
            }
        }
        return clone;
    }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> clone_map;
    Node* cloneGraph(Node* node) {
        if (!node) return NULL;
        Node* clone = new Node(node->val);
        clone_map[node] = clone;
        return checkNeighbors(node, clone);
    }
    
    Node* checkNeighbors(Node* node, Node* clone) {
        for (Node* nei : node->neighbors) {
            if (clone_map.find(nei) == clone_map.end()) {
                Node* clone_nei = new Node(nei->val);
                clone_map[nei] = clone_nei;
                clone->neighbors.push_back(clone_nei);
                checkNeighbors(nei, clone_nei);
            } else {
                clone->neighbors.push_back(clone_map[nei]);
            }
        }
        return clone;
    }
};
