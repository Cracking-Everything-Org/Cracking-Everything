/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {

        // guardo en un mapa el nodo y su copia, luego hago otra pasada y seteo el next y el random
        unordered_map<Node*, Node*> ht;
        Node* dummy = new Node(-1);
        dummy->next = head;

        while (head != NULL) {
            Node* nodeCopy = new Node(head->val);
            ht[head] = nodeCopy;
            head = head->next;
        }

        head = dummy->next;

        while (head != NULL) {
            Node* copyNode = ht[head];
            copyNode->next = ht[head->next];
            copyNode->random = ht[head->random];
            head = head->next;
        }

        return ht[dummy->next];
    }
};
