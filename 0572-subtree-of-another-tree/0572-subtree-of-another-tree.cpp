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
 bool helper(TreeNode* cur, TreeNode* subCur){
        if(cur == NULL && subCur == NULL) return true;

        if(cur && subCur && cur -> val == subCur -> val){
            return helper(cur -> left,subCur -> left) && helper(cur -> right, subCur -> right);
        }
        else return false;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root) return false;
        if(!subRoot) return true;

        if(helper(root, subRoot)){
            return true;
        }

        return isSubtree(root -> left, subRoot) || isSubtree(root -> right, subRoot);
    }
};