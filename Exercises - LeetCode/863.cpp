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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        vector<int> ans;
        if(!root || !target) return ans;
        unordered_map<TreeNode*, TreeNode*> parents;
        fillParents(root, parents);
        unordered_set<TreeNode*> visited;

        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(target,0));
        while(!q.empty()) {
            pair<TreeNode*, int> current = q.front();
            q.pop();
            visited.insert(current.first);
            if (current.second == K) {
                ans.push_back(current.first->val);
            } else {
                if (current.first->left && visited.find(current.first->left) == visited.end()) {
                    q.push(make_pair(current.first->left, current.second + 1));
                }
                if (current.first->right && visited.find(current.first->right) == visited.end()) {
                    q.push(make_pair(current.first->right, current.second + 1));
                }
                if (parents.find(current.first) != parents.end() && visited.find(parents[current.first]) == visited.end()) {
                    q.push(make_pair(parents[current.first], current.second + 1));
                }
            }
        }
        return ans;
    }

    void fillParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parents) {
        if(!root || (!root->left && !root->right)) return ;
        else {
            if(root->left) {
                parents[root->left] = root;
            }
            if(root->right) {
                parents[root->right] = root;
            }
            fillParents(root->left, parents);
            fillParents(root->right, parents);
        }
    }

};
