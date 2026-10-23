/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> nodes;
        q.push(root);
        while(!q.empty()){
            auto p = q.front();
            nodes.push_back(p -> val);
            q.pop();
            if(p -> left){
                q.push(p -> left);
            }
            if(p -> right){
                q.push(p -> right);
            }
        }
        int mini = INT_MAX;
        for(int i = 0;i < nodes.size();i++){
            for(int j = i+1;j < nodes.size();j++){
                mini = min(mini,abs(nodes[i] - nodes[j]));
            }
        }
        return mini;
    }
};