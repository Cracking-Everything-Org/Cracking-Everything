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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (!s || !t) return false;
        if (s->val == t->val) {
            return isSubtreeAux(s, t)
                || isSubtree(s->right, t)
                || isSubtree(s->left, t);
        }
        else {
            return isSubtree(s->right, t)
                || isSubtree(s->left, t);
        }
    }

    bool isSubtreeAux(TreeNode* s, TreeNode* t) {
        if (!s && !t) return true;
        if (!s || !t) return false;
        if (s->val != t->val) return false;
        return isSubtreeAux(s->left, t->left)
            && isSubtreeAux(s->right, t->right);
    }

};
