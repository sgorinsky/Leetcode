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
        if (!root) return "";
        string serialized_str = to_string(root->val);
        vector<TreeNode*> stack = {root};
        
        // iterative dfs
        while (!stack.empty()) {
            TreeNode* curr = stack.back();
            stack.pop_back();
            
            if (curr) {
                // serialized string takes left and right of curr node
                serialized_str += curr->left ? " " + to_string(curr->left->val) : " N";
                serialized_str += curr->right ? " " + to_string(curr->right->val) : " N";
                stack.push_back(curr->right);
                stack.push_back(curr->left);
            }
        }
        return serialized_str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "") return NULL;
        
        int i = 0; // deserialization pointer for data
        
        // get root val
        string num = "";
        while (data[i] != ' ')
            num += data[i++];
        i++;
        
        TreeNode* root = new TreeNode(stoi(num));
        vector<TreeNode*> stack = {root};
        
        while (i < data.length() && !stack.empty()) {
            TreeNode* curr = stack.back();
            stack.pop_back();
            
            // build left node
            string left = "";
            while (i < data.length() && data[i] != ' ')
                left += data[i++];
            ++i;
            
            // build right node
            string right = "";
            while (i < data.length() && data[i] != ' ')
                right += data[i++];
            ++i;
            
            if (right != "" && right != "N") {
                curr->right = new TreeNode(stoi(right));
                stack.push_back(curr->right);
            }
            if (left != "" && left != "N") {
                curr->left = new TreeNode(stoi(left));
                stack.push_back(curr->left);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
