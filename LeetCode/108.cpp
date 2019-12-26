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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return convert(nums, 0, nums.size()-1);
    }

    TreeNode* convert(vector<int>& nums, int low, int high) {
        if(low>high) return NULL;
        int mid = (low+high)/2;
        TreeNode* t = new TreeNode(nums[mid]);
        t->left = convert(nums, low, mid-1);
        t->right = convert(nums, mid+1, high);
        return t;
    }
};
