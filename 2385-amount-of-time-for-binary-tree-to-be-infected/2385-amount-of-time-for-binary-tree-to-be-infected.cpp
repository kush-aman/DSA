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
    TreeNode* parent_track(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent, int start){    
    queue<TreeNode*> q;
    q.push(root);
    TreeNode* res;
    while(!q.empty()){
        TreeNode* current = q.front();
        q.pop();
        if(current -> val == start) res = current;
        if(current -> left){
            q.push(current -> left);
            parent[current -> left] = current;
        }
        if(current -> right){
            q.push(current -> right);
            parent[current -> right] = current;
        }
    }
    return res;
}
    int amountOfTime(TreeNode* root, int start) {
    unordered_map<TreeNode*, TreeNode*> parent;
    queue<TreeNode*> q;
    TreeNode* target = parent_track(root, parent,start);
    unordered_map<TreeNode*, bool> vis;
    q.push(target);
    vis[target] = 1;
    int time = 0;
    while(!q.empty()){
        int size = q.size();
        int flag = 0;
        for(int i = 0;i < size;i++){
            TreeNode* node = q.front();
            q.pop();
            if(!vis[node -> left] && node -> left){
                flag = 1;
                q.push(node -> left);
                vis[node -> left] = true;
            }
            if(!vis[node -> right] && node -> right){
                flag = 1;
                q.push(node -> right);
                vis[node -> right] = true;
            }
            if(parent[node] && !vis[parent[node]]){
                flag = 1;
                q.push(parent[node]);
                vis[parent[node]] = true;
            }
        }
        if(flag) time++;
    }
    return time;
    }
};