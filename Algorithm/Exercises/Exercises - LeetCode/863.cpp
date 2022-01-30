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




class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        vector<int> nodes;
        unordered_set<TreeNode*> visited;
        unordered_map<TreeNode*, TreeNode*> hm;
        buildMap(root, NULL, hm);
        
        int level = 1;
        queue<TreeNode*> q;
        q.push(target);
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* current = q.front();
                if (current) {
                    if (visited.find(current) == visited.end()) {
                        q.pop();
                        if (level == K) {
                            nodes.push_back(current->val);
                        }
                        if (current->left) q.push(current->left);
                        if (current->right) q.push(current->right);
                        q.push(hm[current]);
                    }
                    visited.insert(current);
                }
            }
            level++;
        }
        return nodes;
    }
    
    void buildMap(TreeNode* root, TreeNode* parent, unordered_map<TreeNode*, TreeNode*>& hm) {
        if (root) {
            hm[root] = parent;
            buildMap(root->left, root, hm);
            buildMap(root->right, root, hm);
        }
    }
};
