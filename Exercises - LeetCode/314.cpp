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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        map<int, map<int, vector<int>>> nodes;
        traverse(root, 0, 0, nodes);
        vector<vector<int>> resultList;
        for (auto x : nodes) {
            vector<int> col;
            for (auto y : x.second) {
                col.insert(col.end(), y.second.begin(), y.second.end());
            }
            resultList.push_back(col);
        }
        return resultList;
    }
                                                // x , y, val
    void traverse (TreeNode* root, int x, int y, map<int, map<int, vector<int>>>& nodes) {
        if (root) {
            nodes[x][y].push_back(root -> val);
            traverse(root -> left, x - 1, y + 1, nodes);
            traverse(root -> right, x + 1, y + 1, nodes);
        }
    }
};
