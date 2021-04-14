class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        unordered_set<Node*> ps;
        unordered_set<Node*> qs;
        while (p || q) {
            ps.insert(p);
            qs.insert(q);
            if (ps.find(q) != ps.end()) return q;
            if (qs.find(p) != qs.end()) return p;
            if (q) q = q->parent;
            if (p) p = p->parent;
        }
        return NULL;
    }
};