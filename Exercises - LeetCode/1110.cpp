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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> forest;

        unordered_map<int, bool> toDelete;
        for (int i = 0; i < to_delete.size(); i++) {
            toDelete[to_delete[i]] = true;
        }

        deleteNodes(forest, root, toDelete, false);

        return forest;
    }

    TreeNode* deleteNodes(vector<TreeNode*>& forest, TreeNode* root, unordered_map<int, bool>& toDelete, bool added) {
        if (!root) {
            return NULL;
        }
        if (toDelete.find(root->val) != toDelete.end()) {
            deleteNodes(forest, root->left, toDelete, false);
            deleteNodes(forest, root->right, toDelete, false);
            return NULL;
        } else {
            if (!added) {
                forest.push_back(root);
            }

            root->left = deleteNodes(forest, root->left, toDelete, true);
            root->right = deleteNodes(forest, root->right, toDelete, true);
            return root;
        }
    }
};
