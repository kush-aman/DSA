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
    bool isCousins(TreeNode* root, int x, int y) {
        map<int,pair<int,int>> mpp;
        mpp[root -> val] = {-1,0};
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            int size = q.size();
            for(int i = 0;i < size;i++){
                auto p = q.front().first;
                auto d = q.front().second;
                q.pop();
                if(p -> left){
                    q.push({p -> left,d+1});
                    mpp[p -> left -> val] = {p -> val,d+1};
                }
                if(p -> right){
                    q.push({p -> right,d+1});
                    mpp[p -> right -> val] = {p -> val,d+1};
                }
            }
            if(mpp.find(x) != mpp.end() && mpp.find(y) != mpp.end()){
                    if(mpp[x].first != mpp[y].first && mpp[x].second == mpp[y].second) return true;
                }
        }
        return false;
    }
};