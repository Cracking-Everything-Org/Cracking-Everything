/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    void binaryAux(vector<string> &results, TreeNode* root, string actual){
        if(!root->left && !root->right){
            results.push_back(actual);
        }
        if(root->left) binaryAux(results, root->left, actual + "->" + to_string(root->left->val));
        if(root->right) binaryAux(results, root->right, actual + "->" +  to_string(root->right->val));
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> results;
        if(!root) return results;
        binaryAux(results, root, to_string(root->val));
        return results;
    }
};
