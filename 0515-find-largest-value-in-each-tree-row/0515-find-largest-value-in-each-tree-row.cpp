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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            int largest = INT_MIN;
            for(int i = 0;i < size;i++){
                auto p = q.front();
                q.pop();
                if(p -> val > largest) largest = p -> val;
                if(p -> left) q.push(p -> left);
                if(p -> right) q.push(p -> right);
            }
            ans.push_back(largest);
        }
        return ans;
    }
};