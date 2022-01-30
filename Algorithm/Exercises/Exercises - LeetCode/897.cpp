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
    TreeNode* increasingBST(TreeNode* root) {
        if(!root) return NULL;
        vector<int> inorderList;
        inorderDFS(root, inorderList);
        TreeNode* result = new TreeNode(-1);
        createTree(inorderList, result);
        return result->right;
    }

    void inorderDFS(TreeNode* root, vector<int>& list){
        if(!root) return;
        inorderDFS(root->left, list);
        list.push_back(root->val);
        inorderDFS(root->right, list);
    }

    void createTree(vector<int> list, TreeNode* result){
        for(int i :list){
            result->right = new TreeNode(i);
            result = result->right;
        }
    }
};
