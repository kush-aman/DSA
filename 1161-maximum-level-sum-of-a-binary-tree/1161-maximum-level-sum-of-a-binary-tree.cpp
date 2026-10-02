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
    int maxLevelSum(TreeNode* root) {
        int sum = INT_MIN;
        queue<TreeNode*> q;
        q.push(root);
        int level = 1;
        int ans;
        while(!q.empty()){
            int size = q.size();
            int curSum = 0;
            for(int i = 0;i < size;i++){
                auto p = q.front();
                q.pop();
                curSum += p -> val;
                if(p -> left) q.push(p -> left);
                if(p -> right) q.push(p -> right);
            }
            if(curSum > sum){
                sum = curSum;
                ans = level;
            }
            level++;
        }
        return ans;
    }
};