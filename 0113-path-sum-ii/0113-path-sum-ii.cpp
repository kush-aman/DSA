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
    void helper(TreeNode* root, int targetSum, vector<int> temp, vector<vector<int>>& ans){
        if(!root) return;
        targetSum -= root -> val;
        temp.push_back(root -> val);
        if(targetSum == 0 && !root -> left && !root -> right){
            return ans.push_back(temp);
        }
        helper(root -> left, targetSum, temp, ans);
        helper(root -> right, targetSum, temp, ans);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> temp;
        helper(root,targetSum,temp,ans);

        return ans;
    }
};