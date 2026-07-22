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
    int findBottomLeftValue(TreeNode* root) {
        if(!root) return 0;
    
    map<int, int> mpp;
    queue<pair<TreeNode*, int>> q;
    
    q.push({root, 0});
    while(!q.empty()){
        auto p = q.front();
        q.pop();
        TreeNode* node = p.first;
        int level = p.second;
        mpp[level] = node -> val;
        if(node -> right) q.push({node -> right, level + 1});
        if(node -> left) q.push({node -> left, level + 1});
    }
    return mpp[mpp.size() - 1];
    }
};