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
    bool checkSubtree(TreeNode* s, TreeNode* t) {
        if(!s && !t) return true;
        if(!s || !t) return false;
        return (s->val == t->val)
            && checkSubtree(s->left,t->left)
            && checkSubtree(s->right,t->right);
    }

    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(!s) return false;
        if(t->val == s->val) return checkSubtree(s,t);
        return isSubtree(s->left,t) || isSubtree(s->right,t);
    }
};
