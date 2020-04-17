class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        stack<Node*> stk;

        if (!root)
            return NULL;

        while(root) { // puusheo la diagonal izquierda
            stk.push(root);
            root = root->left;
        }

        Node* head = stk.top(); // reference to the left most node

        Node* node;
        while(!stk.empty()) {
            node = stk.top();
            stk.pop();

            while(node->right) {
                stk.push(node->right);
                node->right = node->right->left;
            }

            if (!stk.empty()) {
                node->right = stk.top();
                stk.top()->left = node;
            }
        }
        node->right = head;
        head->left = node;
        return head;
    }
};
