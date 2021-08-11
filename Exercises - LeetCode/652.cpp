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
class Solution {
public:
    vector<TreeNode*> ans;
    unordered_map<string, int> mp; 
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        inorder(root);
        return ans;
    }
    
    string inorder(TreeNode* root) {
        if (!root) {
            return "";
        }
        
        string str = "{" + inorder(root->left) + to_string(root->val) + inorder(root->right) + "}";
        mp[str]++;
        
        if (mp[str] == 2) {
            ans.push_back(root);
        }
        
        return str;
    }
};