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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> results;
        if(!root) return results;
        queue<TreeNode*> Q;
        Q.push(root);
        while(!Q.empty()){
            vector<int> currentLevel;
            int size = Q.size();
            for(int i=0; i<size; i++){
                TreeNode* current = Q.front();
                Q.pop();
                currentLevel.push_back(current->val);
                if(current->left) Q.push(current->left);
                if(current->right) Q.push(current->right);
            }
            results.push_back(currentLevel);
        }
        reverse(results.begin(), results.end());
        return results;
    }
};
