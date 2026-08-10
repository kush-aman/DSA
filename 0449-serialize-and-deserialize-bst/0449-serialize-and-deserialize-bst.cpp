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
        if(!root) return "";

        queue<TreeNode*> q;
        string ans = "";
        q.push(root);
        while(!q.empty()){
            TreeNode* current = q.front();
            q.pop();
            if(!current) ans.append("#,");
            else ans.append(to_string(current -> val)+',');
            if(current != NULL){
                q.push(current -> left);
                q.push(current -> right);
            }
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0) return NULL;
        string str;
        stringstream s(data);
        getline(s, str, ',');
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* cur = q.front();
            q.pop();

            getline(s, str, ',');
            if(str == "#"){
                cur -> left = NULL;
            }
            else{
                TreeNode* nodeLeft = new TreeNode(stoi(str));
                cur -> left = nodeLeft;
                q.push(nodeLeft); 
            }

            getline(s, str, ',');
            if(str == "#"){
                cur -> right = NULL;
            }
            else{
                TreeNode* nodeRight = new TreeNode(stoi(str));
                cur -> right = nodeRight;
                q.push(nodeRight);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;