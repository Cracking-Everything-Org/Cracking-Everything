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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> results;
        string current;
        paths(root, results, current);
        return results;
    }

    void paths(TreeNode* root, vector<string>& results, string& current){
        if(!root) return ;
        current += to_string(root->val);
        if(!root->left && !root->right){
            results.push_back(current);
            return ;
        } else {
            current += "->";
        }
        string copy1 = current;
        string copy2 = current;
        paths(root->left, results, copy1);
        paths(root->right, results, copy2);
    }
};
