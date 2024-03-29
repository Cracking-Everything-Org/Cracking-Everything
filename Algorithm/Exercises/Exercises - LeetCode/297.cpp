/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        return helperSerialize(root, "");
    }
    
    string helperSerialize(TreeNode* root, string str) {
        if (!root) {
            str += "null,";
        } else {
            str += to_string(root->val) + ",";
            str = helperSerialize(root->left, str);
            str = helperSerialize(root->right, str);
        }
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> dataList = split(data, ",");
        return helperDeserialize(dataList);
    }
    
    TreeNode* helperDeserialize(vector<string> dataList) {
        if (dataList[0] == "null") {
            removeFirst(dataList);
            return NULL;
        }
        TreeNode* root = new TreeNode(dataList[0]->val);
        removeFirst(dataList);
        root->left = helperDeserialize(dataList); 
        root->right = helperDeserialize(dataList);      
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));