class BSTIterator {
    
private:
    stack<TreeNode*> nodeStack;
    
public:
    BSTIterator(TreeNode *root) {
        while (root) {
            nodeStack.push(root);
            root = root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !nodeStack.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* node = nodeStack.top();
        nodeStack.pop();
        int num = node->val;
        node = node->right;
        while (node) {
            nodeStack.push(node);
            node = node->left;
        }
        
        return num;
    }
};