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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        if(!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            long long sum = 0;
            for(int i = 0;i < size;i++){
                auto p = q.front();
                sum += q.front() -> val;
                q.pop();
                if(p -> left){
                    q.push(p -> left);
                }
                if(p -> right){
                    q.push(p -> right);
                }
            }
            ans.push_back((double)sum/size);
        }
        return ans;
    }
};