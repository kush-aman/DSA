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
    void firstTree(TreeNode* root1,vector<TreeNode*>& t1){
        if(!root1) return;

        if(root1 -> left == NULL && root1 -> right == NULL){
            t1.push_back(root1);
        }
        firstTree(root1 -> left,t1);
        firstTree(root1 -> right,t1);
    }
    void secondTree(TreeNode* root2,vector<TreeNode*>& t2){
        if(!root2) return;

        if(root2 -> left == NULL && root2 -> right == NULL){
            t2.push_back(root2);
        }
        secondTree(root2 -> left,t2);
        secondTree(root2 -> right,t2);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<TreeNode*> t1,t2;
        firstTree(root1,t1);
        secondTree(root2,t2);
        if(t1.size() != t2.size()) return false;
        int i = 0;
        while(i < t1.size() && i < t2.size()){
            if(t1[i] -> val != t2[i] -> val) return false;
            i++;
        }

        return true;
    }
};