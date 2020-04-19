/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if (!head) {
            Node* newNode = new Node(insertVal);
            newNode->next = newNode;
            return newNode;
        }

        Node* dummy = head;
        Node* previous = head;
        Node* current = head->next;

        while (current) {
            if (current == dummy
                || (previous->val > current->val && current->val > insertVal)
                || (previous->val <= insertVal && current->val > insertVal)
                || (previous->val <= insertVal && previous->val > current->val)) {

                Node* toInsert = new Node(insertVal);
                previous->next = toInsert;
                toInsert->next = current;
                break;
            }
            current = current->next;
            previous = previous->next;
        }

        return dummy;
    }
};
