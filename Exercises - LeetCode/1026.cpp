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
    int maxAncestorDiff(TreeNode* root) {
        // Each node will have value between 0 and 100000.
        return maxDiff(root, 100000, 0);
    }

    int maxDiff(TreeNode* r, int mn, int mx) {
      if (r == NULL) return mx - mn;
      mx = max(mx, r->val);
      mn = min(mn, r->val);
      return max(maxDiff(r->left, mn, mx), maxDiff(r->right, mn, mx));
    }
};
