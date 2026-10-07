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
private:
    void helper(TreeNode* root, int total, int& ans){
        if(root == NULL) return;
        total = total * 10 + root -> val;
        if(root -> left == NULL && root -> right == NULL){
            ans += total;
        } 
        helper(root -> left,total,ans);
        helper(root -> right,total,ans);
        
    }
public:
    int sumNumbers(TreeNode* root) {
        int total = 0;
        int ans = 0;
        helper(root,total,ans);
        return ans;
    }
};