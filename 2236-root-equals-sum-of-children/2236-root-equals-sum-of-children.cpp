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
    bool checkTree(TreeNode* root) {
        int sum = 0;
        if(root -> left){
            TreeNode* node = root -> left;
            sum += node -> val;
        }
        if(root -> right){
            TreeNode* node = root -> right;
            sum += node -> val;
        }

        if(sum == root -> val) return true;
        return false;
    }
};