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
    void helper(TreeNode* root,int flag,int& sum){
        if(root == NULL) return;
        if(root -> left == NULL && root -> right == NULL && flag == 1){
            sum += root -> val;
        }
        helper(root -> left,1,sum);
        helper(root -> right,0,sum);
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int flag;
        int sum = 0;
        helper(root,flag,sum);

        return sum;
    }
};