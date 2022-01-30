class Solution {
public:
    Node* first = NULL;
    Node* prev = NULL; 

    Node* treeToDoublyList(Node* root) {
        if (!root) return root; 
        inOrder(root);
        prev->right = first;
        first->left = prev;
        return first;
    }

    void inOrder(Node* root){
        if (root == NULL) return; 
        inOrder(root->left);
        if (first == NULL) first = root;        
        if (prev != NULL){
            prev->right= root;
            root->left = prev;
        } 
        prev = root; 
        inOrder(root->right);
    }
};