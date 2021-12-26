class Solution {
public:
    bool isValidBST(TreeNode* root) {
        vector<int> v;
        this->inOrderTraverse(root, v);
        for (int i = 0; i < v.size() - 1; i++) {
            if (v[i + 1] <= v[i]) {
                return false;
            }
        }
        return true;
    }
    
    void inOrderTraverse(TreeNode* root, vector<int>& v) {
        if (root) {
            inOrderTraverse(root->left, v);
            v.push_back(root->val);
            inOrderTraverse(root->right, v);
        }
    }
};