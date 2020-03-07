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
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        int min = 1;
        queue<TreeNode*> Q;
        Q.push(root);
        while(!Q.empty()){
            int size = Q.size();
            for(int i=0; i<size; i++){
                TreeNode* curr = Q.front();
                Q.pop();
                if(!curr->left && !curr->right){
                    return min;
                }
                if(curr->left) Q.push(curr->left);
                if(curr->right) Q.push(curr->right);
            }
            min++;
        }
        return -1;
    }
};
