/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class CBTInserter { // Run BFS and insert nodes in to NodeList who has no right child cause the given tree is a complete Binary tree.
public:
    queue<TreeNode *> NodeList;
    TreeNode* rootNode;
    
    CBTInserter(TreeNode* root) {
        rootNode = root;
        queue<TreeNode *> Q;
        TreeNode* node;
        Q.push(root);
        while (!Q.empty()) {
            node = Q.front();
            Q.pop();

            if (!node->right)
                NodeList.push(node);
            
            if (node->left)
                Q.push(node->left);
            if (node->right)
                Q.push(node->right);                
        }        
    }
    
    int insert(int v) {
        TreeNode * node = NodeList.front();
        TreeNode * new_node = new TreeNode(v); 
        if (!node->left)
            node->left = new_node;
        else if(!node->right)
            node->right = new_node;
        
        if (node->left && node->right)
            NodeList.pop();
        
        NodeList.push(new_node);
        
        return node->val;
    }
    
    TreeNode* get_root() {
        return rootNode;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */