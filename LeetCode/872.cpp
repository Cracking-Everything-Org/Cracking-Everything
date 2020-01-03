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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        if(!root1 || !root2) return false;
        vector<int> dfs1;
        vector<int> dfs2;
        inorderdfs(root1, dfs1);
        inorderdfs(root2, dfs2);
        int index1 = 0;
        int index2 = 0;
        if(dfs1.size() != dfs2.size()) return false;
        while(index1<dfs1.size() && index2 < dfs2.size()){
            if(dfs1[index1] != dfs2[index2]) return false;
            index1++;
            index2++;
        }
        return true;
    }

    void inorderdfs(TreeNode* root, vector<int>& leaves){
        if(!root) return;
        inorderdfs(root->left, leaves);
        if(!root->left && !root->right) leaves.push_back(root->val);
        inorderdfs(root->right, leaves);
    }
};
