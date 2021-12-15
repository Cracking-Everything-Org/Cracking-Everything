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
    Node* cloneGraph(Node* node) {
        if (!node) return NULL;
        
        unordered_map<Node*, Node*> copies;
    
        visitNeighbors(node, copies);
        deepCopy(node, copies);
        
        return copies[node];
    }
    
    void visitNeighbors(Node* node, unordered_map<Node*, Node*>& copies) {
        if (copies.find(node) == copies.end()) {
            copies[node] = new Node(node->val);
            for (auto neighbor : node->neighbors) {
                visitNeighbors(neighbor, copies);
            }
        }
    }
    
    void deepCopy(Node* node, unordered_map<Node*, Node*>& copies) {
        for (auto entry : copies) {
            for (auto neighbor : entry.first->neighbors) {
                entry.second->neighbors.push_back(copies[neighbor]);
            }
        }
    }
};