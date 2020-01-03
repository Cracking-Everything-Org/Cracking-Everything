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
    TreeNode* inser(int l, int r, vector<int>& v) {
        if (l > r) return NULL;
		else if (l == r) return new TreeNode(v[l]);
		int mid = l + (r - l) / 2;
		TreeNode* root = new TreeNode(v[mid]);
		root->left = inser(l, mid - 1, v);
		root->right = inser(mid + 1, r, v);
		return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return inser(0, nums.size()-1, nums);
    }
};
