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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(!root) return result;
        queue<TreeNode*> queue;
        queue.push(root);
        bool fromLeft = true;
        while(!queue.empty()){
            int size = queue.size();
            vector<int> currentLevel(size);
            for(int i=0; i<size; i++){
                TreeNode* currentNode = queue.front();
                queue.pop();
                if(currentNode->left) queue.push(currentNode->left);
                if(currentNode->right) queue.push(currentNode->right);

                if(fromLeft) {
                    currentLevel[i] = currentNode->val;
                } else {
                    currentLevel[size - 1 - i] = currentNode->val;
                }
            }
            result.push_back(currentLevel);
            fromLeft = !fromLeft;
        }
        return result;
    }
};
