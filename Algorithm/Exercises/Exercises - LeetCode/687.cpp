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
	int longestUnivaluePath(TreeNode* root) {
		if (!root) return 0;
		int previousMax = 0;
		lupAux(root, previousMax);
		return previousMax;
	}

	int lupAux(TreeNode* root, int& previousMax) {
		int l = root->left ? lupAux(root->left, previousMax) : 0;
		int r = root->right ? lupAux(root->right, previousMax) : 0;

		l = root->left && root->left->val == root->val ? l + 1 : 0;
		r = root->right && root->right->val == root->val ? r + 1 : 0;

		previousMax = max(previousMax, l + r);
		return max(l, r);
	}
};